//
// Bomberman.cpp for  in /home/soraaz/rendu/cpp_indie_studio/src
//
// Made by Soraaz
// Login   <robin1.partouche@epitech.eu>
//
// Started on  Fri May 26 13:17:31 2017 Soraaz
// Last update Wed Jun 21 16:01:32 2017 ambroise
//

#include "Bomberman.hpp"

Bomberman::Bomberman()
{
	std::mt19937	mt;
	std::uniform_int_distribution<int> rand_mt(1,3);
	mt.seed(time(nullptr));
	world = rand_mt(mt);
	map = std::make_shared<Map>();
	map->setHeight(10);
	map->setWidth(10);
	sound = std::make_shared<Sound>();
	render = std::make_shared<Renderer>("IndieStudio", 820, 480, true, 1);
	render->setBackground(SPLASHBACKGROUND);
	_ia1 = false;
	_ia2 = true;
	_ia3 = true;
	_ia4 = true;
}

void Bomberman::addGUI(std::shared_ptr<IGUI> &menu, std::shared_ptr<IGUI> &option,
		std::shared_ptr<IGUI> &game, std::shared_ptr<IGUI> &splash)
{
  render->addGUI(menu);
  render->addGUI(option);
  render->addGUI(game);
  render->addGUI(splash);
  render->setGUI(GUISPLASH);
}

std::shared_ptr<Map> &Bomberman::getMap()
{
  return (map);
}

std::shared_ptr<Renderer> &Bomberman::getRenderer()
{
  return (render);
}

std::shared_ptr<Sound> &Bomberman::getSound()
{
  return (sound);
}

std::vector<Player> &Bomberman::getPlayers()
{
  return (players);
}

void Bomberman::resetMap()
{
    std::mt19937	mt;
    std::uniform_int_distribution<int> rand_mt(1,3);
    mt.seed(time(nullptr));
    world = rand_mt(mt);
    Player player1, player2, player3, player4;
    Position pos(0, 0);
    if (_ia1 == true)
      player1.setIA(true);
    if (_ia2 == true)
      player2.setIA(true);
    if (_ia3 == true)
      player3.setIA(true);
    if (_ia4 == true)
      player4.setIA(true);
    
	_score = 0;
	_end = 0;
	players.clear();
	render->getSceneManager().clear();
	map->generate(map->getWidth(), map->getHeight());
    if (world == 1)
	    render->getSceneManager().generateMap(WALL_METAL_M1, BOX_METAL3_M1, map->getWidth(), map->getHeight(), 10);
    else if (world == 2)
        render->getSceneManager().generateMap(FLOOR_WOOD_M2, STONE, map->getWidth(), map->getHeight(), 10);
    else if (world == 3)
        render->getSceneManager().generateMap(GRASS, WALL, map->getWidth(), map->getHeight(), 10);

    this->map = map;
	render->getSceneManager().addNode(((int)world * 10) + 6, pos.getX(), pos.getY(), PLAYERBLACKTEXTURE);
	player1.setKeyBoard(irr::KEY_KEY_A, irr::KEY_KEY_Z, irr::KEY_KEY_Q, irr::KEY_KEY_S, irr::KEY_KEY_D);
	player1.setPosition(pos);
	players.push_back(player1);

	pos.setX(map->getWidth() - 1);
	render->getSceneManager().addNode(((int)world * 10) + 7, pos.getX(), pos.getY(), PLAYERBLUETEXTURE);
	player2.setKeyBoard(irr::KEY_KEY_R, irr::KEY_KEY_T, irr::KEY_KEY_F, irr::KEY_KEY_G, irr::KEY_KEY_H);
	player2.setPosition(pos);
	players.push_back(player2);

	pos.setX(0);
	pos.setY(map->getHeight() - 1);
	render->getSceneManager().addNode(((int)world * 10) + 8, pos.getX(), pos.getY(), PLAYERREDTEXTURE);
	player3.setKeyBoard(irr::KEY_KEY_P, irr::KEY_KEY_O, irr::KEY_KEY_K, irr::KEY_KEY_L, irr::KEY_KEY_M);
	player3.setPosition(pos);
	players.push_back(player3);

	pos.setX(map->getWidth() - 1);
	render->getSceneManager().addNode(((int)world * 10) + 9, pos.getX(), pos.getY(), PLAYERGREENTEXTURE);
	player4.setKeyBoard(irr::KEY_RETURN, irr::KEY_UP, irr::KEY_LEFT, irr::KEY_DOWN, irr::KEY_RIGHT);
	player4.setPosition(pos);
	players.push_back(player4);

	aff_map();
}

void	Bomberman::setIA1(bool value)
{
  _ia1 = value;
}

void	Bomberman::setIA2(bool value)
{
  _ia2 = value;
}

void	Bomberman::setIA3(bool value)
{
  _ia3 = value;
}

void	Bomberman::setIA4(bool value)
{
  _ia4 = value;
}
