//
// EventListener.hpp for Indie Studio in /home/lerest_m/Desktop/Programmation/C++/cpp_indie_studio/Renderer/include/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Sat May 27 11:40:52 2017 Mewen Le Reste
// Last update Sat May 27 13:00:06 2017 Mewen Le Reste
//

#ifndef EVENTLISTENER_HPP_
# define EVENTLISTENER_HPP_

# include "Bomberman.hpp"

class Bomberman;

class EventListener : public irr::IEventReceiver
{
	private:
        int movingPlayer;
		std::shared_ptr<Bomberman> game;
		bool mouseEvent(const irr::SEvent::SMouseInput &event);
		bool keyEvent(const irr::SEvent::SKeyInput &event);
		bool joystickEvent(const irr::SEvent::SJoystickEvent &event);

	public:
		EventListener(const std::shared_ptr<Bomberman> &);
		EventListener(const EventListener &) = delete;
		EventListener &operator=(const EventListener &) = delete;
		virtual ~EventListener() = default;
		bool OnEvent(const irr::SEvent &);
};

#endif //EVENTLISTENER_HPP_
