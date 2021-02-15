
#include "psvita.h"
#include "resources.h"
#include <vitaGL.h>
#include <dirent.h>
#include <vita2d.h>
#include <psp2/ctrl.h>

#define DISPLAY_WIDTH  960
#define DISPLAY_HEIGHT 544

#define SCE_ERROR_ERRNO_EEXIST 0x80010011

static int	fileExist(const char* path_to_file);
static int	dirExist(const char* path_to_dir);
static void	waitForUserAck();
int			mkdir(const char* path, mode_t mode);


// Increase heap size. Default 32MB is not enough for this game.
int _newlib_heap_size_user = 180 * 1024 * 1024;

int psvInit()
{
	// Check that all the essential files exist.
	int data_files = dirExist("ux0:data/hurrican/data");
	int shader = fileExist("ur0:data/libshacccg.suprx");
	
	if (!shader){
		
		// Show error message to user.
		vita2d_init();
		vita2d_texture* error_msg = vita2d_load_PNG_buffer(img_error_runtime_files);
	
		if (!error_msg)
			return -1;

		vita2d_start_drawing();
		vita2d_clear_screen();
	    vita2d_draw_texture(error_msg, 307, 213); 
		vita2d_end_drawing();
		vita2d_swap_buffers();

		waitForUserAck();

		vita2d_free_texture(error_msg);
		return -1;
	}

	if (!data_files){
		
		vita2d_init();
		vita2d_texture* error_msg = vita2d_load_PNG_buffer(img_error_data_files);
	
		if (!error_msg)
			return -1;

		vita2d_start_drawing();
		vita2d_clear_screen();
	    vita2d_draw_texture(error_msg, 330, 213); 
		vita2d_end_drawing();
		vita2d_swap_buffers();

		waitForUserAck();

		vita2d_free_texture(error_msg);
		return -1;
	}

	// Create save folder
	if (!dirExist(USE_SAVE_PATH))
		mkdir(USE_SAVE_PATH, 0);

	// This game needs overclocking. Preferably the maximum 500 MHz.
	scePowerSetArmClockFrequency(444);
	scePowerSetBusClockFrequency(222);
	scePowerSetGpuClockFrequency(222);
	scePowerSetGpuXbarClockFrequency(166);

	return 0;
}

int8_t EGL_Open(uint16_t width, uint16_t height, uint16_t depth, int vsync)
{
	/* Initialize openGL and the window surface */
	vglInitExtended(0, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0x800000, SCE_GXM_MULTISAMPLE_4X);
	return 0;
}

void EGL_Close(void)
{
}

void EGL_SwapBuffers(void)
{
	eglSwapBuffers(NULL, NULL);
}

// Missing openGL functions in vitaGL
void glGetActiveAttrib(uint32_t program, int32_t index, int32_t maxAttributeLen, int32_t* lenth, int32_t* size, uint32_t* type, char* attributeName)
{
	// Tested with piglet to find out the return values.
	switch (index){
	case 0:
		strcpy(attributeName, "a_Position");
		break;
	case 1:
		strcpy(attributeName, "a_Color");
		break;
	case 2:
		strcpy(attributeName, "a_Texcoord0");
		break;
	}
}

void glGetActiveUniform(uint32_t program, int32_t index, int32_t maxUniformLen, int32_t* lenth, int32_t* size, uint32_t* type, char* uniformName)
{
	// Tested with piglet to find out the return values.
	switch (index){
	case 0:
		strcpy(uniformName, "u_MVPMatrix");
		break;
	case 1:
		strcpy(uniformName, "uTexture0");
		break;
	}
}

/* Missing functions in Vita SDK */

int chdir(const char *path)
{
	return 0;
}

int mkdir(const char* path, mode_t mode)
{
	int ret = sceIoMkdir(path, 0777); // Don't put mode parameter here. Give always full permissions.
	
	if (ret < 0){
		// Don't return error if dir already exist
		if (!(dirExist(path) && ret == SCE_ERROR_ERRNO_EEXIST)){
			return -1;
		}
	}

	return 0;
}

int rmdir(const char *path)
{
	if (sceIoRemove(path) < 0)
		return -1;

	return 0;
}

//int usleep(long usec)
//{
//    sceKernelDelayThread(usec);
//    return 0;
//}

int usleep(useconds_t usec)
{
    sceKernelDelayThread(usec);
    return 0;
}

uid_t getuid(void)
{
    return 0;
}


/* Privates */

static int dirExist(const char* path_to_dir)
{
	SceUID fd = sceIoDopen(path_to_dir); 

	if(fd < 0){
		return 0;
	}

	sceIoDclose(fd);

	return 1;
}

static int fileExist(const char* path_to_file)
{
	SceUID fd = sceIoOpen(path_to_file, SCE_O_RDONLY, 0777);
	
	if(fd < 0)
		return 0;

	sceIoClose(fd);

	return 1;
}

static void waitForUserAck()
{
	SceCtrlData ctrl;

	while (1) {
		sceCtrlReadBufferPositive(0, &ctrl, 1);
		
		if (ctrl.buttons == SCE_CTRL_CROSS)
			return;
	}
}
