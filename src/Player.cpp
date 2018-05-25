//
// Player.cpp for Player in /home/theogalh/projet/cpp_indie_studio
// 
// Made by AdelyanTV-VM
// Login   <thomas.bouillon@epitech.eu>
// 
// Started on  Sun Jun 18 19:52:52 2017 AdelyanTV-VM
// Last update Wed Jun 21 16:05:08 2017 ambroise
//

#include "Player.hpp"

Player::Player()
{
  std::wstring message = L"Player";

  _score = 0;
  name = message;
  _ia = false;
  
  _keyBomb = irr::KEY_KEY_A;
  _keyDown = irr::KEY_KEY_S;
  _keyUp = irr::KEY_KEY_Z;
  _keyLeft = irr::KEY_KEY_Q;
  _keyRight = irr::KEY_KEY_D;
  
  _pressBomb = false;
  _pressDown = false;
  _pressUp = false;
  _pressLeft = false;
  _pressRight = false;
  
  _dir = t_dir::DOWN;

  _pos.setX(0);
  _pos.setY(0);

  _range = BASE_RANGE;
  _speed = BASE_SPEED;
  _isalive = true;

  _bomb_type = t_Bomb::NORMAL;
  _n_bomb_max = 1;
  _n_bomb = 0;
  _moove_speed = 7;
}

Player::~Player()
{
}

void		Player::setName(const std::wstring &name)
{
   this->name = name;
}

std::wstring	Player::getName()
{
  return name;
}

void		Player::setScore(int d)
{
  _score = d;
}

int		Player::getScore()
{
  return _score;
}

void	Player::setKeyBoard(irr::EKEY_CODE bomb, irr::EKEY_CODE up, irr::EKEY_CODE left, irr::EKEY_CODE down, irr::EKEY_CODE right)
{
  _keyBomb = bomb;
  _keyDown = down;
  _keyUp = up;
  _keyLeft = left;
  _keyRight = right;
}

void		Player::setKeyBomb(irr::EKEY_CODE key)
{
  _keyBomb = key;
}

void		Player::setKeyUp(irr::EKEY_CODE key)
{
  _keyUp = key;
}

void		Player::setKeyLeft(irr::EKEY_CODE key)
{
  _keyLeft = key;
}

void		Player::setKeyDown(irr::EKEY_CODE key)
{
  _keyDown = key;
}

void		Player::setKeyRight(irr::EKEY_CODE key)
{
  _keyDown = key;
}

irr::EKEY_CODE	Player::getKeyBomb()
{
  return _keyBomb;
}

irr::EKEY_CODE	Player::getKeyUp()
{
  return _keyUp;
}

irr::EKEY_CODE	Player::getKeyLeft()
{
  return _keyLeft;
}

irr::EKEY_CODE	Player::getKeyDown()
{
  return _keyDown;
}

irr::EKEY_CODE	Player::getKeyRight()
{
  return _keyRight;
}

void		Player::setPressBomb(bool b)
{
  if (!_ia)
    _pressBomb = b;
}

void		Player::setPressUp(bool b)
{
  if (!_ia)
    _pressUp = b;
}

void		Player::setPressLeft(bool b)
{
  if (!_ia)
    _pressLeft = b;
}

void		Player::setPressDown(bool b)
{
  if (!_ia)
    _pressDown = b;
}

void		Player::setPressRight(bool b)
{
  if (!_ia)
    _pressRight = b;
}

bool	Player::getPressBomb()
{
  return _pressBomb;
}

bool	Player::getPressUp()
{
  return _pressUp;
}

bool	Player::getPressLeft()
{
  return _pressLeft;
}

bool	Player::getPressDown()
{
  return _pressDown;
}

bool	Player::getPressRight()
{
  return _pressRight;
}


void		Player::setDirection(t_dir dir)
{
  _dir = dir;
}

t_dir	Player::getDirection()
{
  return _dir;
}

void Player::setPosition(Position pos)
{
  _pos = pos;
}

void Player::Left()
{
  if (_pos.getX() - _speed >= 0)
    _pos.setX(_pos.getX() - _speed);
}

void Player::Right()
{
  if (_pos.getX() + _speed >= WIDTH_MAP)
    _pos.setX(_pos.getX() + _speed);
}

void Player::Up()
{
  if (_pos.getY() - _speed >= 0)
    _pos.setY(_pos.getY() - _speed);
}

void Player::Down()
{
  if (_pos.getY() + _speed >= HEIGHT_MAP)
    _pos.setY(_pos.getY() + _speed);
}

void Player::Put_Bomb()
{

}

void Player::Die()
{
  _isalive = false;
}

Position	Player::getPosition()
{
  return _pos;
}


bool		Player::isMoving()
{
  if (_pressUp == true && _pressLeft == false && _pressDown == false && _pressRight == false)
    {
      _dir = t_dir::UP;
      return true;
    }
  if (_pressUp == false && _pressLeft == true && _pressDown == false && _pressRight == false)
    {
      _dir = t_dir::LEFT;
      return true;
    }
  if (_pressUp == false && _pressLeft == false && _pressDown == true && _pressRight == false)
    {
      _dir = t_dir::DOWN;
      return true;
    }
  if (_pressUp == false && _pressLeft == false && _pressDown == false && _pressRight == true)
    {
      _dir = t_dir::RIGHT;
      return true;
    }
    if (_pressUp == true && _pressLeft == true && _pressDown == false && _pressRight == false)
    {
      _dir = t_dir::DIAGUL;
      return true;
    }
  if (_pressUp == true && _pressLeft == false && _pressDown == false && _pressRight == true)
    {
      _dir = t_dir::DIAGUR;
      return true;
    }
  if (_pressUp == false && _pressLeft == true && _pressDown == true && _pressRight == false)
    {
      _dir = t_dir::DIAGDL;
      return true;
    }
  if (_pressUp == false && _pressLeft == false && _pressDown == true && _pressRight == true)
    {
      _dir = t_dir::DIAGDR;
      return true;
    }
  return false;
}

bool		Player::checkWall(const std::shared_ptr<Map> &map)
{
  int		f;

  f = 0;
  if (_ia)
    return true;
  if (_dir == t_dir::UP)
    return checkWallUp(map);
  if (_dir == t_dir::DOWN)
    return checkWallDown(map);
  if (_dir == t_dir::LEFT)
    return checkWallLeft(map);
  if (_dir == t_dir::RIGHT)
    return checkWallRight(map);
  if (_dir == t_dir::DIAGUL)
    {
      if (checkWallUp(map) == true)
	f = 1;
      if (checkWallLeft(map) == true)
	{
	  if (f != 1)
	    _dir = t_dir::LEFT;
	  return true;
	}
      if (f == 1)
	{
	  _dir = t_dir::UP;
	  return true;
	}
    }
  if (_dir == t_dir::DIAGUR)
    {
      if (checkWallUp(map) == true)
	f = 1;
      if (checkWallRight(map) == true)
	{
	  if (f != 1)
	    _dir = t_dir::RIGHT;
	  return true;
	}
      if (f == 1)
	{
	  _dir = t_dir::UP;
	  return true;
	}
    }
  if (_dir == t_dir::DIAGDL)
    {
      if (checkWallDown(map) == true)
	f = 1;
      if (checkWallLeft(map) == true)
	{
	  if (f != 1)
	    _dir = t_dir::LEFT;
	  return true;
	}
      if (f == 1)
	{
	  _dir = t_dir::DOWN;
	  return true;
	}
    }
  if (_dir == t_dir::DIAGDR)
    {
      if (checkWallDown(map) == true)
	f = 1;
      if (checkWallRight(map) == true)
	{
	  if (f != 1)
	    _dir = t_dir::RIGHT;
	  return true;
	}
      if (f == 1)
	{
	  _dir = t_dir::DOWN;
	  return true;
	}
    }
  return false;
}

bool		Player::checkWallUp(const std::shared_ptr<Map> &map)
{
  Position	tmp(_pos.getX(), (_pos.getY() - _speed));

  if (tmp.getY() < 0)
    return false;
  if (map->getCase(tmp) == TileType::BLOCK
      || map->getCase(tmp) == TileType::BREAKABLE
      || map->getCase(tmp) == TileType::BOMB)
    return false;
  tmp.setX(tmp.getX() + HITBOX_PLAYER - 0.01);
  if (map->getCase(tmp) == TileType::BLOCK
      || map->getCase(tmp) == TileType::BREAKABLE
      || map->getCase(tmp) == TileType::BOMB)
    return false;
  return true;
  return false;
}

bool		Player::checkWallLeft(const std::shared_ptr<Map> &map)
{
  Position	tmp((_pos.getX() - _speed), _pos.getY());

  if (tmp.getX() < 0)
    return false;
  if (map->getCase(tmp) == TileType::BLOCK
      || map->getCase(tmp) == TileType::BREAKABLE
      || map->getCase(tmp) == TileType::BOMB)
    return false;
  tmp.setY(tmp.getY() + HITBOX_PLAYER - 0.01);
  if (map->getCase(tmp) == TileType::BLOCK
      || map->getCase(tmp) == TileType::BREAKABLE
      || map->getCase(tmp) == TileType::BOMB)
    return false;
  return true;
}

bool		Player::checkWallDown(const std::shared_ptr<Map> &map)
{
  Position	tmp(_pos.getX(), (_pos.getY() + HITBOX_PLAYER - 0.01 + _speed));

  if ((int)(tmp.getY()) > map->getHeight())
    return (false);
  if (map->getCase(tmp) == TileType::BLOCK
      || map->getCase(tmp) == TileType::BREAKABLE
      || map->getCase(tmp) == TileType::BOMB)
    return false;
  tmp.setX(tmp.getX() + HITBOX_PLAYER - 0.01);
  if (map->getCase(tmp) == TileType::BLOCK
      || map->getCase(tmp) == TileType::BREAKABLE
      || map->getCase(tmp) == TileType::BOMB)
    return false;
  return true;
}

bool		Player::checkWallRight(const std::shared_ptr<Map> &map)
{
  Position	tmp((_pos.getX() + HITBOX_PLAYER - 0.01 +  _speed), _pos.getY());

  if ((tmp.getX()) > map->getWidth())
    return false;
  if (map->getCase(tmp) == TileType::BLOCK
      || map->getCase(tmp) == TileType::BREAKABLE
      || map->getCase(tmp) == TileType::BOMB)
      return false;
  tmp.setY(tmp.getY() + HITBOX_PLAYER - 0.01);
  if (map->getCase(tmp) == TileType::BLOCK
      || map->getCase(tmp) == TileType::BREAKABLE
      || map->getCase(tmp) == TileType::BOMB)
    return false;
  return true;
}

void		Player::movePlayer()
{
  if (_dir == t_dir::UP)
    _pos.setY(_pos.getY() - _speed);
  if (_dir == t_dir::DOWN)
    _pos.setY(_pos.getY() + _speed);
  if (_dir == t_dir::LEFT)
    _pos.setX(_pos.getX() - _speed);
  if (_dir == t_dir::RIGHT)
    _pos.setX(_pos.getX() + _speed);
  if (_dir == t_dir::DIAGUL)
    {
      _pos.setY(_pos.getY() - _speed);
      _pos.setX(_pos.getX() - _speed);
    }
  if (_dir == t_dir::DIAGUR)
    {
      _pos.setY(_pos.getY() - _speed);
      _pos.setX(_pos.getX() + _speed);
    }
  if (_dir == t_dir::DIAGDL)
    {
      _pos.setY(_pos.getY() + _speed);
      _pos.setX(_pos.getX() - _speed);
    }
  if (_dir == t_dir::DIAGDR)
    {
      _pos.setY(_pos.getY() + _speed);
      _pos.setX(_pos.getX() + _speed);
    }
}

bool		Player::isPuttingBomb()
{
  return _pressBomb;
}

bool		Player::putBomb(const std::shared_ptr<Map> &map, std::chrono::time_point<std::chrono::system_clock> now)
{
  if (map->getCase(_pos) == TileType::EMPTY && _n_bomb < _n_bomb_max)
    {
      Bomb bomb(_pos, _range, _bomb_type, now);

      _bomb.push_back(bomb);
      _n_bomb++;
      return true;
    }
  return false;
}

std::chrono::time_point<std::chrono::system_clock> Player::getBombTimer()
{
  return _bomb[0].getTimer();
}

void	Player::destroyBomb()
{
  _bomb.erase(_bomb.begin());
  _n_bomb--;
}

unsigned int	Player::getNBomb()
{
  return _n_bomb;
}

Position	Player::getBombPos()
{
  if (_n_bomb != 0)
    return _bomb[0].getPos();
  return _pos;
}

e_Bomb		Player::getBombType()
{
  if (_n_bomb != 0)
    return _bomb[0].getType();
  return e_Bomb::NORMAL;
}

unsigned int	Player::getBombRange()
{
  if (_n_bomb != 0)
    return _bomb[0].getRange();
  return 1;
}

void	Player::upBomb()
{
  if (_n_bomb_max < MAX_BOMB)
    _n_bomb_max++;
}

void	Player::upRange()
{
  if (_range < MAX_RANGE)
    _range++;
}

void	Player::upSpeed()
{
  if (_moove_speed < MAX_SPEED)
    _moove_speed++;
}

bool            Player::checkDangerRight(const std::shared_ptr<Map> &map)
{
  Position      tmp((_pos.getX() + HITBOX_PLAYER - 0.01), _pos.getY());
  int   i = 0;
  while (i != _n_bomb)
    {
      if ((_bomb[i].getX() - _range) <= (_pos.getX() + HITBOX_PLAYER - 0.01 +  _speed) && (_pos.getX() + HITBOX_PLAYER - 0.01 + _speed) <=  (_bomb[i].getX() + _range)
	  && (_bomb[i].getY() - _range) <= _pos.getY() && _pos.getY() <=  (_bomb[i].getY() + _range))
	return false;
      i = i + 1;
    }
  if ((tmp.getX()) > map->getWidth())
    return false;
  if (map->getCase(tmp) == TileType::FLAME)
    return false;
  tmp.setY(tmp.getY() + HITBOX_PLAYER - 0.01);
  if (map->getCase(tmp) == TileType::FLAME)
    return false;
  i = 0;
  while(i != _n_bomb)
    {
      if ((_bomb[i].getX() - _range) <= (_pos.getX() + HITBOX_PLAYER - 0.01 +  _speed) && (_pos.getX() + HITBOX_PLAYER - 0.01 +  _speed) <=  (_bomb[i].getX() + _range)
	  && (_bomb[i].getY() - _range) <= tmp.getY() && tmp.getY() <=  (_bomb[i].getY() + _range))
	return false;
      i = i + 1;
    }
  return true;
}

bool            Player::checkDangerUp(const std::shared_ptr<Map> &map)
{
  Position      tmp(_pos.getX(), (_pos.getY()));
  int i = 0;
  while (i != _n_bomb)
    {
      if ((_bomb[i].getX() - _range) <= _pos.getX() && _pos.getX() <=  (_bomb[i].getX() + _range)
	  && (_bomb[i].getY() - _range) <= (_pos.getY() - _speed) && (_pos.getY() - _speed) <=  (_bomb[i].getY() + _range))
	return false;
      i = i + 1;
    }

  if (tmp.getY() < 0)
    return false;
  if (map->getCase(tmp) == TileType::FLAME)
    return false;
  tmp.setX(tmp.getX() + HITBOX_PLAYER - 0.01);
  if (map->getCase(tmp) == TileType::FLAME)
    return false;
  i = 0;
  while(i != _n_bomb)
    {
      if ((_bomb[i].getX() - _range) <= tmp.getX() && tmp.getX() <=  (_bomb[i].getX() + _range)
	  && (_bomb[i].getY() - _range) <= (_pos.getY() - _speed) && (_pos.getY() - _speed) <=  (_bomb[i].getY() + _range))
	return false;
      i = i + 1;
    }

  return true;
}

bool            Player::checkDangerLeft(const std::shared_ptr<Map> &map)
{
  Position      tmp((_pos.getX()), _pos.getY());
  int i = 0;
  while(i != _n_bomb)
    {
      if ((_bomb[i].getX() - _range) <= (_pos.getX() - _speed) && (_pos.getX() - _speed) <=  (_bomb[i].getX() + _range)
	  && (_bomb[i].getY() - _range) <= _pos.getY() && _pos.getY() <=  (_bomb[i].getY() + _range))
	return false;
      i = i + 1;
    }

  if (tmp.getX() < 0)
    return false;
  if (map->getCase(tmp) == TileType::FLAME)
    return false;
  tmp.setY(tmp.getY() + HITBOX_PLAYER - 0.01);
  if (map->getCase(tmp) == TileType::FLAME)
    return false;
  i = 0;
  while(i != _n_bomb)
    {
      if ((_bomb[i].getX() - _range) <= (_pos.getX() - _speed) && (_pos.getX() - _speed) <=  (_bomb[i].getX() + _range)
	  && (_bomb[i].getY() - _range) <= tmp.getY() && tmp.getY() <=  (_bomb[i].getY() + _range))
	return false;
      i = i + 1;
    }

  return true;
}

bool            Player::checkDangerDown(const std::shared_ptr<Map> &map)
{
  Position      tmp(_pos.getX(), (_pos.getY() + HITBOX_PLAYER - 0.01));
  int i = 0;
  std::cout<< "DANGER DOWN" << std::endl;
  while(i != _n_bomb)
    {
      if ((_bomb[i].getX() - _range) <= _pos.getX() && _pos.getX() <=  (_bomb[i].getX() + _range)
	  && (_bomb[i].getY() - _range) <= (_pos.getY() + HITBOX_PLAYER - 0.01 + _speed) && (_pos.getY() + HITBOX_PLAYER - 0.01 + _speed) <=  (_bomb[i].getY() + _range))
	return false;
      std::cout << "i=" << i << " bomb=" << _n_bomb << " xmin=" << (_bomb[i].getX() - _range) << " x=" << _pos.getX() << " xman=" <<
	(_bomb[i].getX() + _range) << " ymin=" << (_bomb[i].getY() - _range) << " y=" << (_pos.getY() +  HITBOX_PLAYER - 0.01 + _speed) << " ymax=" << (_bomb[i].getY() + _range) << std::endl;
      i = i + 1;
    }

  if ((int)(tmp.getY()) > map->getHeight())
    return (false);
  if (map->getCase(tmp) == TileType::FLAME)
    return false;
  tmp.setX(tmp.getX() + HITBOX_PLAYER - 0.01);
  if (map->getCase(tmp) == TileType::FLAME)
    return false;
  i = 0;
  while(i != _n_bomb)
    {
      if ((_bomb[i].getX() - _range) <= tmp.getX() && tmp.getX() <=  (_bomb[i].getX() + _range)
	  && (_bomb[i].getY() - _range) <= (_pos.getY() + HITBOX_PLAYER - 0.01 + _speed) && (_pos.getY() + HITBOX_PLAYER - 0.01 + _speed) <=  (_bomb[i].getY() + _range))
	return false;
      i = i + 1;
    }

  return true;
}

void    Player::reset_pos()
{
  this->_pressRight = false;
  this->_pressLeft = false;
  this->_pressUp = false;
  this->_pressDown = false;
  this->_pressBomb = false;
}

void    Player::loop_for_ia(std::mutex *verrou, const std::shared_ptr<Map> &map)
{
  verrou->lock();
  std::cout << "Dans le thread" << std::endl;
  std::mt19937  mt;
  std::uniform_int_distribution<int> rand_mt(0, 3);

  mt.seed(time(nullptr));
  int tmp = rand_mt(mt);
  int i = 0;

  
  if (this->_pressLeft && checkWallLeft(map) && checkDangerLeft(map))
    this->_pressLeft;
  else if (this->_pressRight && checkWallRight(map) && checkDangerRight(map))
    this->_pressRight;
  else if (this->_pressUp && checkWallUp(map) && checkDangerUp(map))
    this->_pressUp;
  else if (this->_pressDown && checkWallDown(map) && checkDangerDown(map))
    this->_pressDown;
  else if (_n_bomb != _n_bomb_max && !checkWallRight(map) && checkWallLeft(map))
    {
      reset_pos();
      this->_pressBomb = true;
      this->_pressLeft = true;
    }
  else if (_n_bomb != _n_bomb_max && !checkWallDown(map) && checkWallUp(map))
    {
      reset_pos();
      this->_pressBomb = true;
      this->_pressUp = true;
    }
  else if (_n_bomb != _n_bomb_max && !checkWallLeft(map) && checkWallRight(map))
    {
      reset_pos();
      this->_pressBomb = true;
      this->_pressRight = true;
    }
  else if (_n_bomb != _n_bomb_max && !checkWallUp(map) && checkWallDown(map))
    {
      reset_pos();
      this->_pressBomb = true;
      this->_pressDown = true;
    }
  else if (checkWallDown(map) && checkDangerDown(map))
    {
      reset_pos();
      this->_pressDown = true;
    }
  else if (checkWallUp(map) && checkDangerUp(map))
    {
      reset_pos();
      this->_pressUp = true;
    }
  else if (checkWallLeft(map) && checkDangerLeft(map))
    {
      reset_pos();
      this->_pressLeft = true;
    }
  else if (checkWallRight(map) && checkDangerRight(map))
    {
      reset_pos();
      this->_pressRight = true;
    }
  else if (_n_bomb == _n_bomb_max)
    reset_pos();
  std::cout << tmp << " : " << _dir << " : " << _range << std::endl;
  i = i + 1;
  verrou->unlock();
}

bool    Player::isAlive(const std::shared_ptr<Map> &map)
{
  if (_ia && _isalive)
    {
      std::mutex    verrou;
      std::thread   ia_thread(&Player::loop_for_ia, this, &verrou, map);

      ia_thread.join();
    }
  return _isalive;
}

int	Player::getMooveSpeed()
{
  return _moove_speed;
}

void	Player::setIA(bool value)
{
  _ia = value;
}
