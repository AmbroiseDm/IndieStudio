//
// Created by lerest_m on 12/06/17.
//

#ifndef INDIE_STUDIO_GUI_HPP
#define INDIE_STUDIO_GUI_HPP

#include <memory>
#include "Bomberman.hpp"

#define GUIMENU "Menu"
#define GUIOPTION "Option"
#define GUIGAME "GameGUI"

class Bomberman;

class IGUI
{
    protected:
        std::shared_ptr<Bomberman> game;
        std::string background;
        std::string id;
        bool in_game;
        bool cursor;
        bool have_back;
        IGUI(std::shared_ptr<Bomberman> &, const std::string &, const std::string &, bool, bool);
        IGUI(std::shared_ptr<Bomberman> &, const std::string &, bool, bool);

    public:
        const std::string &getID() const;
        const std::string &getBackground() const;
        bool haveCursor() const;
        bool isInGame() const;
        bool haveBackground() const;
        IGUI(const IGUI &) = delete;
        IGUI &operator=(const IGUI &) = delete;
        virtual void setGUI(irr::gui::IGUIEnvironment *) = 0;
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
        void setGUI(irr::gui::IGUIEnvironment *);
        void update();
};

class Option : public IGUI
{
    private:
        irr::gui::IGUIButton *back;

    public:
        Option(std::shared_ptr<Bomberman> &);
        Option(const Option &) = delete;
        Option &operator=(const Option &) = delete;
        ~Option() = default;
        void setGUI(irr::gui::IGUIEnvironment *);
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
        void setGUI(irr::gui::IGUIEnvironment *);
        void update();
};

#endif //INDIE_STUDIO_GUI_HPP
