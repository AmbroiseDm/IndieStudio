//
// Renderer.hpp for Indie Studio in /home/lerest_m/Desktop/Programmation/C++/cpp_indie_studio/renderer/include/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Mon May 22 13:20:57 2017 Mewen Le Reste
// Last update Sat Jun 17 07:08:59 2017 ambroisedamier
//

#ifndef RENDERER_HPP_
# define RENDERER_HPP_

# include <irrlicht.h>
# include <map>
# include "define.hpp"
# include "EventListener.hpp"
# include "Exception.hpp"
# include "GUI.hpp"
# include "SceneManager.hpp"

class EventListener;
class IGUI;

class RendererException : public Exception
{
	public:
		RendererException(const std::string &error) : Exception(error, "RendererException") {}
};

class Renderer
{
	private:
		int scene;
        std::string gui;
        bool in_game;
        bool in_splash;
        bool disp_background;
		size_t width;
		size_t height;
		std::wstring name;
		irr::IrrlichtDevice *device;
		irr::video::IVideoDriver *driver;
		irr::gui::IGUIEnvironment *guienv;
        std::map<std::string, std::shared_ptr<IGUI>> guiManager;
        SceneManager sceneManager;
        irr::video::ITexture *background;
        irr::core::array<irr::SJoystickInfo> joystickInfo;
        bool joystickEnable;

        void setInGame(bool);
        void setCursor(bool);

	public:
		/**
		 * Constructor of the renderer based on Irrlicht
		 * Create the window
		 *
		 * @param name       Name of the window
		 * @param width      Width of the window
		 * @param height     Height of the window
		 * @param fullscreen Specify if the window is fullscreen or not
		 * @param nbScene    Number of scene in the game
		 */
		Renderer(const std::string &, size_t, size_t, bool, int);
		Renderer(const Renderer &) = delete;
		Renderer &operator=(const Renderer &) = delete;

        /**
        * Change the GUI to display
        *
        * @param gui GUI to add
        * @return Idx to the added GUI
        */
        void addGUI(std::shared_ptr<IGUI> &);

        /**
         * Change the GUI to display
         *
         * @param idx Index of the gui to set
         */
        bool setGUI(const std::string &);

		/**
		 * Specify if the renderer is running
		 *
		 * @return true if the renderer is running
		 */
		bool run();

        /**
         * Change the background to display
         *
         * @param path Path to the bakground to display
         */
        void setBackground(const std::string &);

        /**
         * Change the background to display
         *
         * @param path Path to the bakground to display
         */
        void setBackground();

        /**
         * Specify if the state is in game
         *
         * @return The state of in game
         */
        bool isInGame() const;

        /**
         * Specify if the state is in splash screen
         *
         * @return The state of in splash screen
         */
        bool isInSplash() const;

        /**
         * End the splash screen
         */
        void endSplash();

        /**
         * Specify if the state is in game
         *
         * @return The state of in game
         */
        bool isEndSplash() const;

		/**
		 * Set the event listener
		 *
		 * @param listener Event listener
		 */
		void setEventListener(EventListener *);

		/**
		 * Render all the element on the window
		 *
		 * @param color Color of the background
		 */
		void render(const irr::video::SColor &);

		/**
		 * Return the number of connected joysticks
		 *
		 * @return The number of connected joysticks
		 */
		irr::u32 getNbJoystick() const;

		/**
		 * Stop the renderer
		 */
		void stop();

		/**
		 * Return the width of the window
		 *
		 * @return The width of the window
		 */
		size_t getWidth() const;

		/**
		 * Return the height of the window
		 *
		 * @return The height of the window
		 */
		size_t getHeight() const;

		/**
		 * Return the scene manager
		 *
		 * @return The scene manager
		 */
		SceneManager &getSceneManager();

        /**
         * Return an Irrlicht texture from the given path
         *
         * @return The texture pointing by the given path
         */
        irr::video::ITexture *getTexture(const std::string &);

        /**
         * Specify if the joyticks are enabled or not
         *
         * @return true if the joystick are enabled
         */
        bool getJoystickEnable() const;

		/**
		 * Destructor
		 */
		~Renderer();
};

#endif //RENDERER_HPP_
