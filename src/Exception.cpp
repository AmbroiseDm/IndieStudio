//
// Exception.cpp for Indie Studio in /home/lerest_m/Desktop/Programmation/C++/cpp_indie_studio/Renderer/src/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Sat May 27 13:27:26 2017 Mewen Le Reste
// Last update Sat May 27 13:27:33 2017 Mewen Le Reste
// 

#include "Exception.hpp"

Exception::Exception(const std::string &error) : _what(error), _type("Exception") {}

Exception::Exception(const std::string &error, const std::string &type) : _what(error), _type(type) {}

Exception::Exception(const Exception &other) : _what(other._what), _type(other._type) {}

Exception &Exception::operator=(const Exception &other)
{
  this->_what = other._what;
  this->_type = other._type;
  return *this;
}

void Exception::dump() const
{
  std::cerr << _type << ": " << _what << std::endl;
}

const char *Exception::what() const throw()
{
  return _what.c_str();
}

const char *Exception::type() const throw()
{
  return _type.c_str();
}

Exception::~Exception() {}
