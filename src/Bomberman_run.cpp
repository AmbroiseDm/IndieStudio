//
// Bomberman_run.cpp for Bomberman in /home/theogalh/projet/cpp_indie_studio
// 
// Made by AdelyanTV-VM
// Login   <thomas.bouillon@epitech.eu>
// 
// Started on  Sun Jun 18 19:53:03 2017 AdelyanTV-VM
// Last update Wed Jun 21 15:27:40 2017 ambroise
//

#include "Bomberman.hpp"

void Bomberman::run()
{
	Position pos(0, 0);
	unsigned int n;
	std::chrono::time_point<std::chrono::system_clock>	now;
	int	frame;
	int	flag;

	// temportaire
	frame = 0;
	while(render->run())
	  {
	    now = std::chrono::system_clock::now();
	    n = 0;
	    if (frame == 60)
	      frame = 0;
	    for (auto &player : players)
	      {
		flag = 0;
		
		if (player.isAlive(map) && player.isMoving())
		  {
		    for (int speed = 0; speed < player.getMooveSpeed(); ++speed)
		      {
			
			player.setDirection(render->getSceneManager().convertMove(player.getDirection()));
			if ((frame + speed) % 7 == 0)
			  {
			    flag++;
			    
			    if (player.checkWall(map))
			      {
				player.movePlayer();
				render->getSceneManager().movePlayer(n, player.getDirection());
			      }
			  }
		      }
		    if (flag == 0)
		      render->getSceneManager().walkPlayer(n, player.getDirection());
		  }
		else
		  render->getSceneManager().movePlayer(n, NONE);
		if (player.isAlive(map) == true && player.isPuttingBomb() && player.putBomb(map, now))
	      {
		if (Debug::isDebug())
		  std::cout << "n_exept = " << _exeption.size() << std::endl;
		pos = player.getPosition();
	  map->setCase(pos, TileType::BOMB);
	  if (Debug::isDebug())
	    std::cout << "affichage d'une bombe" << std::endl;
	  render->getSceneManager().addNode(4, pos.getX(), pos.getY());
	}
		if (player.getNBomb() != 0 && std::chrono::duration_cast<std::chrono::milliseconds>(now - player.getBombTimer()).count() > 3000 || checkSetExplosion(player.getBombPos()) == true)
		  {
		    pos = player.getBombPos();
    		  map->setCase(pos, TileType::EMPTY);
    		  render->getSceneManager().deleteNode(pos.getX(), pos.getY());
    		  explosion(pos, player.getBombType(), player.getBombRange(), now);
    		  player.destroyBomb();
    		  if (Debug::isDebug())
    		      std::cout << "destruction d'une bombe" << std::endl;
    	  }
    	  if (getNFlame() != 0 && std::chrono::duration_cast<std::chrono::milliseconds>(now - getFlameTimer()).count() > 1500)
    		  endExplosion(_flame[0].getPos(), _flame[0].getRange());
	  if (player.isAlive(map) == true && map->getCase(player.getPosition()) == TileType::FLAME)
	    {
	      player.setScore(_score);
	      _score = _score + 500;
	      _end++;
	      player.Die();
	      render->getSceneManager().deletePlayer(n);
	    }
	  if (_end >= 3)
	    {
	      int tempo_n = 0;
	      while (tempo_n != 4)
		{
		  if (players[tempo_n].isAlive(map) == true)
		    players[tempo_n].setScore(_score);
		  tempo_n++;
		}
	      render->setGUI(GUIMENU);
            _end = 0;
	    }
    	  else if (map->getCase(player.getPosition()) == TileType::POWERUP_BOMB
    			  || map->getCase(player.getPosition()) == TileType::POWERUP_RANGE
				  || map->getCase(player.getPosition()) == TileType::POWERUP_SPEED)
	    {
	      if (map->getCase(player.getPosition()) == TileType::POWERUP_BOMB)
    			  player.upBomb();
    		  if (map->getCase(player.getPosition()) == TileType::POWERUP_RANGE)
    			  player.upRange();
    		  if (map->getCase(player.getPosition()) == TileType::POWERUP_SPEED)
    			  player.upSpeed();
    		  pos = player.getPosition();
    		  render->getSceneManager().deleteNode(pos.getX(), pos.getY());
    		  map->setCase(pos, TileType::EMPTY);
    	  }
    	  ++n;
	  frame++;
      }
      render->render(irr::video::SColor(255, 255, 105, 180));
    }
}

unsigned int Bomberman::getNFlame()
{
  return _flame.size();
}

bool Bomberman::checkSetExplosion(Position pos)
{
  for (int n = 0; n != _set_explosion.size(); ++n)
  {
	  if (std::floor(pos.getX()) == std::floor(_set_explosion[n].getX()) && std::floor(pos.getY()) == std::floor(_set_explosion[n].getY()))
	  {
		  _set_explosion.erase(_set_explosion.begin() + n);
	  	  return true;
	  }
  }
  return false;
}

std::chrono::time_point<std::chrono::system_clock> Bomberman::getFlameTimer()
{
  return _flame[0].getTimer();
}

bool Bomberman::check_exeption(Position pos)
{
	for (int n = 0; n != _set_explosion.size(); ++n)
	{
		if (std::floor(pos.getX()) == std::floor(_exeption[n].getX()) && std::floor(pos.getY()) == std::floor(_exeption[n].getY()))
		{
			_exeption[n].setY(40);
			return true;
		}
	}
	return false;
}

void Bomberman::getPowerUp(Position pos)
{
  int random;
  std::mt19937  mt;
  std::uniform_int_distribution<int> rand_mt(0, 9);
  mt.seed(time(nullptr));
  for (int n = 0; n < _power_up.size(); ++n)
  {
    if (std::floor(pos.getX()) == std::floor(_power_up[n].getX()) && std::floor(pos.getY()) == std::floor(_power_up[n].getY()))
	  {
	    random = rand_mt(mt);
	    if (random == 1)
	      map->setCase(pos, TileType::POWERUP_BOMB);
	    if (random == 2)
	      map->setCase(pos, TileType::POWERUP_RANGE);
	    if (random == 3)
	      map->setCase(pos, TileType::POWERUP_SPEED);
	    _power_up.erase(_power_up.begin() + n);
	  }
  }
}

bool Bomberman::setPowerUp(const Position &pos)
{
	if (map->getCase(pos) == TileType::FLAME || map->getCase(pos) == TileType::EMPTY /* && !check_exeption(tmp) */)
	{
		getPowerUp(pos);
		if (map->getCase(pos) != TileType::FLAME && map->getCase(pos) != TileType::EMPTY)
		{
		  if (map->getCase(pos) == POWERUP_BOMB)
		    render->getSceneManager().addNode(6, pos.getX(), pos.getY(), POWERUPBOMB);
		  if (map->getCase(pos) == POWERUP_RANGE)
		    render->getSceneManager().addNode(6, pos.getX(), pos.getY(), POWERUPFIRE);
		  if (map->getCase(pos) == POWERUP_SPEED)
		    render->getSceneManager().addNode(6, pos.getX(), pos.getY(), POWERUPSKATE);
		}
		else
		{
		  map->setCase(pos, TileType::EMPTY);
		  render->getSceneManager().deleteNode(pos.getX(), pos.getY());
		}
	}
}

void Bomberman::endExplosion(Position pos, unsigned int range)
{
  Position	tmp(pos);

  render->getSceneManager().deleteNode(pos.getX(), pos.getY());
  map->setCase(tmp, TileType::EMPTY);
  tmp.setY(pos.getY() + 1);
  while (tmp.getY() <= (pos.getY() + range) && tmp.getY() < map->getHeight())
  {
      if (!setPowerUp(tmp))
        tmp.setY(tmp.getY() + 1);
      else
	tmp.setY(tmp.getY() + 1);
  }
  tmp.setY(pos.getY() - 1);
  while (tmp.getY() >= (pos.getY() - range) && tmp.getY() >= 0)
  {
    if (!setPowerUp(tmp))
      tmp.setY(tmp.getY() - 1);
    else
      tmp.setY(tmp.getY() - 1);
  }
  tmp.setY(pos.getY());
  tmp.setX(pos.getX() + 1);

  while (tmp.getX() <= (pos.getX() + range) && tmp.getX() < map->getWidth())
    {
      if (!setPowerUp(tmp))
        tmp.setX(tmp.getX() + 1);
      else
	tmp.setX(tmp.getX() + 1);
  }
  tmp.setX(pos.getX() - 1);
  while (tmp.getX() >= (pos.getX() - range) && tmp.getX() >= 0)
  {
    if (!setPowerUp(tmp))
      tmp.setX(tmp.getX() - 1);
    else
      tmp.setX(tmp.getX() - 1);
  }
  _flame.erase(_flame.begin());
}


void Bomberman::explosion(Position pos, e_Bomb type, unsigned int range, std::chrono::time_point<std::chrono::system_clock> now)
{
  Flame	flame(pos, range, type, now);
  Position tmp(pos);
  int	random;

  render->getSceneManager().addNode(7, pos.getX(), pos.getY());
  map->setCase(tmp, TileType::FLAME);
  tmp.setY(pos.getY() + 1);
  while (tmp.getY() <= (pos.getY() + range) && tmp.getY() < map->getHeight())
  {
	  if (map->getCase(tmp) != TileType::BLOCK)
	  {
		  if (map->getCase(tmp) == TileType::BREAKABLE)
		  {
			  if (Debug::isDebug())
				  std::cout << "BREAKABLE" << std::endl;
			  _power_up.push_back(tmp);
			  map->setCase(tmp, TileType::FLAME);
			  render->getSceneManager().addNode(8, tmp.getX(), tmp.getY());
			  tmp.setY(pos.getY() + range);
		  }
		  else
		  {
			  if (map->getCase(tmp) == TileType::BOMB)
				  _set_explosion.push_back(tmp);
			  map->setCase(tmp, TileType::FLAME);
			  render->getSceneManager().addNode(8, tmp.getX(), tmp.getY());
		  }
	  }
      else
        tmp.setY(pos.getY() + range);
      tmp.setY(tmp.getY() + 1);
  }
  tmp.setY(pos.getY() - 1);
  while (tmp.getY() >= (pos.getY() - range) && tmp.getY() >= 0)
  {
     
	  if (map->getCase(tmp) != TileType::BLOCK)
      {
		  if (map->getCase(tmp) == TileType::BREAKABLE)
		  {
			  if (Debug::isDebug())
				  std::cout << "BREAKABLE" << std::endl;
			  _power_up.push_back(tmp);
			  map->setCase(tmp, TileType::FLAME);
			  render->getSceneManager().addNode(8, tmp.getX(), tmp.getY());
			  tmp.setY(pos.getY() - range);
		  }
		  else
		  {
			  if (map->getCase(tmp) == TileType::BOMB)
				  _set_explosion.push_back(tmp);
			  map->setCase(tmp, TileType::FLAME);
			  render->getSceneManager().addNode(8, tmp.getX(), tmp.getY());
		  }
      }
      else
        tmp.setY(pos.getY() - range);
      tmp.setY(tmp.getY() - 1);
  }
  tmp.setY(pos.getY());
  tmp.setX(pos.getX() + 1);
  while (tmp.getX() <= (pos.getX() + range) && tmp.getX() < map->getWidth())
  {
	  if (map->getCase(tmp) != TileType::BLOCK)
      {
		  if (map->getCase(tmp) == TileType::BREAKABLE)
		  {
			  if (Debug::isDebug())
				  std::cout << "BREAKABLE" << std::endl;
			  _power_up.push_back(tmp);
			  map->setCase(tmp, TileType::FLAME);
			  render->getSceneManager().addNode(8, tmp.getX(), tmp.getY());
			  tmp.setX(pos.getX() + range);
		  }
		  else
		  {
			  if (map->getCase(tmp) == TileType::BOMB)
				  _set_explosion.push_back(tmp);
			  map->setCase(tmp, TileType::FLAME);
			  render->getSceneManager().addNode(8, tmp.getX(), tmp.getY());
		  }
      }
      else
        tmp.setX(pos.getX() + range);
      tmp.setX(tmp.getX() + 1);
  }
  tmp.setX(pos.getX() - 1);
  while (tmp.getX() >= (pos.getX() - range) && tmp.getX() >= 0)
  {
      if (map->getCase(tmp) != TileType::BLOCK)
      {
    	  if (map->getCase(tmp) == TileType::BREAKABLE)
    	  {
    		  if (Debug::isDebug())
    			  std::cout << "BREAKABLE" << std::endl;
    		  _power_up.push_back(tmp);
    		  map->setCase(tmp, TileType::FLAME);
    		  render->getSceneManager().addNode(8, tmp.getX(), tmp.getY());
    		  tmp.setX(pos.getX() - range);
    	  }
    	  else
    	  {
    		  if (map->getCase(tmp) == TileType::BOMB)
    			  _set_explosion.push_back(tmp);
    		  map->setCase(tmp, TileType::FLAME);
    		  render->getSceneManager().addNode(8, tmp.getX(), tmp.getY());
    	  }
      }
      else
        tmp.setX(pos.getX() - range);
      tmp.setX(tmp.getX() - 1);
  }
  _flame.push_back(flame);
}


void Bomberman::aff_map()
{
  std::mt19937	mt;
  std::uniform_int_distribution<int> rand_mt(1,5);
  mt.seed(time(nullptr));
  for (int y = 0; y != map->getHeight(); ++y)
  {
	  for (int x = 0; x != map->getWidth(); ++x)
	  {
		  TileType type = map->getCase(Position(x, y));
		  if (type == BLOCK)
		    {
		      render->getSceneManager().addNode(world * 10, x, y);
		    }
		  else if (type == BREAKABLE)
		    {
		      render->getSceneManager().addNode(rand_mt(mt) + (world * 10), x, y);
		    }
	  }
  }
  if (Debug::isDebug())
  {
	  for (int y = 0; y != map->getHeight(); ++y)
	  {
		  for (int x = 0; x != map->getWidth(); ++x)
		  {
			  TileType type = map->getCase(Position(x, y));
			  if (type == BLOCK)
				std::cout << "#";
			  else if (type == TileType::BREAKABLE)
				std::cout << "X";
			  else if (type == TileType::EMPTY)
				std::cout << "0";
			  else if (type == TileType::FLAME)
			    std::cout << "F";
			  else
				std::cout << "?";
		  }
		std::cout << std::endl;
	  }
  }
}
