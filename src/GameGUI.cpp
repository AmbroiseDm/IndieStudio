//
// GameGUI.cpp for GameGui in /home/amity/epitech/tek2/c++/cpp_indie_studio/src
// 
// Made by Alexandre
// Login   <alexandre.kaczor@epitech.eu>
// 
// Started on  Fri Jun 16 15:23:24 2017 Alexandre
// Last update Sun Jun 18 20:18:11 2017 Alexandre
//

#include "GUI.hpp"

GameGUI::GameGUI(std::shared_ptr<Bomberman> &game) : IGUI(game, GUIGAME, true, true)
{
  event = irr::KEY_CLEAR;
}

irr::EKEY_CODE GameGUI::getEvent() const
{
  return event;
}

void GameGUI::setEvent(irr::EKEY_CODE d)
{
  event = d;
}

void GameGUI::setGUI(irr::gui::IGUIEnvironment *guienv)
{
  guienv->getSkin()->setFont(guienv->getFont(FONTLUCIDA), irr::gui::EGDF_WINDOW);
  guienv->getSkin()->setFont(guienv->getFont(FONTLUCIDA), irr::gui::EGDF_BUTTON);

  irr::core::rect<irr::s32> backPos = {50, 0, 275, 48};
  back = guienv->addButton(backPos, NULL, -1, NULL);
  back->setImage(game->getRenderer()->getTexture(BACKBUTTON));
  back->setPressedImage(game->getRenderer()->getTexture(BACKBUTTONHOVER));

  this->setAudio(guienv);
  this->setPanel(guienv);
}

void GameGUI::update()
{
  if (back->isPressed())
    game->getRenderer()->setGUI(GUIMENU);
  else if (mute->isPressed())
    game->getSound()->pause_m_game();
  else if (demute->isPressed())
    game->getSound()->start_m_game();
}
