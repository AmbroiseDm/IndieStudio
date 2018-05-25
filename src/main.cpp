//
// main.cpp for main in /home/theogalh/projets/cpp_indie_studio/src
//
// Made by Theogalh
// Login   <thomas.bouillon@epitech.eu>
//
// Started on  Wed May  3 13:20:40 2017 Theogalh
// Last update Sat May 27 13:28:41 2017 Mewen Le Reste
//

# include "Bomberman.hpp"

int	main(int ac, const char **av)
{
	try
	{
        if (ac == 2 && std::string(av[1]) == "-d")
            Debug::setDebug(true);
		std::shared_ptr<Bomberman> bomberman = std::make_shared<Bomberman>();
        std::shared_ptr<IGUI> menu = std::make_shared<Menu>(bomberman);
        std::shared_ptr<IGUI> option = std::make_shared<Option>(bomberman);
        std::shared_ptr<IGUI> gameGUI = std::make_shared<GameGUI>(bomberman);
        std::shared_ptr<IGUI> splash = std::make_shared<Splash>(bomberman);
        bomberman->addGUI(menu, option, gameGUI, splash);
		EventListener listener(bomberman);
		bomberman->getRenderer()->setEventListener(&listener);
		bomberman->run();
		return 0;
	} catch (const Exception &error)
	{
		error.dump();
		return 1;
	}
}
