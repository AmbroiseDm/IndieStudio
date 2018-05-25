//
// Bomb.hpp for  in /home/soraaz/rendu/cpp_indie_studio
// 
// Made by Soraaz
// Login   <robin1.partouche@epitech.eu>
// 
// Started on  Fri May 26 13:20:00 2017 Soraaz
// Last update Sat Jun 17 06:46:55 2017 ambroisedamier
//

# ifndef BOMB_CPP
# define BOMB_CPP

#include "Protocol.hpp"
#include <chrono>

class Bomb
{
private:
  Position _pos;
  unsigned int   _range;
  e_Bomb	_type;
  std::chrono::time_point<std::chrono::system_clock>	_timer;
  
public:
  Bomb(Position pos, unsigned int range, e_Bomb type, std::chrono::time_point<std::chrono::system_clock> timer);
  ~Bomb();

  void setX(const int x);
  void setY(const int y);
  void setPos(Position pos);
  int  getX() const;
  int  getY() const;
  Position  getPos() const;
  unsigned int	getRange() const;
  e_Bomb	getType() const;
  std::chrono::time_point<std::chrono::system_clock> getTimer() const;
};

# endif
