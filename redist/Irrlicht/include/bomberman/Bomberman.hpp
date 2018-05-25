#ifndef BOMBERMAN_HPP_
# define BOMBERMAN_HPP_

# include <vector>
# include <irrlicht.h>
# include <memory>
# include "Debug.hpp"
# include "path.hpp"
# include "Renderer.hpp"
# include "Map.hpp"
# include "Sound.h"
# include "Player.hpp"

class Renderer;
class EventListener;
class IGUI;

class Bomberman
{
	private:
  std::shared_ptr<Renderer> render;
  std::shared_ptr<IGUI> menu;
  std::shared_ptr<IGUI> option;
  std::shared_ptr<IGUI> game;
  std::vector<Player> players;
	std::shared_ptr<Sound> sound;
  unsigned int nb_player;
  Map map;
  
	public:
        /**
         * Init the game
         */
		Bomberman();
		Bomberman(const Bomberman &) = delete;
		Bomberman &operator=(const Bomberman &) = delete;
		~Bomberman() = default;

        /**
         * Init the game
         *
         * @param menu   Menu GUI
         * @param option Option GUI
         * @param game   Game GUI/HUD
         */
        void addGUI(std::shared_ptr<IGUI> &, std::shared_ptr<IGUI> &, std::shared_ptr<IGUI> &);

		/**
		 * Run the game
		 */
		void run();

		std::shared_ptr<Renderer> &getRenderer();

		std::shared_ptr<Sound> &getSound();


  //PlayerPart

  unsigned int		getNbPlayer();

  irr::EKEY_CODE	getPlayerKeyBomb(unsigned int n);
  irr::EKEY_CODE	getPlayerKeyUp(unsigned int n);
  irr::EKEY_CODE	getPlayerKeyLeft(unsigned int n);
  irr::EKEY_CODE	getPlayerKeyDown(unsigned int n);
  irr::EKEY_CODE	getPlayerKeyRight(unsigned int n);

  void			setPlayerPressBomb(unsigned int n, bool b);
  void			setPlayerPressUp(unsigned int n, bool b);
  void			setPlayerPressLeft(unsigned int n, bool b);
  void			setPlayerPressDown(unsigned int n, bool b);
  void			setPlayerPressRight(unsigned int n, bool b);


  void			aff_map(const Map &map);
};

#endif //BOMBERMAN_HPP_
