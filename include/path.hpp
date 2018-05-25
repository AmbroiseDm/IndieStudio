//
// path.hpp for path in /home/amity/epitech/tek2/c++/cpp_indie_studio
// 
// Made by Alexandre
// Login   <alexandre.kaczor@epitech.eu>
// 
// Started on  Sun Jun 18 03:47:36 2017 Alexandre
// Last update Sun Jun 18 22:35:20 2017 AdelyanTV-VM
//

#ifndef PATH_HPP_
# define PATH_HPP_

# ifdef WIN32

#  define PLAYER "asset\\model\\bombernew.x"
#  define PLAYERTEXTURE "asset\\texture\\body.png"

#  define PLAYER_ILLIDAN "asset\\hots\\model\\Illidan.b3d"
#  define PLAYER_ARTHAS "asset\\hots\\model\\Arthas.b3d"
#  define PLAYER_SYLVANAS "asset\\hots\\model\\Sylvanas.b3d"
#  define PLAYER_RAGNAROS "asset\\hots\\model\\Ragnaros.b3d"

#  define PLAYER_ARTANIS "asset\\hots\\model\\Artanis.b3d"
#  define PLAYER_KERRIGAN "asset\\hots\\model\\Kerrigan.b3d"
#  define PLAYER_REYNOR "asset\\hots\\model\\Raynor.b3d"
#  define PLAYER_NOVA "asset\\hots\\model\\Nova.b3d"


//BOMB
#  define BOMBMODEL "asset\\model\\bomb.x"
#  define EXPLODEMODEL "asset\\explode\\Explode.b3d"

//POWERUP
#  define POWERUPMODEL "asset\\model\\powerup.x"
#  define POWERUPBOMB "asset\\texture\\powerupbomb.png"
#  define POWERUPFIRE "asset\\texture\\powerupfire.png"
#  define POWERUPSKATE "asset\\texture\\powerupspeed.png"

// BACKGROUND
#  define BACKGROUND "asset\\img\\background.jpg"
#  define MENUBACKGROUND "asset\\img\\menu_background.jpg"
#  define SPLASHBACKGROUND "asset\\img\\splashscreen.jpg"

// TEXTURE
#  define WATER "asset\\water.jpg"
#  define WOOD "asset\\texture\\box.jpg"
#  define WALL "asset\\texture\\wall.png"
#  define FLOOR "asset\\texture\\grass.jpg"
#  define GRASS "asset\\texture\\grass.png"
#  define FIRE  "asset\\texture\\fire.bmp"
#  define STONE "asset\\texture\\stone.jpg"

#  define ILLIDAN "asset\\hots\\texture\\Illidan\\storm_illidan_ultimate_crimson_diff.jpg"
#  define ARTHAS "asset\\hots\\texture\\Arthas\\storm_hero_arthas_diff.jpg"
#  define SYLVANAS "asset\\hots\\texture\\Sylvanas\\storm_hero_sylvanas_highelf_diff.jpg"
#  define RAGNAROS "asset\\hots\\texture\\Ragnaros\\storm_hero_ragnaros_diff.jpg"

#  define ARTANIS "asset\\hots\\texture\\Artanis\\storm_hero_artanis_diff.jpg"
#  define REYNOR "asset\\hots\\texture\\Raynor\\storm_hero_raynor_diff.jpg"
#  define KERRIGAN "asset\\hots\\texture\\Kerrigan\\storm_hero_kerrigan_ghost.jpg"
#  define NOVA "asset\\hots\\texture\\Nova\\storm_hero_nova_diff.jpg"

#  define PLAYERBLACKTEXTURE "asset\\texture\\bodyblack.png"
#  define PLAYERBLUETEXTURE "asset\\texture\\bodyblue.png"
#  define PLAYERREDTEXTURE "asset\\texture\\bodyred.png"
#  define PLAYERGREENTEXTURE "asset\\texture\\patrick.png"

// MONDE 1

#  define WALL_METAL_M1 "asset\\texture\\wall_metal2.png"
#  define BOX_METAL1_M1 "asset\\texture\\box_metal.jpg"
#  define BOX_METAL2_M1 "asset\\texture\\wall_metal5.png"
#  define BOX_METAL3_M1 "asset\\texture\\wall_metal3.png"
#  define BOX_METAL4_M1 "asset\\texture\\wall_metal7.jpg"
#  define FLOOR_METAL_M1 "asset\\texture\\wall_metal6.png"

#  define BAREL_BLUE_M1 "asset\\model\\Barel_blue\\Barel_blue.obj"
#  define BAREL_SPACE_M1 "asset\\model\\SpaceBarrel\\SpaceBarrel.obj"

// MONDE 2

#  define BOX_CARD_M2 "asset\\texture\\box_card_m2.jpg"
#  define BOX_WOOD1_M2 "asset\\texture\\box_wood1_m2.jpg"
#  define BOX_WOOD2_M2 "asset\\texture\\box_wood2_m2.png"
#  define FLOOR_WOOD_M2 "asset\\texture\\FLOOR_WOOD1_M2.png"
#  define WALL_STONE1_M2 "asset\\texture\\wall_stone1_m2.jpg"

// MONDE 3

#  define TONNEAU_M3 "asset\\model\\tonneau.obj"
#  define TONNEAU_TEXT "asset\\texture\\woodbarrel.jpg"
#  define BOX_DARKSIDER_M3 "asset\\texture\\box_darksiders.png"
#  define BOX_WOOD1_M3 "asset\\texture\\box.jpg"

//BUTTON
#  define BACKBUTTON "asset\\btn\\button_back.png"
#  define BACKBUTTONHOVER "asset\\btn\\button_back_hover.png"
#  define PLAYBUTTON "asset\\btn\\button_jouer.png"
#  define PLAYBUTTONHOVER "asset\\btn\\button_jouer_hover.png"
#  define OPTIONBUTTON "asset\\btn\\button_options.png"
#  define OPTIONBUTTONHOVER "asset\\btn\\button_options_hover.png"
#  define QUITBUTTON "asset\\btn\\button_quitter.png"
#  define QUITBUTTONHOVER "asset\\btn\\button_quitter_hover.png"
#  define OKBUTTON "asset\\btn\\button_ok.png"
#  define OKBUTTONHOVER "asset\\btn\\button_ok_hover.png"
#  define BTNGREY "asset\\btn\\hover.png"
#  define BTNMUTE "asset\\btn\\mute.png"
#  define BTNDEMUTE "asset\\btn\\demute.png"
#  define APPUYERTOUCHE "asset\\btn\\touch.png"

//IMG
#  define KEY_OPTION "asset\\img\\key.png"
#  define NAME_OPTION "asset\\img\\name.png"
#  define MAP_OPTION "asset\\img\\map.png"

//FONT
# define  FONTLUCIDA "asset\\font\\fontlucida.png"

// SKYBOX
#  define SKYBOXUP "asset\\skybox\\ulukai\\up.png"
#  define SKYBOXDOWN "asset\\skybox\\ulukai\\down.png"
#  define SKYBOXLEFT "asset\\skybox\\ulukai\\right.png"
#  define SKYBOXRIGHT "asset\\skybox\\ulukai\\left.png"
#  define SKYBOXFRONT "asset\\skybox\\ulukai\\front.png"
#  define SKYBOXBACK "asset\\skybox\\ulukai\\back.png"

// MUSIC
#  define MUSIC_MENU "audio\\Music_menu.ogg"
#  define MUSIC_GAME "audio\\Music_fight.ogg"
#  define MUSIC_SPLASH "audio\\Music_splash.ogg"
#  define EXPLODE_SOUND "audio\\explode.ogg"


# elif __linux__

#  define PLAYER "asset/model/bombernew.x"
#  define PLAYERTEXTURE "asset/exture/body.png"

#  define PLAYER_ILLIDAN "asset/hots/model/Illidan.b3d"
#  define PLAYER_ARTHAS "asset/hots/model/Arthas.b3d"
#  define PLAYER_SYLVANAS "asset/hots/model/Sylvanas.b3d"
#  define PLAYER_RAGNAROS "asset/hots/model/Ragnaros.b3d"

#  define PLAYER_ARTANIS "asset/hots/model/Artanis.b3d"
#  define PLAYER_KERRIGAN "asset/hots/model/Kerrigan.b3d"
#  define PLAYER_REYNOR "asset/hots/model/Raynor.b3d"
#  define PLAYER_NOVA "asset/hots/model/Nova.b3d"


//BOMB
#  define BOMBMODEL "asset/model/bomb.x"
#  define EXPLODEMODEL "asset/explode/Explode.b3d"

//POWERUP
#  define POWERUPMODEL "asset/model/powerup.x"
#  define POWERUPBOMB "asset/texture/powerupbomb.png"
#  define POWERUPFIRE "asset/texture/powerupfire.png"
#  define POWERUPSKATE "asset/texture/powerupspeed.png"

// BACKGROUND
#  define BACKGROUND "asset/img/background.jpg"
#  define MENUBACKGROUND "asset/img/menu_background.jpg"
#  define SPLASHBACKGROUND "asset/img/splashscreen.jpg"

// TEXTURE
#  define WATER "asset/water.jpg"
#  define WOOD "asset/texture/box.jpg"
#  define WALL "asset/texture/wall.png"
#  define FLOOR "asset/texture/grass.jpg"
#  define GRASS "asset/texture/grass.png"
#  define FIRE  "asset/texture/fire.bmp"
#  define STONE "asset/texture/stone.jpg"

#  define ILLIDAN "asset/hots/texture/Illidan/storm_illidan_ultimate_crimson_diff.jpg"
#  define ARTHAS "asset/hots/texture/Arthas/storm_hero_arthas_diff.jpg"
#  define SYLVANAS "asset/hots/texture/Sylvanas/storm_hero_sylvanas_highelf_diff.jpg"
#  define RAGNAROS "asset/hots/texture/Ragnaros/storm_hero_ragnaros_diff.jpg"

#  define ARTANIS "asset/hots/texture/Artanis/storm_hero_artanis_diff.jpg"
#  define REYNOR "asset/hots/texture/Raynor/storm_hero_raynor_diff.jpg"
#  define KERRIGAN "asset/hots/texture/Kerrigan/storm_hero_kerrigan_ghost.jpg"
#  define NOVA "asset/hots/texture/Nova/storm_hero_nova_diff.jpg"

#  define PLAYERBLACKTEXTURE "asset/texture/bodyblack.png"
#  define PLAYERBLUETEXTURE "asset/texture/bodyblue.png"
#  define PLAYERREDTEXTURE "asset/texture/bodyred.png"
#  define PLAYERGREENTEXTURE "asset/texture/patrick.png"

// MONDE 1

#  define WALL_METAL_M1 "asset/texture/wall_metal2.png"
#  define BOX_METAL1_M1 "asset/texture/box_metal.jpg"
#  define BOX_METAL2_M1 "asset/texture/wall_metal5.png"
#  define BOX_METAL3_M1 "asset/texture/wall_metal3.png"
#  define BOX_METAL4_M1 "asset/texture/wall_metal7.jpg"
#  define FLOOR_METAL_M1 "asset/texture/wall_metal6.png"

#  define BAREL_BLUE_M1 "asset/model/Barel_blue/Barel_blue.obj"
#  define BAREL_SPACE_M1 "asset/model/SpaceBarrel/SpaceBarrel.obj"

// MONDE 2

#  define BOX_CARD_M2 "asset/texture/box_card_m2.jpg"
#  define BOX_WOOD1_M2 "asset/texture/box_wood1_m2.jpg"
#  define BOX_WOOD2_M2 "asset/texture/box_wood2_m2.png"
#  define FLOOR_WOOD_M2 "asset/texture/FLOOR_WOOD1_M2.png"
#  define WALL_STONE1_M2 "asset/texture/wall_stone1_m2.jpg"

// MONDE 3

#  define TONNEAU_M3 "asset/model/tonneau.obj"
#  define TONNEAU_TEXT "asset/texture/woodbarrel.jpg"
#  define BOX_DARKSIDER_M3 "asset/texture/box_darksiders.png"
#  define BOX_WOOD1_M3 "asset/texture/box.jpg"

//BUTTON
#  define BACKBUTTON "asset/btn/button_back.png"
#  define BACKBUTTONHOVER "asset/btn/button_back_hover.png"
#  define PLAYBUTTON "asset/btn/button_jouer.png"
#  define PLAYBUTTONHOVER "asset/btn/button_jouer_hover.png"
#  define OPTIONBUTTON "asset/btn/button_options.png"
#  define OPTIONBUTTONHOVER "asset/btn/button_options_hover.png"
#  define QUITBUTTON "asset/btn/button_quitter.png"
#  define QUITBUTTONHOVER "asset/btn/button_quitter_hover.png"
#  define OKBUTTON "asset/btn/button_ok.png"
#  define OKBUTTONHOVER "asset/btn/button_ok_hover.png"
#  define BTNGREY "asset/btn/hover.png"
#  define BTNMUTE "asset/btn/mute.png"
#  define BTNDEMUTE "asset/btn/demute.png"
#  define APPUYERTOUCHE "asset/btn/touch.png"

//IMG
#  define KEY_OPTION "asset/img/key.png"
#  define NAME_OPTION "asset/img/name.png"
#  define MAP_OPTION "asset/img/map.png"

//FONT
# define  FONTLUCIDA "asset/font/fontlucida.png"

// SKYBOX
#  define SKYBOXUP "asset/skybox/ulukai/up.png"
#  define SKYBOXDOWN "asset/skybox/ulukai/down.png"
#  define SKYBOXLEFT "asset/skybox/ulukai/right.png"
#  define SKYBOXRIGHT "asset/skybox/ulukai/left.png"
#  define SKYBOXFRONT "asset/skybox/ulukai/front.png"
#  define SKYBOXBACK "asset/skybox/ulukai/back.png"

// MUSIC
#  define MUSIC_MENU "audio/Music_menu.ogg"
#  define MUSIC_GAME "audio/Music_fight.ogg"
#  define MUSIC_SPLASH "audio/Music_splash.ogg"
#  define EXPLODE_SOUND "audio/explode.ogg"

# endif

#endif // PATH_HPP
