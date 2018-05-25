//
// path.hpp for path in /home/theogalh/projets/cpp_indie_studio/include
//
// Made by Theogalh
// Login   <thomas.bouillon@epitech.eu>
//
// Started on  Mon May 15 15:31:42 2017 Theogalh
// Last update Fri Jun 16 14:22:07 2017 Dante Grossi
//

#ifndef PATH_HPP_
# define PATH_HPP_

# ifdef WIN32

#  define PLAYER "asset\\model\\bombertest.x"
#  define PLAYERBLACKTEXTURE "asset\\texture\\bodyblack.png"
#  define PLAYERBLUETEXTURE "asset\\texture\\bodyblue.png"
#  define PLAYERREDTEXTURE "asset\\texture\\bodyred.png"
#  define PLAYERGREENTEXTURE "asset\\texture\\patrick.png"

#  define PLAYER_ILLIDAN "asset\\hots\\model\\Illidan.b3d"
#  define PLAYER_ARTHAS "asset\\hots\\model\\Arthas.b3d"
#  define PLAYER_SYLVANAS "asset\\hots\\model\\Sylvanas.b3d"

// BACKGROUND
#  define BACKGROUND "asset\\background.jpg"
#  define MENUBACKGROUND "asset\\menu_background.jpg"

// TEXTURE
#  define WATER "asset\\water.jpg"
#  define WOOD "asset\\texture\\box.jpg"
#  define WALL "asset\\texture\\wall.png"
#  define FLOOR "asset\\texture\\grass.jpg"
#  define ILLIDAN "asset\\hots\\texture\\Illidan\\storm_illidan_norm.jpg"
#  define ARTHAS "asset\\hots\\texture\\Illidan\\storm_hero_arthas_normal.jpg"
#  define SYLVANAS "asset\\hots\\texture\\Illidan\\storm_hero_sylvanas_base_norm.jpg"

// SKYBOX
#  define SKYBOXUP "asset\\skybox\\up.tga"
#  define SKYBOXDOWN "asset\\skybox\\down.tga"
#  define SKYBOXLEFT "asset\\skybox\\left.tga"
#  define SKYBOXRIGHT "asset\\skybox\\right.tga"
#  define SKYBOXFRONT "asset\\skybox\\front.tga"
#  define SKYBOXBACK "asset\\skybox\\back.tga"

// MUSIC
#  define MUSIC_MENU "audio\\Music_menu.ogg"
#  define MUSIC_GAME "audio\\Music_combat.ogg"
#  define MUSIC_SPLASH "audio\\Music_splash.ogg"

# elif __linux__

#  define PLAYER "asset/model/bombernew.x"
#  define PLAYERTEXTURE "asset/texture/body.png"
#  define PLAYERBLACKTEXTURE "asset/texture/bodyblack.png"
#  define PLAYERBLUETEXTURE "asset/texture/bodyblue.png"
#  define PLAYERREDTEXTURE "asset/texture/bodyred.png"
#  define PLAYERGREENTEXTURE "asset/texture/patrick.png"

#  define PLAYER_ILLIDAN "asset/hots/model/Illidan.b3d"
#  define PLAYER_ARTHAS "asset/hots/model/Arthas.b3d"
#  define PLAYER_SYLVANAS "asset/hots/model/Sylvanas.b3d"

// BACKGROUND
#  define BACKGROUND "asset/background.jpg"
#  define MENUBACKGROUND "asset/menu_background.jpg"

// TEXTURE
#  define WATER "asset/water.jpg"
#  define WOOD "asset/texture/box.jpg"
#  define WALL "asset/texture/wall.png"
#  define FLOOR "asset/texture/grass.jpg"
#  define ILLIDAN "asset/hots/texture/Illidan/storm_illidan_norm.jpg"
#  define ARTHAS "asset/hots/texture/Illidan/storm_hero_arthas_normal.jpg"
#  define SYLVANAS "asset/hots/texture/Illidan/storm_hero_sylvanas_base_norm.jpg"

// SKYBOX
#  define SKYBOXUP "asset/skybox/up.tga"
#  define SKYBOXDOWN "asset/skybox/down.tga"
#  define SKYBOXLEFT "asset/skybox/left.tga"
#  define SKYBOXRIGHT "asset/skybox/right.tga"
#  define SKYBOXFRONT "asset/skybox/front.tga"
#  define SKYBOXBACK "asset/skybox/back.tga"

// MUSIC
#  define MUSIC_MENU "audio/Music_menu.ogg"
#  define MUSIC_GAME "audio/Music_fight.ogg"
#  define MUSIC_SPLASH "audio/Music_splash.ogg"
#  define EXPLODE_SOUND "audio/Music_menu_old.ogg"

# endif

#endif // PATH_HPP
