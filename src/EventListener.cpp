//
// EventListener.cpp for Indie Studio in /home/lerest_m/Desktop/Programmation/C++/cpp_indie_studio/Renderer/src/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Sat May 27 11:40:39 2017 Mewen Le Reste
// Last update Sun Jun 18 01:07:57 2017 Alexandre
//

#include "EventListener.hpp"

EventListener::EventListener(const std::shared_ptr<Bomberman> &game) : movingPlayer(0), game(game) {}

bool EventListener::OnEvent(const irr::SEvent &event)
{
  bool absorbed = false;
  
  switch (event.EventType)
  {
  	  case irr::EET_MOUSE_INPUT_EVENT :
  		  absorbed = mouseEvent(event.MouseInput);
  		  break ;
  	  case irr::EET_KEY_INPUT_EVENT :
  		  absorbed = keyEvent(event.KeyInput);
  		  break ;
  	  case irr::EET_JOYSTICK_INPUT_EVENT :
  		  if (game->getRenderer()->getJoystickEnable())
  			  absorbed = joystickEvent(event.JoystickEvent);
  		  break ;
  	  default:
  		  absorbed = false;
  		  break ;
  }
  return (absorbed);
}

bool EventListener::mouseEvent(const irr::SEvent::SMouseInput &)
{
  return false;
}

bool EventListener::keyEvent(const irr::SEvent::SKeyInput &event)
{
  unsigned int	n;
  n = 0;

  if (game->getRenderer()->isInSplash())
  {
	  if (event.PressedDown)
	  {
		  game->getRenderer()->endSplash();
		  game->getRenderer()->setGUI(GUIMENU);
	  }
  }
  else
  {
	  if (event.PressedDown && event.Key == irr::KEY_ESCAPE)
	  {
		  game->getRenderer()->stop();
		  return true;
	  }
	  if (game->getRenderer()->isInGame())
	  {
		  if (event.PressedDown && event.Key == irr::KEY_F10)
		  {
			  game->getRenderer()->getSceneManager().changeCameraLock();
			  return (true);
		  }
		  if (event.PressedDown)
		  {
			  while (n != game->getPlayers().size())
			  {
				  if (event.Key == game->getPlayers()[n].getKeyBomb())
					  game->getPlayers()[n].setPressBomb(true);
				  if (event.Key == game->getPlayers()[n].getKeyUp())
					  game->getPlayers()[n].setPressUp(true);
				  if (event.Key == game->getPlayers()[n].getKeyLeft())
					  game->getPlayers()[n].setPressLeft(true);
				  if (event.Key == game->getPlayers()[n].getKeyDown())
					  game->getPlayers()[n].setPressDown(true);
				  if (event.Key == game->getPlayers()[n].getKeyRight())
					  game->getPlayers()[n].setPressRight(true);
				  n++;
			  }
		  }
		  else
		  {
			  while (n != game->getPlayers().size())
			  {
				  if (event.Key == game->getPlayers()[n].getKeyBomb())
					  game->getPlayers()[n].setPressBomb(false);
				  if (event.Key == game->getPlayers()[n].getKeyUp())
					  game->getPlayers()[n].setPressUp(false);
				  if (event.Key == game->getPlayers()[n].getKeyLeft())
					  game->getPlayers()[n].setPressLeft(false);
				  if (event.Key == game->getPlayers()[n].getKeyDown())
					  game->getPlayers()[n].setPressDown(false);
				  if (event.Key == game->getPlayers()[n].getKeyRight())
					  game->getPlayers()[n].setPressRight(false);
				  n++;
			  }
		  }
	  }
  }
  return false;
}

bool EventListener::joystickEvent(const irr::SEvent::SJoystickEvent &event)
{
	for (int n = 0; n != game->getPlayers().size(); ++n)
    {
		if (event.Joystick == n)
		{
			irr::f32 moveHorizontal = static_cast<irr::f32>(event.Axis[irr::SEvent::SJoystickEvent::AXIS_X]) / 32767.f;
			if(fabs(moveHorizontal) < 0.05f)
				moveHorizontal = 0.f;
	  
			irr::f32 moveVertical = static_cast<irr::f32>(event.Axis[irr::SEvent::SJoystickEvent::AXIS_Y]) / -32767.f;
			if(fabs(moveVertical) < 0.05f)
				moveVertical = 0.f;
	  
			if (moveHorizontal > 0.f)
				game->getPlayers()[n].setPressRight(true);
			else if (moveHorizontal < 0.f)
				game->getPlayers()[n].setPressLeft(true);
			else
			{
				game->getPlayers()[n].setPressRight(false);
				game->getPlayers()[n].setPressLeft(false);
			}
			if (moveVertical > 0.f)
				game->getPlayers()[n].setPressUp(true);
			else if (moveVertical < 0.f)
				game->getPlayers()[n].setPressDown(true);
			else
			{
				game->getPlayers()[n].setPressUp(false);
				game->getPlayers()[n].setPressDown(false);
			}
			if (event.IsButtonPressed(0))
				game->getPlayers()[n].setPressBomb(true);
			else
				game->getPlayers()[n].setPressBomb(false);
		}
		else
		{
			game->getPlayers()[n].setPressBomb(false);
			game->getPlayers()[n].setPressUp(false);
			game->getPlayers()[n].setPressLeft(false);
			game->getPlayers()[n].setPressDown(false);
			game->getPlayers()[n].setPressRight(false);
		}
    }
	return false;
}
