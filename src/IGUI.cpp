//
// Created by lerest_m on 12/06/17.
//

#include "GUI.hpp"

IGUI::IGUI(std::shared_ptr<Bomberman> &game, const std::string &id, const std::string &background, bool in_game, bool cursor) :
        game(game), background(background), id(id), in_game(in_game), cursor(cursor), have_back(true) {}

IGUI::IGUI(std::shared_ptr<Bomberman> &game, const std::string &id, bool in_game, bool cursor) :
        game(game), background(""), id(id), in_game(in_game), cursor(cursor), have_back(false) {}

const std::string &IGUI::getID() const
{
    return (id);
}

const std::string &IGUI::getBackground() const
{
    return (background);
}

bool IGUI::haveCursor() const
{
    return (cursor);
}

bool IGUI::isInGame() const
{
    return (in_game);
}

bool IGUI::haveBackground() const
{
    return (have_back);
}

void IGUI::setAudio(irr::gui::IGUIEnvironment *guienv)
{
  irr::core::rect<irr::s32> demutePos = {1855, 0, 1900, 48};
  demute = guienv->addButton(demutePos, NULL, -1, NULL);
  demute->setImage(game->getRenderer()->getTexture(BTNDEMUTE));
  
  irr::core::rect<irr::s32> mutePos = {1765, 0, 1810, 48};
  mute = guienv->addButton(mutePos, NULL, -1, NULL);
  mute->setImage(game->getRenderer()->getTexture(BTNMUTE));
}

void IGUI::setPanel(irr::gui::IGUIEnvironment *guienv)
{
  irr::core::rect<irr::s32> namePos;
  std::wstring message;
  int y1 = 100;
  int y2 = 120;
  int i = 0;
  for (int i = 0; i != game->getPlayers().size(); ++i)
    {
      message = L"Player ";
      message += std::to_wstring(i + 1);
      message += L" : ";
      message += game->getPlayers()[i].getName();
      namePos = {50, y1, 200, y2};
      p = guienv->addButton(namePos, 0, -1, message.c_str());
      p->setImage(game->getRenderer()->getTexture(BTNGREY));
      message = L"Score : ";
      message += std::to_wstring(game->getPlayers()[i].getScore());
      namePos = {230, y1, 380, y2};
      s = guienv->addButton(namePos, 0, -1, message.c_str());
      s->setImage(game->getRenderer()->getTexture(BTNGREY));
      y1 += 30;
      y2 += 30;
    }
}
