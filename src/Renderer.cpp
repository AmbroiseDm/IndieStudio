//
// Renderer.cpp for Indie Studio in /home/lerest_m/Desktop/Programmation/C++/cpp_indie_studio/Renderer/src/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Mon May 22 13:23:11 2017 Mewen Le Reste
// Last update Sun Jun 18 03:19:57 2017 AdelyanTV-VM
//

#include "Renderer.hpp"

Renderer::Renderer(const std::string &name, size_t width, size_t height, bool fullscreen, int nbScene) :
in_game(false), in_splash(true), disp_background(false), scene(0), name(name.begin(), name.end()), gui(""), joystickEnable(false)
{
    if (fullscreen)
      {
		irr::IrrlichtDevice *nulldevice = irr::createDevice(irr::video::EDT_NULL);
		irr::core::dimension2d<irr::u32> deskres = nulldevice->getVideoModeList()->getDesktopResolution();
		nulldevice -> drop();
		width = deskres.Width;
		height = deskres.Height;
      }
    device = irr::createDevice(irr::video::EDT_OPENGL,
			       irr::core::dimension2d<irr::u32>(width, height),
			       32, fullscreen, false, true, 0);
    this->width = width;
    this->height = height;
    if (!device)
      throw RendererException("Unable to create window");
    //joystickEnable = device->activateJoysticks(joystickInfo);
    driver = device->getVideoDriver();
    sceneManager.init(device, driver);
    device->setWindowCaption(this->name.c_str());
    guienv = device->getGUIEnvironment();
}

void Renderer::endSplash()
{
	in_splash = false;
}

bool Renderer::isInSplash() const
{
	return (in_splash);
}

bool Renderer::isInGame() const
{
	return (in_game);
}

bool Renderer::getJoystickEnable() const
{
	return (joystickEnable);
}

void Renderer::setCursor(bool cursor)
{
  device->getCursorControl()->setVisible(cursor);
}

irr::u32 Renderer::getNbJoystick() const
{
	return (joystickInfo.size());
}

bool Renderer::run()
{
  if (!device)
    return (false);
  return (device->run());
}

void Renderer::addGUI(std::shared_ptr<IGUI> &gui)
{
  guiManager[gui->getID()] = gui;
}

bool Renderer::setGUI(const std::string &idx)
{
  if (guiManager.find(idx) == guiManager.end())
    return (false);
  gui = idx;
  guienv->clear();
  guiManager[idx]->setGUI(guienv);
  if (guiManager[idx]->haveBackground())
    setBackground(guiManager[idx]->getBackground());
  else
    setBackground();
  setInGame(guiManager[idx]->isInGame());
  setCursor(guiManager[idx]->haveCursor());
  return (true);
}

void Renderer::setEventListener(EventListener *listener)
{
  if (device)
    device->setEventReceiver(listener);
}

void Renderer::setBackground(const std::string &path)
{
  background = driver->getTexture(path.c_str());
  disp_background = true;
}

void Renderer::setBackground()
{
  disp_background = false;
}

void Renderer::setInGame(bool state)
{
  this->in_game = state;
}

void Renderer::render(const irr::video::SColor &color)
{
  irr::core::dimension2d<irr::u32> size;
  
  if (device)
    {
      if (in_game && sceneManager.isFlying())
	setCursor(false);
      else if (in_game && !sceneManager.isFlying())
	setCursor(true);
      driver->beginScene(true, true, color);
      size = background->getOriginalSize();
      if (disp_background)
	driver->draw2DImage(background, irr::core::position2d<irr::s32>(0, 0),
			    irr::core::rect<irr::s32>(0, 0, size.Width, size.Height), 0,
			    irr::video::SColor(255, 255, 255, 255), true);
      if (in_game)
	sceneManager.render();
      guienv->drawAll();
      if (gui != "")
	guiManager[gui]->update();
      driver->endScene();
    }
}

irr::video::ITexture *Renderer::getTexture(const std::string &path)
{
  return (driver->getTexture(path.c_str()));
}

void Renderer::stop()
{
  if (device)
    device->closeDevice();
  device = NULL;
}

size_t Renderer::getWidth() const
{
  return width;
}

size_t Renderer::getHeight() const
{
  return height;
}

SceneManager &Renderer::getSceneManager()
{
	return (sceneManager);
}

Renderer::~Renderer()
{
  if (device)
    device->drop();
}
