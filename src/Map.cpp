//
// Map.cpp for aze in /home/damier_a/indie_studio_ambroise
// 
// Made by Ambroise DAMIER
// Login   <damier_a@epitech.net>
// 
// Started on  Fri May 26 14:25:48 2017 Ambroise DAMIER
// Last update Sun Jun 18 15:59:52 2017 Alexandre
//

#include "Map.hpp"

Map::Map() : height(0), width(0) {}

Map::Map(const std::string &file) : height(0), width(0)
{
  char c;
  unsigned int tmp = 0;
  std::vector<TileType>	tempo;
  std::ifstream flux(file.c_str(), std::ios::in);


  if (flux)
    {
      while (flux.get(c))
		{
		  if (c == '\n' || c == '\0')
			{
			  map.push_back(tempo);
			  tempo.clear();
			  ++this->height;
			  this->width = tmp;
			  tmp = 0;
			}
		  else
			{
			  std::string type;
			  type += c;
			  tempo.push_back(static_cast<TileType>(std::stoi(type)));
			  ++tmp;
			}
		}
      map.push_back(tempo);
      tempo.clear();
      ++this->height;
      this->width = tmp;
    }
  flux.close();
}

Map::Map(const Map &clone) : map(clone.map), width(clone.width), height(clone.height) {}

Map &Map::operator=(Map const &clone)
{
  this->map = clone.map;
  this->width = clone.width;
  this->height = clone.height;
  return (*this);
}

TileType Map::getCase(const Position &pos) const
{
	int x = pos.getX(), y = pos.getY();
	if (y < 0 || y >= map.size() || x < 0 || x >= map[0].size())
		return (TileType::BLOCK);
	return (map[y][x]);
}


void Map::setCase(const Position &pos, TileType type)
{
  map[(int)pos.getY()][(int)pos.getX()] = type;
}


unsigned int Map::getHeight() const
{
  return (height);
}

unsigned int Map::getWidth() const
{
  return (width);
}

void Map::setHeight(unsigned int h)
{
  height = h;
}

void Map::setWidth(unsigned int w)
{
  width = w;
}

void	Map::generate(int width, int height)
{
  std::mt19937  mt;
  std::uniform_int_distribution<int> rand_mt(0, 2);
  std::vector<TileType> tmp;
  int	i = 0;
  int	j = 0;
  if (height % 2 == 0)
    height = height + 1;
  if (width % 2 == 0)
    width = width + 1;

  for (auto &it : map)
	  it.clear();
  map.clear();
  mt.seed(time(nullptr));
  while (i != width)
    {
      while (j != height)
	{
	  if ((i == 1 || i == (width - 2)) && (j == 1 || j == (height - 2)))
	    tmp.push_back(static_cast<TileType>(1));
	  else if ((i <= 1 || i >= (width - 2)) && (j <= 1 || j >= (height - 2)))
	    tmp.push_back(static_cast<TileType>(0));
	  else if (i % 2 == 1 && j % 2 == 1)
	    {
	      if (rand_mt(mt) != 0)
		tmp.push_back(static_cast<TileType>(1));
	      else
		tmp.push_back(static_cast<TileType>(0));
	    }
	  // else if (i == 0 || j == 0 || i == (width - 1) || j == (height - 1))
	  //   tmp.push_back(static_cast<TileType>(2));
	  else
	    {
	      if (rand_mt(mt) != 0)
		tmp.push_back(static_cast<TileType>(2));
	      else
		tmp.push_back(static_cast<TileType>(0));
	    }
	  j = j + 1;
	}
      map.push_back(tmp);
      tmp.clear();
      j = 0;
      i = i + 1;
    }
  this->height = width;
  this->width = height;
}
