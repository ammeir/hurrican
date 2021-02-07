cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(hurrican)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Hurrican")
set(VITA_TITLEID  "MEIR00003")
set(VITA_VERSION  "00.90")


if (BUILD_TYPE MATCHES Release)

   # Build release version with -O3 flag. It will optimize the code and give a good performance boost. 
   message("Build mode is RELEASE")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -mcpu=cortex-a9 -mfpu=neon-fp16 -fno-optimize-sibling-calls -ftree-vectorize -fsingle-precision-constant -mtune=cortex-a9 -mfloat-abi=hard -ffast-math -Wno-write-strings")
   
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -mcpu=cortex-a9 -mfpu=neon-fp16 -fno-optimize-sibling-calls -ftree-vectorize -fsingle-precision-constant -mtune=cortex-a9 -mfloat-abi=hard -ffast-math -fpermissive -Wno-write-strings")



   #set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
   #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
else ()
   # Build with -g flag to enable better debugging information.
   message("Build mode is DEBUG")
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -std=gnu11")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")
   add_compile_options(-g)
   add_definitions(-DPSV_DEBUG_CODE)
   add_definitions(-DDEBUG)
   add_definitions(-D_DEBUG)
endif (BUILD_TYPE MATCHES Release)


add_definitions(-DPSVITA)
add_definitions(-DPLATFORM_SDL)
add_definitions(-DUSE_GL2)
add_definitions(-DUSE_GLES2)
add_definitions(-DUSE_EGL_RAW)
add_definitions(-DUSE_MODPLUG)
add_definitions(-DUSE_NO_EXCEPTIONS)
add_definitions(-DUSE_FAST_RNG)
add_definitions(-DUSE_FAST_TRIG)
#add_definitions(-DUSE_PVRTC)



# Add any additional include paths here
include_directories(
  src/
  src/cml/
  src/SDLPort/
  src/vita_port/
  src/unrarlib040/unrarlib/
  $ENV{VITASDK}/arm-vita-eabi/include/SDL/
  $ENV{VITASDK}/arm-vita-eabi/include/libmodplug/
)

add_executable(${PROJECT_NAME}
  src/vita_port/psvita.c
  src/SDLPort/SDL_fmod.cpp
  src/SDLPort/SDL_port.cpp
  src/SDLPort/cshader.cpp
  src/SDLPort/texture.cpp
  src/DX8Enum.cpp
  src/DX8Font.cpp
  src/DX8Graphics.cpp
  src/DX8Input.cpp
  src/DX8Joystick.cpp
  src/DX8Sound.cpp
  src/DX8Sprite.cpp
  src/DX8Texture.cpp
  src/Boss_BigFish.cpp
  src/Boss_Bratklops.cpp
  src/Boss_Drache.cpp
  src/Boss_EisFaust.cpp
  src/Boss_EvilHurri.cpp
  src/Boss_FahrstuhlBoss.cpp
  src/Boss_FlugBoss.cpp
  src/Boss_Golem.cpp
  src/Boss_MetalHead.cpp
  src/Boss_PharaoKopf.cpp
  src/Boss_RiesenPiranha.cpp
  src/Boss_RiesenQualle.cpp
  src/Boss_RiesenRaupe.cpp
  src/Boss_RiesenSpinne.cpp
  src/Boss_RiesenWespe.cpp
  src/Boss_Rollmops.cpp
  src/Boss_SchmidtOrgie.cpp
  src/Boss_Schneekoenig.cpp
  src/Boss_Skeletor.cpp
  src/Boss_Skull.cpp
  src/Boss_Spinnenmaschine.cpp
  src/Boss_Stahlfaust.cpp
  src/Boss_TheWall.cpp
  src/Boss_Ufo.cpp
  src/Boss_WuxeSpinnen.cpp
  src/CCracktro.cpp
  src/CCutScene.cpp
  src/CDragonHack.cpp
  src/Console.cpp
  src/Gameplay.cpp
  src/Gegner_Auge.cpp
  src/Gegner_BallerDrone.cpp
  src/Gegner_BigRocket.cpp
  src/Gegner_BlueBoulder.cpp
  src/Gegner_BrockelRock.cpp
  src/Gegner_Climber.cpp
  src/Gegner_DeckenKrabbe.cpp
  src/Gegner_Deckenturm.cpp
  src/Gegner_Diamant.cpp
  src/Gegner_Drone.cpp
  src/Gegner_EierMann.cpp
  src/Gegner_EisStachel.cpp
  src/Gegner_Eiszapfen.cpp
  src/Gegner_Extras.cpp
  src/Gegner_FallBombe.cpp
  src/Gegner_FallingRock.cpp
  src/Gegner_FetteRakete.cpp
  src/Gegner_FetteSpinne.cpp
  src/Gegner_FieseDrone.cpp
  src/Gegner_FieserFireWalker.cpp
  src/Gegner_FieserWalker.cpp
  src/Gegner_FireSpider.cpp
  src/Gegner_Fledermaus.cpp
  src/Gegner_FlugKanone.cpp
  src/Gegner_Flugsack.cpp
  src/Gegner_Geschuetz.cpp
  src/Gegner_GunTower.cpp
  src/Gegner_Helper.cpp
  src/Gegner_Jaeger.cpp
  src/Gegner_Kettenglied.cpp
  src/Gegner_KrabblerLinks.cpp
  src/Gegner_KrabblerOben.cpp
  src/Gegner_KrabblerRechts.cpp
  src/Gegner_KugelGross.cpp
  src/Gegner_KugelKlein.cpp
  src/Gegner_KugelMedium.cpp
  src/Gegner_KugelRiesig.cpp
  src/Gegner_LaFass.cpp
  src/Gegner_LavaBall.cpp
  src/Gegner_LavaBallSpawner.cpp
  src/Gegner_LavaKrabbe.cpp
  src/Gegner_Lavamann.cpp
  src/Gegner_Made.cpp
  src/Gegner_Minidragon.cpp
  src/Gegner_MiniRocket.cpp
  src/Gegner_MittelSpinne.cpp
  src/Gegner_Mutant.cpp
  src/Gegner_Nest.cpp
  src/Gegner_NeuFisch.cpp
  src/Gegner_OneUp.cpp
  src/Gegner_PFlanze.cpp
  src/Gegner_Piranha.cpp
  src/Gegner_PokeNuke.cpp
  src/Gegner_PowerBlock.cpp
  src/Gegner_Punisher.cpp
  src/Gegner_Qualle.cpp
  src/Gegner_Raketenwerfer.cpp
  src/Gegner_ReitFlugsack.cpp
  src/Gegner_RoboMan1.cpp
  src/Gegner_RoboRaupe.cpp
  src/Gegner_Rotzpott.cpp
  src/Gegner_Schabe.cpp
  src/Gegner_SchienenViech.cpp
  src/Gegner_SchleimAlien.cpp
  src/Gegner_SchleimBoller.cpp
  src/Gegner_SchleimMaul.cpp
  src/Gegner_Schneekoppe.cpp
  src/Gegner_Schwabbel.cpp
  src/Gegner_SideRocket.cpp
  src/Gegner_SkiWalker.cpp
  src/Gegner_SmallWespe.cpp
  src/Gegner_SnowBomb.cpp
  src/Gegner_SpiderBomb.cpp
  src/Gegner_Spitter.cpp
  src/Gegner_Spitterbombe.cpp
  src/Gegner_Stachelbeere.cpp
  src/Gegner_Stahlmuecke.cpp
  src/Gegner_Stalagtit.cpp
  src/Gegner_StarBig.cpp
  src/Gegner_StarSmall.cpp
  src/Gegner_StelzSack.cpp
  src/Gegner_SwimWalker.cpp
  src/Gegner_Walker.cpp
  src/Gegner_WandKannone.cpp
  src/Gegner_WandKrabbe.cpp
  src/Gegner_WasserMine.cpp
  src/Gegner_Zitrone.cpp
  src/GegnerClass.cpp
  src/GetKeyName.cpp
  src/GUISystem.cpp
  src/HUD.cpp
  src/Intro.cpp
  src/lightmap.cpp
  src/Logdatei.cpp
  src/Mathematics.cpp
  src/Main.cpp
  src/Menu.cpp
  src/Outtro.cpp
  src/Partikelsystem.cpp
  src/Player.cpp
  src/Projectiles.cpp
  src/stdafx.cpp
  src/Texts.cpp
  src/Tileengine.cpp  
  src/Timer.cpp
  src/tracealloc.cpp
  src/Trigger_Bruecke.cpp
  src/Trigger_Column.cpp
  src/Trigger_Column2.cpp
  src/Trigger_EndLevel.cpp
  src/Trigger_FadeMusic.cpp
  src/Trigger_FahrStuhl.cpp
  src/Trigger_Fass.cpp
  src/Trigger_Feuerspucker.cpp
  src/Trigger_Floating.cpp
  src/Trigger_Floating2.cpp
  src/Trigger_Floating3.cpp
  src/Trigger_Glubschi.cpp
  src/Trigger_Glubschi2.cpp
  src/Trigger_LaFassSpawner.cpp
  src/Trigger_Lift.cpp
  src/Trigger_LightFlare.cpp
  src/Trigger_LuefterGross.cpp
  src/Trigger_LuefterKlein.cpp
  src/Trigger_LuefterKlein2.cpp
  src/Trigger_Mushroom.cpp
  src/Trigger_PartikelSpawner.cpp
  src/Trigger_Plattform.cpp
  src/Trigger_Presse.cpp
  src/Trigger_Presswurst.cpp
  src/Trigger_SchleuseH.cpp
  src/Trigger_SchleuseV.cpp
  src/Trigger_Secret.cpp
  src/Trigger_ShootButton.cpp
  src/Trigger_ShootPlattform.cpp
  src/Trigger_Shrine.cpp
  src/Trigger_SoundTrigger.cpp
  src/Trigger_Spikelift.cpp
  src/Trigger_Stampfstein.cpp
  src/Trigger_SurfBrett.cpp
  src/Trigger_Switch.cpp
  src/Trigger_Tube.cpp
  src/Trigger_TutorialText.cpp
  src/Trigger_Warning.cpp
  src/unrarlib040/unrarlib/unrarlib.c
)

target_link_libraries(${PROJECT_NAME}
  vitaGL
  vitashark
  vita2d
  SDL_mixer
  SDL_image
  SDL
  SceShaccCg_stub
  SceDisplay_stub
  SceCtrl_stub
  SceAudio_stub
  SceSysmodule_stub
  SceGxm_stub
  SceCommonDialog_stub
  SceHid_stub
  SceAppMgr_stub
  ScePower_stub
  vorbisfile
  vorbis
  mathneon
  modplug
  mikmod
  ogg
  jpeg
  png
  z
)

vita_create_self(eboot.bin ${PROJECT_NAME} UNSAFE)

vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} eboot.bin
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml 
)