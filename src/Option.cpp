//
// Option.cpp for Options in /home/amity/epitech/tek2/c++/cpp_indie_studio/src
// 
// Made by Alexandre
// Login   <alexandre.kaczor@epitech.eu>
// 
// Started on  Fri Jun 16 15:23:30 2017 Alexandre
// Last update Sun Jun 18 22:43:17 2017 Alexandre
//

#include "GUI.hpp"

Option::Option(std::shared_ptr<Bomberman> &game) : IGUI(game, GUIOPTION, BACKGROUND, false, true)
{
  event = irr::KEY_CLEAR;
}

irr::EKEY_CODE Option::getEvent() const
{
  return event;
}

void Option::setEvent(irr::EKEY_CODE d)
{
  event = d;
}

void Option::addBtn(irr::gui::IGUIEnvironment *guienv)
{
  irr::core::rect<irr::s32> applyPos = {550, 400, 740, 440};
  irr::core::rect<irr::s32> backPos = {50, 0, 275, 48};

  back = guienv->addButton(backPos, NULL, -1, NULL);
  back->setImage(game->getRenderer()->getTexture(BACKBUTTON));
  back->setPressedImage(game->getRenderer()->getTexture(BACKBUTTONHOVER));
    
  applyMap = guienv->addButton(applyPos, NULL, -1, NULL);
  applyMap->setImage(game->getRenderer()->getTexture(OKBUTTON));
  applyMap->setPressedImage(game->getRenderer()->getTexture(OKBUTTONHOVER));

  applyPos = {550, 700, 740, 740};
  applyName = guienv->addButton(applyPos, NULL, -1, NULL);
  applyName->setImage(game->getRenderer()->getTexture(OKBUTTON));
  applyName->setPressedImage(game->getRenderer()->getTexture(OKBUTTONHOVER));

  applyPos = {550, 1000, 740, 1040};
  applyKey = guienv->addButton(applyPos, NULL, -1, NULL);
  applyKey->setImage(game->getRenderer()->getTexture(OKBUTTON));
  applyKey->setPressedImage(game->getRenderer()->getTexture(OKBUTTONHOVER));

  applyPos = {550, 400, 740, 440};
  applyIa = guienv->addButton(applyPos, NULL, -1, NULL);
  applyIa->setImage(game->getRenderer()->getTexture(OKBUTTON));
  applyIa->setPressedImage(game->getRenderer()->getTexture(OKBUTTONHOVER));
}

void Option::addTitle(irr::gui::IGUIEnvironment *guienv)
{
  irr::core::rect<irr::s32> mapPos = {100, 200, 740, 240};
  irr::core::rect<irr::s32> namePos = {100, 470, 740, 510};
  irr::core::rect<irr::s32> keyPos = {100, 750, 755, 790};

  map = guienv->addButton(mapPos, NULL, -1, NULL);
  map->setImage(game->getRenderer()->getTexture(MAP_OPTION));

  name = guienv->addButton(namePos, NULL, -1, NULL);
  name->setImage(game->getRenderer()->getTexture(NAME_OPTION));

  key = guienv->addButton(keyPos, NULL, -1, NULL);
  key->setImage(game->getRenderer()->getTexture(KEY_OPTION));

  mapPos = {800, 200, 1460, 240};
  ia = guienv->addButton(mapPos, NULL, -1, NULL);
  ia->setImage(game->getRenderer()->getTexture(KEY_OPTION));
}

void Option::addInput(irr::gui::IGUIEnvironment *guienv)
{
  std::vector<std::wstring> actions;
  std::wstring message;

  change_map.clear();
  change_name.clear();
  change_key_p1.clear();
  change_key_p2.clear();
  change_key_p3.clear();
  change_key_p4.clear();
  change_map.push_back(guienv->addEditBox(L"15", irr::core::rect<irr::s32>(100, 300, 200, 320)));
  change_map.push_back(guienv->addEditBox(L"15", irr::core::rect<irr::s32>(250, 300, 400, 320)));

  int x1 = 800, x2 = 950;
  ia1 = guienv->addButton(irr::core::rect<irr::s32>(x1, 300, x2, 350), NULL, -1, L"1 J");
  x1 += 150;
  x2 += 150;
  ia2 = guienv->addButton(irr::core::rect<irr::s32>(x1, 300, x2, 350), NULL, -1, L"2 J");
  x1 += 150;
  x2 += 150;
  ia3 = guienv->addButton(irr::core::rect<irr::s32>(x1, 300, x2, 350), NULL, -1, L"3 J");
  x1 += 150;
  x2 += 150;
  ia4 = guienv->addButton(irr::core::rect<irr::s32>(x1, 300, x2, 350), NULL, -1, L"4 J");
    
  x1 = 100;
  x2 = 200;
  for (auto &it : game->getPlayers())
  {
    change_name.push_back(guienv->addEditBox(it.getName().c_str(), irr::core::rect<irr::s32>(x1, 580, x2, 600)));
    x1 += 150;
    x2 += 150;
  }

  actions.push_back(L"Poser");
  actions.push_back(L"Avancer");
  actions.push_back(L"Gauche");
  actions.push_back(L"Reculer");
  actions.push_back(L"Droite");
  int i = 1, y1 = 830, y2 = 850;
  for (auto &action : actions)
    {
      message = i;
      guienv->addStaticText(action.c_str(), irr::core::rect<irr::s32>(100, y1, 200, y2), true, false);
      change_key_p1.push_back(guienv->addEditBox(message.c_str(), irr::core::rect<irr::s32>(250, y1, 350, y2)));
      change_key_p2.push_back(guienv->addEditBox(message.c_str(), irr::core::rect<irr::s32>(400, y1, 500, y2)));
      change_key_p3.push_back(guienv->addEditBox(message.c_str(), irr::core::rect<irr::s32>(550, y1, 650, y2)));
      change_key_p4.push_back(guienv->addEditBox(message.c_str(), irr::core::rect<irr::s32>(700, y1, 800, y2)));
      y1 += 30;
      y2 += 30;
      ++i;
  }
}

void Option::setGUI(irr::gui::IGUIEnvironment *guienv)
{
  guienv->getSkin()->setFont(guienv->getFont(FONTLUCIDA), irr::gui::EGDF_WINDOW);
  guienv->getSkin()->setFont(guienv->getFont(FONTLUCIDA), irr::gui::EGDF_BUTTON);

  this->data = guienv;
  this->addTitle(guienv);
  this->addBtn(guienv);
  this->addInput(guienv);
}

void Option::modifyName()
{
  int i = 0;

  for (const auto &name : change_name)
    {
      if (name->getText())
	{
	  if (i < game->getPlayers().size())
	    game->getPlayers()[i].setName(name->getText());
	}
      ++i;
    }
}

void Option::modifyKey()
{
  
}

void Option::modifyMap()
{
  for (const auto &it : change_map)
    {
      if (!it->getText())
	return ;
    }
  
  unsigned int w = std::stoi(change_map[0]->getText());
  unsigned int h = std::stoi(change_map[1]->getText());
  
  if (w > 50 || w < 1 || h > 50 || h < 1)
    {
      irr::gui::IGUIWindow* window = data->addWindow(irr::core::rect<irr::s32>(700, 500, 1100, 700), false, L"Erreur Taille Map");
      data->addStaticText(L"Erreur Width Height\nVeuillez ne pas depasser 50*50\n", irr::core::rect<irr::s32>(130,80,270,120), true, false, window);
    }
  else
    {
      game->getMap()->setWidth(w);
      game->getMap()->setHeight(h);
    }
}

void Option::update()
{
    if (back->isPressed())
      game->getRenderer()->setGUI(GUIMENU);
    else if (applyName->isPressed())
      modifyName();
    else if (applyKey->isPressed())
      modifyKey();
    else if (applyMap->isPressed())
      modifyMap();
    else if (ia1->isPressed()) {
        game->setIA1(false);
        game->setIA2(true);
        game->setIA3(true);
        game->setIA4(true);
    }
    else if (ia2->isPressed()) {
        game->setIA1(false);
        game->setIA2(false);
        game->setIA3(true);
        game->setIA4(true);
    }
    else if (ia3->isPressed()) {
        game->setIA1(false);
        game->setIA2(false);
        game->setIA3(false);
        game->setIA4(true);
    }
    else if (ia4->isPressed()) {
        game->setIA1(false);
        game->setIA2(false);
        game->setIA3(false);
        game->setIA4(false);
    }
}
