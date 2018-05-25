//
// Menu.cpp for Menu in /home/amity/epitech/tek2/c++/cpp_indie_studio/src
// 
// Made by Alexandre
// Login   <alexandre.kaczor@epitech.eu>
// 
// Started on  Sat Jun 17 23:48:56 2017 Alexandre
// Last update Sun Jun 18 20:13:52 2017 Alexandre
//

#include "GUI.hpp"

Menu::Menu(std::shared_ptr<Bomberman> &game) : IGUI(game, GUIMENU, MENUBACKGROUND, false, true)
{
  event = irr::KEY_CLEAR;
}

irr::EKEY_CODE Menu::getEvent() const
{
  return event;
}

void Menu::setEvent(irr::EKEY_CODE d)
{
  event = d;
}

void Menu::setGUI(irr::gui::IGUIEnvironment *guienv)
{
  guienv->getSkin()->setFont(guienv->getFont(FONTLUCIDA), irr::gui::EGDF_WINDOW);
  guienv->getSkin()->setFont(guienv->getFont(FONTLUCIDA), irr::gui::EGDF_BUTTON);

  irr::core::rect<irr::s32> playPos = {790, 225, 1125, 285};
  play = guienv->addButton(playPos, NULL, -1, NULL);
  play->setImage(game->getRenderer()->getTexture(PLAYBUTTON));
  play->setPressedImage(game->getRenderer()->getTexture(PLAYBUTTONHOVER));
  playPressed = false;
  
  irr::core::rect<irr::s32> optionPos = {790, 325, 1125, 385};
  options = guienv->addButton(optionPos, NULL, -1, NULL);
  options->setImage(game->getRenderer()->getTexture(OPTIONBUTTON));
  options->setPressedImage(game->getRenderer()->getTexture(OPTIONBUTTONHOVER));
  optionsPressed = false;
  
  irr::core::rect<irr::s32> quitPos = {790, 425, 1125, 485};
  quit = guienv->addButton(quitPos, NULL, -1, NULL);
  quit->setImage(game->getRenderer()->getTexture(QUITBUTTON));
  quit->setPressedImage(game->getRenderer()->getTexture(QUITBUTTON));
  quitPressed = false;
  this->setAudio(guienv);
  this->setPanel(guienv);
}

void Menu::update()
{
  if (play->isPressed())
    playPressed = true;
  else if (!play->isPressed() && playPressed)
  {
	  game->resetMap();
	  game->getRenderer()->setGUI(GUIGAME);
  }
  else if (options->isPressed())
	  optionsPressed = true;
  else if (!options->isPressed() && optionsPressed)
	  game->getRenderer()->setGUI(GUIOPTION);
  else if (quit->isPressed())
	  quitPressed = true;
  else if (!quit->isPressed() && quitPressed)
	  game->getRenderer()->stop();
  else if (mute->isPressed())
    game->getSound()->pause_m_menu();
  else if (demute->isPressed())
    game->getSound()->start_m_menu();
}
