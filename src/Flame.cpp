//
// Flame.cpp for flame in /home/ambroisedamier/cpp_indie_studio/src
// 
// Made by ambroisedamier
// Login   <ambroise.damier@epitech.eu>
// 
// Started on  Sat Jun 17 23:08:59 2017 ambroisedamier
// Last update Sat Jun 17 23:11:08 2017 ambroisedamier
//

#include "Flame.hpp"

Flame::Flame(Position pos, unsigned int range, e_Bomb type, std::chrono::time_point<std::chrono::system_clock> timer)
{
  _pos = pos;
  _range = range;
  _type = type;
  _timer = timer;
}

Flame::~Flame()
{
}

void Flame::setX(const int x)
{
  _pos.setX(x);
}

void Flame::setY(const int y)
{
  _pos.setY(y);
}

void Flame::setPos(Position pos)
{
  _pos = pos;
}

int  Flame::getX() const
{
  return (_pos.getX());
}

int  Flame::getY() const
{
  return (_pos.getY());
}

Position  Flame::getPos() const
{
  return (_pos);
}

unsigned int	Flame::getRange() const
{
  return _range;
}

e_Bomb		Flame::getType() const
{
  return _type;
}

std::chrono::time_point<std::chrono::system_clock> Flame::getTimer() const
{
  return _timer;
}
