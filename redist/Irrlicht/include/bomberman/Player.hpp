//
// Player.hpp for  in /home/soraaz/rendu/cpp_indie_studio
// 
// Made by Soraaz
// Login   <robin1.partouche@epitech.eu>
// 
// Started on  Fri May 26 14:05:53 2017 Soraaz
// Last update Thu Jun 15 22:22:04 2017 ambroisedamier
//

# ifndef PLAYER_CPP
# define PLAYER_CPP

# define HEIGHT_MAP 10
# define WIDTH_MAP 10
# define BASE_RANGE 1
# define BASE_SPEED 0.25
# define GAIN_SPEED 0.25
# define HITBOX_PLAYER_BOMB 1
# define HITBOX_PLAYER_MOVE 1

#include <vector>
#include "Bomb.hpp"
#include "irrlicht.h"
#include "Protocol.hpp"
#include "Map.hpp"
#include "define.hpp"

class Player
{
private:
  Position _pos;
  t_dir _dir;
  int _type;

  irr::EKEY_CODE        _keyBomb;
  irr::EKEY_CODE        _keyDown;
  irr::EKEY_CODE        _keyUp;
  irr::EKEY_CODE        _keyLeft;
  irr::EKEY_CODE        _keyRight;

  bool			_pressBomb;
  bool			_pressUp;
  bool			_pressLeft;
  bool			_pressDown;
  bool			_pressRight;

  std::vector<Bomb> _bomb;
  float _range;
  float _speed;
  float _bomb_stock;
  bool	_isalive;
public:
  Player(const int nb);
  ~Player();

  // clavier

  void	setKeyBoard(irr::EKEY_CODE bomb, irr::EKEY_CODE up, irr::EKEY_CODE left, irr::EKEY_CODE down, irr::EKEY_CODE right);
  void	setKeyBomb(irr::EKEY_CODE key);
  void	setKeyUp(irr::EKEY_CODE key);
  void	setKeyLeft(irr::EKEY_CODE key);
  void	setKeyDown(irr::EKEY_CODE key);
  void	setKeyRight(irr::EKEY_CODE key);

  irr::EKEY_CODE	getKeyBomb();
  irr::EKEY_CODE	getKeyUp();
  irr::EKEY_CODE	getKeyLeft();
  irr::EKEY_CODE	getKeyDown();
  irr::EKEY_CODE	getKeyRight();

  void	setPressBomb(bool b);
  void	setPressUp(bool b);
  void	setPressLeft(bool b);
  void	setPressDown(bool b);
  void	setPressRight(bool b);

  bool	getPressBomb();
  bool	getPressUp();
  bool	getPressLeft();
  bool	getPressDown();
  bool	getPressRight();


  void	setDirection(t_dir dir);
  t_dir	getDirection();
  
  void setPosition(Position pos);
  Position	getPosition();
  
  void Left();
  void Right();
  void Up();
  void Down();
  void Put_Bomb();
  void Die();

  bool	isMoving();
  void	movePlayer();
  bool	checkWall(const Map &map);

  bool	checkWallDown(const Map &map);
  bool	checkWallUp(const Map &map);
  bool	checkWallLeft(const Map &map);
  bool	checkWallRight(const Map &map);

  
  // void Bonus(int bonus /* );
};

# endif
