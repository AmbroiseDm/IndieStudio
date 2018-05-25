//
// Map.hpp for aze in /home/damier_a/indie_studio_ambroise
// 
// Made by Ambroise DAMIER
// Login   <damier_a@epitech.net>
// 
// Started on  Fri May 26 11:06:29 2017 Ambroise DAMIER
// Last update Sun Jun 18 16:01:33 2017 Alexandre
//

#ifndef MAP_HPP_
# define MAP_HPP_

# include <vector>
# include <iostream>
# include <string>
# include <chrono>
# include <random>
# include <fstream>
# include "Protocol.hpp"

class Map
{
	private:
	  std::vector<std::vector<TileType>> map;
	  unsigned int height;
	  unsigned int width;

	public:
	  Map();
	  Map(const std::string &file);
	  Map(const Map &);
	  ~Map() = default;

	  Map &operator=(const Map &);
	  TileType getCase(const Position &) const;
	  void setCase(const Position &, TileType);
	  unsigned int getHeight() const;
	  unsigned int getWidth() const;
	  void setHeight(unsigned int);
	  void setWidth(unsigned int);
  
  void	generate(int width, int height);
};

#endif // !MAP_HPP_
