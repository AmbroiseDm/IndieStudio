//
// GUI.hpp for GUI in /home/amity/epitech/tek2/c++/cpp_indie_studio/include
// 
// Made by Alexandre
// Login   <alexandre.kaczor@epitech.eu>
// 
// Started on  Sun Jun 18 00:54:55 2017 Alexandre
// Last update Sun Jun 18 22:39:03 2017 Alexandre
//

#ifndef INDIE_STUDIO_GUI_HPP
#define INDIE_STUDIO_GUI_HPP

#include <memory>
#include "Bomberman.hpp"

#define GUIMENU "Menu"
#define GUIOPTION "Option"
#define GUIGAME "GameGUI"
#define GUISPLASH "SplashScreen"

class Bomberman;

class IGUI
{
protected:
  std::shared_ptr<Bomberman> game;
  std::string background;
  std::string id;
  irr::gui::IGUIButton *p;
  irr::gui::IGUIButton *s;
  irr::gui::IGUIButton *mute;
  irr::gui::IGUIButton *demute;
  bool in_game;
  bool cursor;
  bool have_back;
  irr::EKEY_CODE event;
  IGUI(std::shared_ptr<Bomberman> &, const std::string &, const std::string &, bool, bool);
  IGUI(std::shared_ptr<Bomberman> &, const std::string &, bool, bool);
  
public:
  const std::string &getID() const;
  const std::string &getBackground() const;
  bool haveCursor() const;
  bool isInGame() const;
  bool haveBackground() const;
  void setAudio(irr::gui::IGUIEnvironment *);
  void setPanel(irr::gui::IGUIEnvironment *);
  IGUI(const IGUI &) = delete;
  IGUI &operator=(const IGUI &) = delete;
  virtual void setGUI(irr::gui::IGUIEnvironment *) = 0;
  virtual void setEvent(irr::EKEY_CODE) = 0;
  virtual irr::EKEY_CODE getEvent() const = 0;
  virtual void update() = 0;
  ~IGUI() = default;
};

class Menu : public IGUI
{
private:
  bool playPressed;
  irr::gui::IGUIButton *play;
  bool optionsPressed;
  irr::gui::IGUIButton *options;
  bool quitPressed;
  irr::gui::IGUIButton *quit;
  
public:
  Menu(std::shared_ptr<Bomberman> &);
  Menu(const Menu &) = delete;
  Menu &operator=(const Menu &) = delete;
  ~Menu() = default;
  void setEvent(irr::EKEY_CODE);
  irr::EKEY_CODE getEvent() const;
  void setGUI(irr::gui::IGUIEnvironment *);
  void update();
};

class Option : public IGUI
{
private:
  irr::gui::IGUIButton  *back;
  irr::gui::IGUIButton  *key;
  irr::gui::IGUIButton  *name;
  irr::gui::IGUIButton  *map;
  irr::gui::IGUIButton  *ia;
  irr::gui::IGUIButton  *applyName;
  irr::gui::IGUIButton  *applyKey;
  irr::gui::IGUIButton  *applyMap;
  irr::gui::IGUIButton  *applyIa;
  irr::gui::IGUIButton  *ia1;
  irr::gui::IGUIButton  *ia2;
  irr::gui::IGUIButton  *ia3;
  irr::gui::IGUIButton  *ia4;
  std::vector<irr::gui::IGUIEditBox*> change_key_p1;
  std::vector<irr::gui::IGUIEditBox*> change_key_p2;
  std::vector<irr::gui::IGUIEditBox*> change_key_p3;
  std::vector<irr::gui::IGUIEditBox*> change_key_p4;
  std::vector<irr::gui::IGUIEditBox*> change_name;
  std::vector<irr::gui::IGUIEditBox*> change_map;
  bool applyNamePressed;
  bool applyKeyPressed;
  void addBtn(irr::gui::IGUIEnvironment *);
  void addTitle(irr::gui::IGUIEnvironment *);
  void addInput(irr::gui::IGUIEnvironment *);
  void modifyName();
  void modifyKey();
  void modifyMap();
public:
  irr::gui::IGUIEnvironment * data;
  Option(std::shared_ptr<Bomberman> &);
  Option(const Option &) = delete;
  Option &operator=(const Option &) = delete;
  ~Option() = default;
  void setGUI(irr::gui::IGUIEnvironment *);
  void setEvent(irr::EKEY_CODE);
  irr::EKEY_CODE getEvent() const;
  void update();
  
};

class GameGUI : public IGUI
{
private:
  irr::gui::IGUIButton *back;
   
public:
  GameGUI(std::shared_ptr<Bomberman> &);
  GameGUI(const GameGUI &) = delete;
  GameGUI &operator=(const GameGUI &) = delete;
  ~GameGUI() = default;
  void setEvent(irr::EKEY_CODE);
  irr::EKEY_CODE getEvent() const;
  void setGUI(irr::gui::IGUIEnvironment *);
  void update();
};

class Splash : public IGUI
{
private:
  irr::gui::IGUIButton *touch;

public:
  Splash(std::shared_ptr<Bomberman> &);
  Splash(const Splash &) = delete;
  Splash &operator=(const Splash &) = delete;
  ~Splash() = default;
  void setEvent(irr::EKEY_CODE);
  irr::EKEY_CODE getEvent() const;
  void setGUI(irr::gui::IGUIEnvironment *);
  void update();
};

#endif //INDIE_STUDIO_GUI_HPP
