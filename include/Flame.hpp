//
// Flame.hpp for  in /home/ambroisedamier/cpp_indie_studio/include
// 
// Made by ambroisedamier
// Login   <ambroise.damier@epitech.eu>
// 
// Started on  Sun Jun 18 01:51:42 2017 ambroisedamier
// Last update Sun Jun 18 01:54:39 2017 ambroisedamier
//

# ifndef FLAME_CPP
# define FLAME_CPP

#include "Protocol.hpp"
#include <chrono>

class Flame
{
private:
  Position _pos;
  unsigned int   _range;
  e_Bomb	_type;
  std::chrono::time_point<std::chrono::system_clock>	_timer;
  
public:
  Flame(Position pos, unsigned int range, e_Bomb type, std::chrono::time_point<std::chrono::system_clock> timer);
  ~Flame();

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
