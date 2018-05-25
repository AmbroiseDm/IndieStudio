//
// Renderer.hpp for Indie Studio in /home/lerest_m/Desktop/Programmation/C++/cpp_indie_studio/renderer/include/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Mon May 22 13:20:57 2017 Mewen Le Reste
// Last update Sat May 27 13:31:08 2017 Mewen Le Reste
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
        bool isInGame();


        /**
         * Change if the camera is lock or not
         */
        void changeCameraLock();

        /**
         * Add a node to the sceneManager
         *
         * @param type    Type of node to add
         * @param x       X position of the node
         * @param y       Y position of the node
         * @param texture Path to the texture of the new node (no texture by default)
         * @return The new generated node
         */
        irr::scene::ISceneNode *addNode(int, int, int, const std::string &texture = "");

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
         * Move the given player to the given ONSCREEN direction
         *
         * @param idx Index of the player to move
         * @param dir Onscreen direction
         * @return The direction on the map where the player move
         */
        t_dir movePlayer(int, t_dir);

		/**
		 * Destructor
		 */
		~Renderer();
};

#endif //RENDERER_HPP_
