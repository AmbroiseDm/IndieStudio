#ifndef SCENEMANAGER_HPP_
# define SCENEMANAGER_HPP_

# include <cmath>
# include <irrlicht.h>
# include <iostream>
# include <utility>
# include <vector>
# include "Debug.hpp"
# include "define.hpp"
# include "path.hpp"

class SceneManager
{
    private:
        class Vector2D
        {
            private:
                float x;
                float y;

            public:
                Vector2D(float, float);
                Vector2D(const Vector2D &);
                Vector2D &operator=(const Vector2D &);
                ~Vector2D() = default;

                double scal(const Vector2D &) const;
        };

    private:
        int mapWidth;
        int mapHeight;
        int mapSize;
        irr::video::IVideoDriver *driver;
        irr::IrrlichtDevice *device;
        irr::scene::ISceneManager *sceneManager;
        std::vector<irr::scene::IMeshSceneNode *> cubeMap;
        std::vector<std::vector<irr::scene::ISceneNode *>> mapEntity;
        std::vector<std::pair<irr::scene::ISceneNode *, bool>> players;
        irr::scene::ISceneNode *sky;
        irr::scene::ICameraSceneNode *flyingCamera;
        irr::scene::ICameraSceneNode *staticCamera;
        bool flying;

    private:
        irr::scene::IMeshSceneNode *addCube(irr::video::ITexture *, const irr::f32 &, const irr::core::vector3df &);
        irr::scene::IAnimatedMeshSceneNode *addMesh(irr::video::ITexture *, const std::string &,
        		const irr::core::vector3df &, const irr::core::vector3df &scale = {1, 1, 1});
        void setCamera(int, int, int);
        t_dir movePlayerRight();
        t_dir movePlayerLeft();
        t_dir movePlayerUp();
        t_dir movePlayerDown();
        t_dir movePlayerUpRight();
        t_dir movePlayerUpLeft();
        t_dir movePlayerDownRight();
        t_dir movePlayerDownLeft();
        t_dir getDiagonal(t_dir, t_dir);
        void rotate(int, t_dir);
        int getCameraStatus();
        bool isInTriangle(const irr::core::vector3df &, const irr::core::vector3df &, const irr::core::vector3df &, const irr::core::vector3df &);

	public:
		SceneManager();
        SceneManager(const SceneManager &) = delete;
        SceneManager &operator=(const SceneManager &) = delete;
        ~SceneManager() = default;

        /**
         * Init the SceneManager
         *
         * @param device Irrlicht device to create the ISceneManager
         * @param driver Irrlicht video driver to create all the texture
         */
        void init(irr::IrrlichtDevice *, irr::video::IVideoDriver *);

        /**
		 * Render all the element on the window
		 */
        void render();

        /**
         * Change if the camera is lock or not
         */
        void changeCameraLock();

        /**
         * Specify if the camera is free or not
         *
         * @return true if the camera is free
         */
        bool isFlying();

        /**
         * Move the given player to the given ONSCREEN direction
         *
         * @param idx Index of the player to move
         * @param dir Onscreen direction
         * @return The direction on the map where the player move
         */
        t_dir movePlayer(int, t_dir);

        /**
         * Convert the ONSCREEN direction into ON MAP direction
         *
         * @return The ON MAP direction
         */
        t_dir convertMove(t_dir);

        /**
         * Add a node to the sceneManager
         *
         * @param type    Type of node to add
         * @param x       X position of the node
         * @param y       Y position of the node
         * @param texture Path to the texture of the new node (no texture by default)
         * @return The new generated node
         */
        irr::scene::ISceneNode *addNode(int, int, int, const std::string &);

        /**
         * Delete a node from the sceneManager
         *
         * @param x X position of the node
         * @param y Y position of the node
         */
        void deleteNode(int, int);

        /**
         * Delete a palyer from the sceneManager
         *
         * @param idx Index of the player to delete
         */
        void deletePlayer(int);

        /**
         * Delete all the node from the sceneManager
         */
        void deleteAllNode();

        /**
         * Delete all the player from the sceneManager
         */
        void deleteAllPlayer();

        /**
         * Generate the map
         *
         * @param floor   Path to the floor texture
         * @param wall    Path to the wall texture
         * @param width   Width of the map
         * @param height  Height of the map
         * @param mapSize Size of one block
         */
        void generateMap(const std::string &, const std::string &, int, int, int);

        /**
         * Delete the map
         */
        void deleteMap();

        /**
         * Delete the map, all the players and all the nodes
         */
        void clear();
};

#endif //SCENEMANAGER_HPP_
