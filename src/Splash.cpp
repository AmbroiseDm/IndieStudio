//
// GameGUI.cpp for GameGui in /home/amity/epitech/tek2/c++/cpp_indie_studio/src
// 
// Made by Alexandre
// Login   <alexandre.kaczor@epitech.eu>
// 
// Started on  Fri Jun 16 15:23:24 2017 Alexandre
// Last update Sun Jun 18 22:29:22 2017 Alexandre
//

#include "GUI.hpp"

Splash::Splash(std::shared_ptr<Bomberman> &game) : IGUI(game, GUISPLASH, SPLASHBACKGROUND, false, false)
{
  event = irr::KEY_CLEAR;
}

irr::EKEY_CODE Splash::getEvent() const
{
  return event;
}

void Splash::setEvent(irr::EKEY_CODE d)
{
  event = d;
}

void Splash::setGUI(irr::gui::IGUIEnvironment *guienv)
{
  irr::core::rect<irr::s32> mapPos = {650, 550, 1360, 620};

  touch = guienv->addButton(mapPos, NULL, -1, NULL);
  touch->setImage(game->getRenderer()->getTexture(APPUYERTOUCHE));
}

void Splash::update() {}
