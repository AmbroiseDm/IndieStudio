//
// Player.hpp for  in /home/soraaz/rendu/cpp_indie_studio
// 
// Made by Soraaz
// Login   <robin1.partouche@epitech.eu>
// 
// Started on  Fri May 26 14:05:53 2017 Soraaz
// Last update Mon Jun 19 00:49:26 2017 Soraaz
//

# ifndef PLAYER_CPP
# define PLAYER_CPP

# define HEIGHT_MAP 10
# define WIDTH_MAP 10
# define BASE_RANGE 1
# define BASE_SPEED 0.01
# define GAIN_SPEED 0.01
# define HITBOX_PLAYER 1
# define MAX_SPEED 15
# define MAX_RANGE 8
# define MAX_BOMB 8

#include <chrono>
#include <memory>
#include <vector>
#include <thread>
#include <mutex>
#include "Bomb.hpp"
#include "irrlicht.h"
#include "Protocol.hpp"
#include "Map.hpp"
#include "define.hpp"

class Player
{
protected:
  std::wstring  name;
  Position	_pos;
  t_dir		_dir;

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

  int   _score;	
  std::vector<Bomb> _bomb;
  float _range;
  float _speed;
  bool	_isalive;
  int	_moove_speed;
  bool	_ia;

  e_Bomb	_bomb_type;
  unsigned int _n_bomb_max;
  unsigned int _n_bomb;

public:
  Player();
  ~Player();

  // clavier

  void	setKeyBoard(irr::EKEY_CODE bomb, irr::EKEY_CODE up, irr::EKEY_CODE left, irr::EKEY_CODE down, irr::EKEY_CODE right);
  void	setKeyBomb(irr::EKEY_CODE key);
  void	setKeyUp(irr::EKEY_CODE key);
  void	setKeyLeft(irr::EKEY_CODE key);
  void	setKeyDown(irr::EKEY_CODE key);
  void	setKeyRight(irr::EKEY_CODE key);

  void		 setName(const std::wstring &);
  std::wstring   getName();
  void		 setScore(int );
  int		 getScore();
  
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
  bool	isPuttingBomb();
  bool	putBomb(const std::shared_ptr<Map> &map, std::chrono::time_point<std::chrono::system_clock> now);
  void	destroyBomb();
  unsigned int	getNBomb();
  Position	getBombPos();
  e_Bomb	getBombType();
  unsigned int	getBombRange();
  std::chrono::time_point<std::chrono::system_clock> getBombTimer();
  
  void	movePlayer();
  bool	checkWall(const std::shared_ptr<Map> &map);

  bool	checkWallDown(const std::shared_ptr<Map> &map);
  bool	checkWallUp(const std::shared_ptr<Map> &map);
  bool	checkWallLeft(const std::shared_ptr<Map> &map);
  bool	checkWallRight(const std::shared_ptr<Map> &map);
  bool checkDangerDown(const std::shared_ptr<Map> &map);
  bool checkDangerUp(const std::shared_ptr<Map> &map);
  bool checkDangerLeft(const std::shared_ptr<Map> &map);
  bool checkDangerRight(const std::shared_ptr<Map> &map);

  void	upBomb();
  void	upRange();
  void	upSpeed();
  bool isAlive(const std::shared_ptr<Map> &map);
  int	getMooveSpeed();
  void  loop_for_ia(std::mutex *verrou, const std::shared_ptr<Map> &map);
  void	reset_pos();
  void setIA(bool value);
  // void Bonus(int bonus /* );
};

# endif
