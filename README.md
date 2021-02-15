
### Port of Hurrican for Playstation Vita

Hurrican is a freeware jump and shoot game created by Poke53280 that is based on the Turrican game series. Blast your way through nine action-packed levels filled with different enemies and powerups.

### Running the game
-Unzip `hurrican.zip` and copy the contents to `ux0:data/` so that you have a folder `ux0:data/hurrican/data`  
-Copy runtime shader compiler `libshacccg.suprx` to `ur0:data/`. Follow this [guide](https://samilops2.gitbook.io/vita-troubleshooting-guide/shader-compiler/extract-libshacccg.suprx) on how to extract it from your Vita  
-Install `hurrican.vpk`

### Controls
Left analog stick = move/aim  
Dpad = move/aim  
Square = shoot  
Cross = jump  
Triangle = lightning beam  
Circle = powerline  
R = grenade  
L = smart bomb  
Select = select weapon  
Start = main menu

### Compiling the game 
-Install [VitaSDK](http://vitasdk.org) toolchain  
-If you are on Windows, install [MSYS2](http://msys2.org) command shell  
-Clone hurrican repo into a folder somewhere  
-Build and install dependencies vitaGL, vitaShaRK and mathneon  
-Compile:  
  cmake "your hurrican repo folder" -DBUILD_TYPE=Release  
  make

For a debug version replace Release with Debug.

### Known issues
-Frame drops in some parts of the game (e.g near waterfalls and with certain boss fights)
-Gaps between background tiles are sometimes visible, especially in level 7


### Credits
Thanks to Poke53280 team for making this game, releasing the source, and making it freeware.  
Thanks to developer Pickle136 for adding SDL/OpenGL-ES support.  
Thanks to developer DKS for improving and optimizing the code.  
Thanks to Rinnegatamante for making the vitaGL library.
