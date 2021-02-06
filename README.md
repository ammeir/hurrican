
### Port of Hurrican for PSVITA

Hurrican is a freeware run and gun game created by Poke53280 that is based on the Turrican game series. Blast your way through nine action-packed levels filled with different enemies and powerups.

### Running the game:  
-Unzip hurrican.zip and copy the contents to ux0:data/ so that you have a folder ux0:data/hurrican/data  
-Copy runtime shader compiler libshacccg.suprx to ur0:data/. Follow this [guide](https://samilops2.gitbook.io/vita-troubleshooting-guide/shader-compiler/extract-libshacccg.suprx) on how to extract it.

### Compiling the game:  
-Install VitaSDK toolchain: http://vitasdk.org  
-If you are on Windows, install MSYS2 command shell: http://msys2.org  
-Clone hurrican repo into a folder somewhere.  
-Build and install dependencies vitaGL, vitaShaRK and mathneon.  
-Compile and package:  
  cmake "your hurrican repo folder" -DBUILD_TYPE=Release  
  make

For a debug version replace Release with Debug.

### Performance:  
This port needs a lot more optimization. Vita struggles in some parts of the game when there are a lot of shots and particles in the air. But you can get a decent performance if you set the detail level to low/medium. Overclocking to maximum 500 MHz also helps.

### Known issues:  
-Frame drops in some parts of the game  
-White gaps between background tiles are noticable in level 7.


### Credits:  
Thanks to Poke53280 team for making this game, releasing the source, and making it freeware.  
Thanks to developer Pickle136 for adding SDL/OpenGL-ES support.  
Thanks to developer DKS for impoving and optimizing the code.  
Thanks to Rinnegatamante for making the vitaGL library
