
#ifndef PSVITA_H
#define PSVITA_H

#include "debug.h"
#include <psp2/types.h>

#define APP_DIR							  "ux0:data/hurrican/"
#define USE_STORAGE_PATH APP_DIR		  "data"
#define USE_SAVE_PATH APP_DIR			  "save"
#define PSV_LOG_FILE APP_DIR			  "Game_Log.txt"

#define PSV_CPU_SPEED_333				  0
#define PSV_CPU_SPEED_444				  1
#define PSV_CPU_SPEED_500				  2

// Missing defines in vitaGL
#define GL_ACTIVE_ATTRIBUTES              0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH    0x8B8A 
#define GL_ACTIVE_UNIFORMS                0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH      0x8B87
#define GL_SHADING_LANGUAGE_VERSION       0x8B8C


#ifdef __cplusplus
extern "C" {
#endif 

int     psvInit();

void	EGL_Close(void);
int8_t  EGL_Open(uint16_t width, uint16_t height, uint16_t depth, int vsync);
void    EGL_SwapBuffers(void);

void    glGetActiveAttrib(uint32_t program, int32_t index, int32_t maxAttributeLen, int32_t* lenth, int32_t* size, uint32_t* type, char* attributeName);
void    glGetActiveUniform(uint32_t program, int32_t index, int32_t maxUniformLen, int32_t* lenth, int32_t* size, uint32_t* type, char* uniformName);


#ifdef __cplusplus
}
#endif 


#endif