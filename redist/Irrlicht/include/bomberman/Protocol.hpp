//
// Protocol.hpp for  in /home/soraaz/rendu/cpp_indie_studio
// 
// Made by Soraaz
// Login   <robin1.partouche@epitech.eu>
// 
// Started on  Fri May 26 13:33:18 2017 Soraaz
// Last update Thu Jun 15 19:30:28 2017 ambroisedamier
//

#ifndef PROTOCOL_HPP_
# define PROTOCOL_HPP_

# include <stdlib.h>
# include <iostream>

typedef enum		e_TileType
  {
    EMPTY		= 0,
    BLOCK		= 1,
    BREAKABLE		= 2,
    BOMB		= 3,
    POWERUP		= 4
  }			TileType;

typedef enum		e_Direction
  {
    Up = 0,
    Left = 1,
    Down = 2,
    Right = 3,
    UL = 4,
    UR = 5,
    DL = 6,
    DR = 7
  }			Direction;

/**
 * A class that represent a 2D position
 */
class Position
{
	private:
  float x;
  float y;
  float z;
  bool set;

	public:
		/**
		 * Constructor
		 */
		Position()
		{
			this->x = 0;
			this->y = 0;
			this->z = 0;
			set = false;
		}

		/**
		 * Constructor
		 *
		 * @param x X position
		 * @param y Y position
		 */
		Position(float x, float y)
		{
			this->x = x;
			this->y = y;
			this->z = 0;
			set = true;
		}

		/**
		 * Constructor
		 *
		 * @param x X position
		 * @param y Y position
		 */
		Position(float x, float y, float z)
		{
		  this->x = x;
		  this->y = y;
		  this->z = z;
		  set = true;
		}

		/**
		 * Copy constructor
		 *
		 * @param other Other position to copy
		 */
		Position(const Position &other)
		{
			*this = other;
		}

		/**
		 * Copy operator
		 *
		 * @param other Other position to copy
		 * @return      The copy of the position
		 */
		Position &operator=(const Position &other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->set = other.set;
			return *this;
		}

		/**
		 * Comparison operator
		 *
		 * @param other Other position to compare
		 * @return      True if the given position is the same
		 */
		bool operator==(const Position &other) const
		{
			if (this->x == other.x && this->y == other.y && this->z == other.z && this->set == other.set)
				return true;
			return false;
		}

		/**
		 * Comparison operator
		 *
		 * @param other Other position to compare
		 * @return      True if the given position is the same
		 */
		bool operator!=(const Position &other) const
		{
			if (this->x != other.x || this->y != other.y || this->z != other.z || this->set != other.set)
				return true;
			return false;
		}

		/**
		 * Return the x position
		 *
		 * @return The x position
		 */
		float getX() const
		{
			return x;
		}

		/**
		 * Return the y position
		 *
		 * @return The y position
		 */
		float getY() const
		{
			return y;
		}

		/**
		 * Return the z position
		 *
		 * @return The z position
		 */
		float getZ() const
		{
			return z;
		}

		/**
		 * Set the x position to the given one
		 *
		 * @param x New x position
		 */
		void setX(float x)
		{
			this->x = x;
			set = true;
		}

		/**
		 * Set the y position to the given one
		 *
		 * @param y New y position
		 */
		void setY(float y)
		{
			this->y = y;
			set = true;
		}

		/**
		 * Set the z position to the given one
		 *
		 * @param z New z position
		 */
		void setZ(float z)
		{
			this->z = z;
			set = true;
		}

		/**
		 * Set the position to the given one
		 *
		 * @param x New x position
		 * @param y New y position
		 */
		void setPosition(float x, float y)
		{
			this->x = x;
			this->y = y;
			set = true;
		}

		/**
		 * Set the position to the given one
		 *
		 * @param x New x position
		 * @param y New y position
		 * @param z New z position
		 */
		void setPosition(float x, float y, float z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
			set = true;
		}

		/**
		 * Specify if the position has been set or not
		 *
		 * @return A boolean that specify if the position has been set or not
		 */
		bool isSet() const
		{
			return set;
		}

		/**
		 * Destructor
		 */
		~Position() {}
};

#endif //PROTOCOL_HPP_
