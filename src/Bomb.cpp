//
// Bomb.cpp for  in /home/soraaz/rendu/cpp_indie_studio
// 
// Made by Soraaz
// Login   <robin1.partouche@epitech.eu>
// 
// Started on  Fri May 26 13:26:35 2017 Soraaz
// Last update Sat Jun 17 06:47:35 2017 ambroisedamier
//

#include "Bomb.hpp"

Bomb::Bomb(Position pos, unsigned int range, e_Bomb type, std::chrono::time_point<std::chrono::system_clock> timer)
{
  _pos = pos;
  _range = range;
  _type = type;
  _timer = timer;
}

Bomb::~Bomb()
{
}

void Bomb::setX(const int x)
{
  _pos.setX(x);
}

void Bomb::setY(const int y)
{
  _pos.setY(y);
}

void Bomb::setPos(Position pos)
{
  _pos = pos;
}

int  Bomb::getX() const
{
  return (_pos.getX());
}

int  Bomb::getY() const
{
  return (_pos.getY());
}

Position  Bomb::getPos() const
{
  return (_pos);
}

unsigned int	Bomb::getRange() const
{
  return _range;
}

e_Bomb		Bomb::getType() const
{
  return _type;
}

std::chrono::time_point<std::chrono::system_clock> Bomb::getTimer() const
{
  return _timer;
}
