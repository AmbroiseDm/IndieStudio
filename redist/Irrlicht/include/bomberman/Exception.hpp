//
// Exception.hpp for Indie Studio in /home/lerest_m/Desktop/Programmation/C++/cpp_indie_studio/Renderer/include/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Sat May 27 13:27:38 2017 Mewen Le Reste
// Last update Sat May 27 13:27:44 2017 Mewen Le Reste
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <exception>
# include <iostream>
# include <string>

/**
 * A class that represent throwable exceptions
 */
class Exception : public std::exception
{
  private:
    std::string _what;
    std::string _type;

  public:
    /**
     * Conctructor, create an exception of type "Exception"
     *
     * @param error Error message
     */
    Exception(const std::string &);

    /**
     * Conctructor, create an exception of the given type
     *
     * @param error Error message
     * @param type  Type of the exception
     */
    Exception(const std::string &, const std::string &);

    /**
     * Copy conctructor
     *
     * @param other Exception to copy
     */
    Exception(const Exception &);

    /**
		 * Copy operator
		 *
		 * @param other	Exception to copy
		 * @return			The copy of the exception
		 */
    Exception &operator=(const Exception &);

    /**
     * Write the exception on the error stream
     */
    void dump() const;

    /**
     * Return the cause of the exception
     *
     * @return The cause of the exception
     */
    const char *what() const throw();

    /**
     * Return the error type
     *
     * @return The error type
     */
    const char *type() const throw();

    /**
     * Destructor
     */
    virtual ~Exception();
};

#endif //EXCEPTION_HPP_
