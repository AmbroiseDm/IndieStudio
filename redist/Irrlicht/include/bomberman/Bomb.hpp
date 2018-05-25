//
// Bomb.hpp for  in /home/soraaz/rendu/cpp_indie_studio
// 
// Made by Soraaz
// Login   <robin1.partouche@epitech.eu>
// 
// Started on  Fri May 26 13:20:00 2017 Soraaz
// Last update Wed Jun  7 20:20:17 2017 Soraaz
//

# ifndef BOMB_CPP
# define BOMB_CPP

#include "Protocol.hpp"

class Bomb
{
private:
  Position _pos;
  int	_timer;
  int   _radius;
public:
  Bomb(const int x, const int y);
  Bomb(Position pos);
  ~Bomb();

  void setX(const int x);
  void setY(const int y);
  void setPos(Position pos);
  int  getX() const;
  int  getY() const;
  Position  getPos() const;
  void	Explose();
};

# endif
