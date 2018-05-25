//
// Bomberman.hpp for bomberman in /home/amity/epitech/tek2/c++/cpp_indie_studio/include
// 
// Made by Alexandre
// Login   <alexandre.kaczor@epitech.eu>
// 
// Started on  Sun Jun 18 00:52:00 2017 Alexandre
// Last update Mon Jun 19 00:53:06 2017 Soraaz
//

#ifndef BOMBERMAN_HPP_
# define BOMBERMAN_HPP_

# include <array>
# include <vector>
# include <iomanip>
# include <irrlicht.h>
# include <memory>
# include <thread>
# include <mutex>
# include "Debug.hpp"
# include "path.hpp"
# include "Renderer.hpp"
# include "Map.hpp"
# include "Sound.h"
# include "Player.hpp"
# include "Flame.hpp"

class Renderer;
class EventListener;
class IGUI;

class Bomberman
{
private:
  std::shared_ptr<Renderer> render;
  std::vector<Player> players;
  std::shared_ptr<Sound> sound;

  unsigned int nb_player;
  int	world;
  std::shared_ptr<Map> map;
  std::vector<Flame> _flame;
  std::vector<Position>	_exeption;
  std::vector<Position> _set_explosion;
  std::vector<Position> _power_up;
  int		_end;
  int		_score;
  bool		_ia1;
  bool		_ia2;
  bool		_ia3;
  bool		_ia4;

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
  void addGUI(std::shared_ptr<IGUI> &, std::shared_ptr<IGUI> &, std::shared_ptr<IGUI> &, std::shared_ptr<IGUI> &);
  
  /**
   * Run the game
   */
  void run();
  
  void resetMap();

  std::shared_ptr<Renderer> &getRenderer();
  std::shared_ptr<Map> &getMap();
  std::shared_ptr<Sound> &getSound();
  std::vector<Player> &getPlayers();
  
  void aff_map();
  bool setPowerUp(const Position &);

  void explosion(Position pos, e_Bomb type, unsigned int range, std::chrono::time_point<std::chrono::system_clock>	now);
  void endExplosion(Position pos, unsigned int range);
  unsigned int getNFlame();
  std::chrono::time_point<std::chrono::system_clock> getFlameTimer();
  bool check_exeption(Position pos);
  bool checkSetExplosion(Position pos);
  void getPowerUp(Position pos);
  void	setIA1(bool value);
  void  setIA2(bool value);
  void  setIA3(bool value);
  void  setIA4(bool value);
};

#endif //BOMBERMAN_HPP_
