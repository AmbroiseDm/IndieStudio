#include "SceneManager.hpp"

SceneManager::Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

SceneManager::Vector2D::Vector2D(const SceneManager::Vector2D &other) : x(other.x), y(other.y) {}

SceneManager::Vector2D &SceneManager::Vector2D::operator=(const SceneManager::Vector2D &other)
{
    this->x = other.x;
    this->y = other.y;
    return (*this);
}

void SceneManager::walkPlayer(int idx, t_dir direction)
{
	if (!players[idx].first)
		return ;
    if (!players[idx].second)
    {
        players[idx].second = true;
        players[idx].first->setFrameLoop(29, 59);
    }
    rotate(idx, direction);
}

inline double SceneManager::Vector2D::scal(const Vector2D &other) const
{
    return ((x * other.x) + (y * other.y));
}

SceneManager::SceneManager() : mapWidth(0), mapHeight(0), mapSize(10), flying(false) {}

void SceneManager::init(irr::IrrlichtDevice *device, irr::video::IVideoDriver *driver)
{
    this->device = device;
    this->driver = driver;
    sceneManager = device->getSceneManager();
    sky = sceneManager->addSkyBoxSceneNode(driver->getTexture(SKYBOXUP), //top
                                           driver->getTexture(SKYBOXDOWN), //bottom
                                           driver->getTexture(SKYBOXLEFT), //left
                                           driver->getTexture(SKYBOXRIGHT), //right
                                           driver->getTexture(SKYBOXFRONT), //front
                                           driver->getTexture(SKYBOXBACK)); //back
    sky->setVisible(true);
}

void SceneManager::changeCameraLock()
{
    if (!flying)
    {
        sceneManager->setActiveCamera(flyingCamera);
        flying = true;
    }
    else
    {
        sceneManager->setActiveCamera(staticCamera);
        flying = false;
    }
}

irr::scene::IMeshSceneNode *SceneManager::addCube(irr::video::ITexture *texture, const irr::f32 &size, const irr::core::vector3df &pos)
{
    irr::scene::IMeshSceneNode *cube = sceneManager->addCubeSceneNode(size, 0, -1, pos);
    cube->setMaterialTexture(0, texture);
    cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    cube->setMaterialFlag(irr::video::EMF_ANISOTROPIC_FILTER, true);
    return (cube);
}

irr::scene::IAnimatedMeshSceneNode *SceneManager::addMesh(irr::video::ITexture *texture, const std::string &path,
		const irr::core::vector3df &pos, const irr::core::vector3df &scale)
{
    irr::scene::IAnimatedMesh *mesh = sceneManager->getMesh(path.c_str());
    irr::scene::IAnimatedMeshSceneNode *animation = sceneManager->addAnimatedMeshSceneNode(mesh);
    animation->setScale(scale);
    animation->setPosition(pos);
    if (texture)
        animation->setMaterialTexture(0, texture);
    animation->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    animation->setMaterialFlag(irr::video::EMF_ANISOTROPIC_FILTER, true);
    return (animation);
}

void SceneManager::setCamera(int width, int height, int mapSize)
{
    irr::core::vector3df pos((mapSize * (height + 2)), 180 * (mapSize / 10), ((mapSize * (width + 2)) / 2));
    irr::core::vector3df target(((mapSize * (height + 2)) / 2), 0, ((mapSize * (width + 2)) / 2));

    irr::SKeyMap keyMap[5];
    keyMap[0].Action = irr::EKA_MOVE_FORWARD;
    keyMap[0].KeyCode = irr::KEY_KEY_Z;
    keyMap[1].Action = irr::EKA_MOVE_BACKWARD;
    keyMap[1].KeyCode = irr::KEY_KEY_S;
    keyMap[2].Action = irr::EKA_STRAFE_LEFT;
    keyMap[2].KeyCode = irr::KEY_KEY_Q;
    keyMap[3].Action = irr::EKA_STRAFE_RIGHT;
    keyMap[3].KeyCode = irr::KEY_KEY_D;
    keyMap[4].Action = irr::EKA_JUMP_UP;
    keyMap[4].KeyCode = irr::KEY_SPACE;
    flyingCamera = sceneManager->addCameraSceneNodeFPS(0, 100.0f, 0.1f, -1, keyMap, 5);
    staticCamera = sceneManager->addCameraSceneNode(0, pos, target);
    sceneManager->setActiveCamera(staticCamera);
    flyingCamera->setTarget(target);
    flyingCamera->setPosition(pos);
}

void SceneManager::addNode(int type, int x, int y, const std::string &texture)
{
    int pos_x = (y * mapSize) + mapSize, pos_y = (x * mapSize) + mapSize;
    switch (type)
    {
    	case 1: // ADD OBJECT DESTROYABLE TEST A DEL
    		deleteNode(x, y);
			mapEntity[y][x] = addCube(driver->getTexture(WOOD), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 2: // ADD WALL NON-DESTROYABLE TEST A DEL
    		deleteNode(x, y);
        	mapEntity[y][x] = addCube(driver->getTexture(WALL), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 3: // ADD PLAYERS TEST
        	irr::scene::IAnimatedMeshSceneNode *bomberNode;
            if (texture != "")
            	bomberNode = addMesh(driver->getTexture(texture.c_str()), PLAYER, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(7, 7, 7));
            else
            	bomberNode = addMesh(NULL, PLAYER, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(7, 7, 7));
            bomberNode->setFrameLoop(70, 90);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(bomberNode, false));
            break;
        case 4: // BOMBE
            deleteNode(x, y);
            mapEntity[y][x] = addMesh(NULL, BOMBMODEL, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(7, 7, 7));
        	break;
        case 6: // POWER UP
	         deleteNode(x, y);
    		if (texture != "")
    			mapEntity[y][x] = addMesh(driver->getTexture(texture.c_str()), POWERUPMODEL, irr::core::vector3df(pos_x, mapSize, pos_y), irr::core::vector3df(2, 2, 2));
    		else
    			mapEntity[y][x] = addMesh(NULL, POWERUPMODEL, irr::core::vector3df(pos_x, mapSize, pos_y), irr::core::vector3df(2, 2, 2));
        	break;
        case 7: // EXPLOSION CENTRE
            deleteNode(x, y);
            irr::scene::IParticleSystemSceneNode *ps;
            ps = sceneManager->addParticleSystemSceneNode(false);
            irr::scene::IParticleEmitter* em;
            em = ps->createBoxEmitter(
                    irr::core::aabbox3d<irr::f32>(-7,0,-7,7,1,7),
                    irr::core::vector3df(0.0f,0.06f,0.0f),
                    80,100,
                    irr::video::SColor(0,255,255,255),       // darkest color
                    irr::video::SColor(0,255,255,255),       // brightest color
                    200,300,0, // min and max age, angle
                    irr::core::dimension2df(10.f,10.f),         // min size
                    irr::core::dimension2df(12.f,12.f));        // max size
            ps->setEmitter(em);
            em->drop();
            irr::scene::IParticleAffector* paf;
            paf = ps->createFadeOutParticleAffector();
            ps->addAffector(paf);
            paf->drop();
            ps->setPosition(irr::core::vector3df(pos_x,mapSize,pos_y));
            ps->setScale(irr::core::vector3df(0.5,0.5,0.5));
            ps->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            ps->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
            ps->setMaterialTexture(0, driver->getTexture(FIRE));
            ps->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
            mapEntity[y][x] = ps;
            // mapEntity[y][x] = addCube(driver->getTexture(WALL_METAL_M1), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 8: // EXPLOSION LINE
            deleteNode(x, y);
            irr::scene::IParticleSystemSceneNode *ps2;
            ps2 = sceneManager->addParticleSystemSceneNode(false);
            irr::scene::IParticleEmitter* em2;
            em2 = ps2->createBoxEmitter(
                    irr::core::aabbox3d<irr::f32>(-7,0,-7,7,1,7),
                    irr::core::vector3df(0.0f,0.06f,0.0f),
                    80,100,
                    irr::video::SColor(0,255,255,255),       // darkest color
                    irr::video::SColor(0,255,255,255),       // brightest color
                    300,500,0, // min and max age, angle
                    irr::core::dimension2df(10.f,10.f),         // min size
                    irr::core::dimension2df(12.f,12.f));        // max size
            ps2->setEmitter(em2);
            em2->drop();
            irr::scene::IParticleAffector* paf2;
            paf2 = ps2->createFadeOutParticleAffector();
            ps2->addAffector(paf2);
            paf2->drop();
            ps2->setPosition(irr::core::vector3df(pos_x,mapSize,pos_y));
            ps2->setScale(irr::core::vector3df(0.5,0.5,0.5));
            ps2->setMaterialFlag(irr::video::EMF_LIGHTING, false);
            ps2->setMaterialFlag(irr::video::EMF_ZWRITE_ENABLE, false);
            ps2->setMaterialTexture(0, driver->getTexture(FIRE));
            ps2->setMaterialType(irr::video::EMT_TRANSPARENT_ADD_COLOR);
            mapEntity[y][x] = ps2;
            break;
        case 10: // M1 Non-Destroyable
            deleteNode(x, y);
            mapEntity[y][x] = addCube(driver->getTexture(FLOOR_METAL_M1), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 11: // M1 Destroyables...
            deleteNode(x, y);
            mapEntity[y][x] = addCube(driver->getTexture(BOX_METAL1_M1), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 12:
            deleteNode(x, y);
            mapEntity[y][x] = addCube(driver->getTexture(BOX_METAL2_M1), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 13:
            deleteNode(x, y);
            mapEntity[y][x] = addCube(driver->getTexture(BOX_METAL4_M1), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 14:
            deleteNode(x, y);
            mapEntity[y][x] = addMesh(NULL, BAREL_BLUE_M1, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(5, 5, 5));
            break;
        case 15:
            deleteNode(x, y);
            mapEntity[y][x] = addMesh(NULL, BAREL_SPACE_M1, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(0.4, 0.4, 0.4));
            break;
        case 16:
            deleteNode(x, y);
            world = 1;
            irr::scene::IAnimatedMeshSceneNode *artanis;
            artanis = addMesh(driver->getTexture(ARTANIS), PLAYER_ARTANIS, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(0.05, 0.05, 0.05));
            artanis->setFrameLoop(0, 29);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(artanis, false));
            break;
        case 17:
            deleteNode(x, y);
            irr::scene::IAnimatedMeshSceneNode *kerrigan;
            kerrigan = addMesh(driver->getTexture(KERRIGAN), PLAYER_KERRIGAN, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(0.05, 0.05, 0.05));
            kerrigan->setFrameLoop(0, 29);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(kerrigan, false));
            break;
        case 18:
            deleteNode(x, y);
            irr::scene::IAnimatedMeshSceneNode *reynor;
            reynor = addMesh(driver->getTexture(REYNOR), PLAYER_REYNOR, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(0.07, 0.07, 0.07));
            reynor->setFrameLoop(0, 29);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(reynor, false));
            break;
        case 19:
            deleteNode(x, y);
            irr::scene::IAnimatedMeshSceneNode *nova;
            nova = addMesh(driver->getTexture(NOVA), PLAYER_NOVA, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(0.07, 0.07, 0.07));
            nova->setFrameLoop(0, 29);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(nova, false));
            break;
        case 20: // M1 Non-Destroyable
            deleteNode(x, y);
            mapEntity[y][x] = addCube(driver->getTexture(WALL_STONE1_M2), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 21: // M1 Destroyables...
            deleteNode(x, y);
            mapEntity[y][x] = addCube(driver->getTexture(BOX_WOOD1_M2), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 22:
            deleteNode(x, y);
            mapEntity[y][x] = addCube(driver->getTexture(BOX_WOOD2_M2), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 23:
            deleteNode(x, y);
            mapEntity[y][x] = addCube(driver->getTexture(BOX_CARD_M2), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 24:
            deleteNode(x, y);
            mapEntity[y][x] = addMesh(driver->getTexture(TONNEAU_TEXT), TONNEAU_M3, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(2, 2, 2));
            break;
        case 25:
            deleteNode(x, y);
            mapEntity[y][x] = addMesh(driver->getTexture(TONNEAU_TEXT), TONNEAU_M3, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(2, 2, 2));
            break;
        case 26:
            deleteNode(x, y);
            world = 2;
            irr::scene::IAnimatedMeshSceneNode *ragnaros;
            ragnaros = addMesh(driver->getTexture(RAGNAROS), PLAYER_RAGNAROS, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(0.05, 0.05, 0.05));
            ragnaros->setFrameLoop(0, 29);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(ragnaros, false));
            break;
        case 27:
            deleteNode(x, y);
            irr::scene::IAnimatedMeshSceneNode *illidan;
            illidan = addMesh(driver->getTexture(ILLIDAN), PLAYER_ILLIDAN, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(0.07, 0.07, 0.07));
            illidan->setFrameLoop(0, 29);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(illidan, false));
            break;
        case 28:
            deleteNode(x, y);
            irr::scene::IAnimatedMeshSceneNode *sylvanas;
            sylvanas = addMesh(driver->getTexture(SYLVANAS), PLAYER_SYLVANAS, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(0.07, 0.07, 0.07));
            sylvanas->setFrameLoop(0, 29);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(sylvanas, false));
            break;
        case 29:
            deleteNode(x, y);
            irr::scene::IAnimatedMeshSceneNode *arthas;
            arthas = addMesh(driver->getTexture(ARTHAS), PLAYER_ARTHAS, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(0.05, 0.05, 0.05));
            arthas->setFrameLoop(0, 29);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(arthas, false));
            break;
        case 30: // M1 Non-Destroyable
            deleteNode(x, y);
            mapEntity[y][x] = addCube(driver->getTexture(WALL), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 31: // M1 Destroyables...
            deleteNode(x, y);
            mapEntity[y][x] = addCube(driver->getTexture(WOOD), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 32:
            deleteNode(x, y);
            mapEntity[y][x] = addCube(driver->getTexture(BOX_DARKSIDER_M3), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 33:
            deleteNode(x, y);
            mapEntity[y][x] = addCube(driver->getTexture(BOX_WOOD1_M3), mapSize, irr::core::vector3df(pos_x, mapSize, pos_y));
            break;
        case 34:
            deleteNode(x, y);
            mapEntity[y][x] = addMesh(driver->getTexture(TONNEAU_TEXT), TONNEAU_M3, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(2, 2, 2));
            break;
        case 35:
            deleteNode(x, y);
            mapEntity[y][x] = addMesh(driver->getTexture(TONNEAU_TEXT), TONNEAU_M3, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(2, 2, 2));
            break;
        case 36:
            deleteNode(x, y);
            world = 3;
            irr::scene::IAnimatedMeshSceneNode *bomber1;
            bomber1 = addMesh(driver->getTexture(PLAYERBLACKTEXTURE), PLAYER, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(7, 7, 7));
            bomber1->setFrameLoop(0, 29);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(bomber1, false));
            break;
        case 37:
            deleteNode(x, y);
            irr::scene::IAnimatedMeshSceneNode *bomber2;
            bomber2 = addMesh(driver->getTexture(PLAYERBLUETEXTURE), PLAYER, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(7, 7, 7));
            bomber2->setFrameLoop(0, 29);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(bomber2, false));
            break;
        case 38:
            deleteNode(x, y);
            irr::scene::IAnimatedMeshSceneNode *bomber3;
            bomber3 = addMesh(driver->getTexture(PLAYERGREENTEXTURE), PLAYER, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(7, 7, 7));
            bomber3->setFrameLoop(0, 29);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(bomber3, false));
            break;
        case 39:
            deleteNode(x, y);
            irr::scene::IAnimatedMeshSceneNode *bomber4;
            bomber4 = addMesh(driver->getTexture(PLAYERREDTEXTURE), PLAYER, irr::core::vector3df(pos_x, 5, pos_y), irr::core::vector3df(7, 7, 7));
            bomber4->setFrameLoop(0, 29);
            players.push_back(std::pair<irr::scene::IAnimatedMeshSceneNode *, bool>(bomber4, false));
            break;
    }
}

bool SceneManager::isInTriangle(const irr::core::vector3df &point, const irr::core::vector3df &a,
                                const irr::core::vector3df &b, const irr::core::vector3df &c)
{
    Vector2D ca(a.X - c.X, a.Z - c.Z);
    Vector2D ba(a.X - b.X, a.Z - b.Z);
    Vector2D pa(a.X - point.X, a.Z - point.Z);
    double u = (ba.scal(ba) * ca.scal(pa) - ca.scal(ba) * ba.scal(pa)) / (ca.scal(ca) * ba.scal(ba) - ca.scal(ba) * ca.scal(ba));
    double v = (ca.scal(ca) * ba.scal(pa) - ca.scal(ba) * ca.scal(pa)) / (ca.scal(ca) * ba.scal(ba) - ca.scal(ba) * ca.scal(ba));
    return (((u > 0) && (v > 0) && (u + v < 1)));
}

int SceneManager::getCameraStatus()
{
    irr::core::vector3df a(0, 0, 0);
    irr::core::vector3df b(0, 0, mapSize * (mapWidth + 2));
    irr::core::vector3df c(mapSize * (mapHeight + 2), 0, mapSize * (mapWidth + 2));
    irr::core::vector3df d(mapSize * (mapHeight + 2), 0, 0);
    irr::core::vector3df e((mapSize * (mapHeight + 2)) / 2, 0, (mapSize * (mapWidth + 2)) / 2);
    irr::core::vector3df camPos = staticCamera->getPosition();
    if (camPos.X >= (mapSize * (mapHeight + 2)) || isInTriangle(camPos, d, e, c))
        return (1);
    else if (camPos.X <= 0 || isInTriangle(camPos, a, e, b))
        return (3);
    else if (camPos.Z <= 0 || isInTriangle(camPos, a, e, d))
        return (2);
    else if (camPos.Z >= (mapSize * (mapWidth + 2)) || isInTriangle(camPos, b, e, c))
        return (4);
    return (1);
}

t_dir SceneManager::movePlayerRight()
{
    int status = getCameraStatus();
    if (status == 1)
        return (RIGHT);
    else if (status == 2)
        return (DOWN);
    else if (status == 3)
        return (LEFT);
    else
        return (UP);
}

t_dir SceneManager::movePlayerLeft()
{
    int status = getCameraStatus();
    if (status == 1)
        return (LEFT);
    else if (status == 2)
        return (UP);
    else if (status == 3)
        return (RIGHT);
    else
        return (DOWN);
}

t_dir SceneManager::movePlayerUp()
{
    int status = getCameraStatus();
    if (status == 1)
        return (UP);
    else if (status == 2)
        return (RIGHT);
    else if (status == 3)
        return (DOWN);
    else
        return (LEFT);
}

t_dir SceneManager::movePlayerDown()
{
    int status = getCameraStatus();
    if (status == 1)
        return (DOWN);
    else if (status == 2)
        return (LEFT);
    else if (status == 3)
        return (UP);
    else
        return (RIGHT);
}

t_dir SceneManager::getDiagonal(t_dir first, t_dir second)
{
    if (first == UP)
    {
        if (second == LEFT)
            return (DIAGUL);
        else
            return (DIAGUR);
    }
    else if (first == DOWN)
    {
        if (second == LEFT)
            return (DIAGDL);
        else
            return (DIAGDR);
    }
    else if (first == LEFT)
    {
        if (second == UP)
            return (DIAGUL);
        else
            return (DIAGDL);
    }
    else
    {
        if (second == UP)
            return (DIAGUR);
        else
            return (DIAGDR);
    }
}

t_dir SceneManager::movePlayerUpRight()
{
    t_dir first = movePlayerUp();
    t_dir second = movePlayerRight();
    t_dir dir = getDiagonal(first, second);
    return (dir);
}

t_dir SceneManager::movePlayerUpLeft()
{
    t_dir first = movePlayerUp();
    t_dir second = movePlayerLeft();
    t_dir dir = getDiagonal(first, second);
    return (dir);
}

t_dir SceneManager::movePlayerDownRight()
{
    t_dir first = movePlayerRight();
    t_dir second = movePlayerDown();
    t_dir dir = getDiagonal(first, second);
    return (dir);
}

t_dir SceneManager::movePlayerDownLeft()
{
    t_dir first = movePlayerLeft();
    t_dir second = movePlayerDown();
    t_dir dir = getDiagonal(first, second);
    return (dir);
}

void SceneManager::rotate(int idx, t_dir dir)
{
    float   rotation;
	if (!players[idx].first)
		return ;
    if (idx == 2 && world == 2)
        rotation = 90;
    else if (idx == 3 && world == 2)
        rotation = 260;
    else
        rotation = 0;
    irr::core::vector3df target = players[idx].first->getRotation();
    switch (dir)
    {
        case LEFT:
            target.Y = 0 + rotation;
            break ;
        case DIAGUL:
            target.Y = 45 + rotation;
            break ;
        case UP:
            target.Y = 90 + rotation;
            break ;
        case DIAGUR:
            target.Y = 135 + rotation;
            break ;
        case RIGHT:
            target.Y = 180 + rotation;
            break ;
        case DIAGDR:
            target.Y = 225 + rotation;
            break ;
        case DOWN:
            target.Y = 270 + rotation;
            break ;
        case DIAGDL:
            target.Y = 315 + rotation;
            break ;
        default:
            target.Y = rotation;
            break ;
    }
    players[idx].first->setRotation(target);
}

t_dir SceneManager::convertMove(t_dir direction)
{
    t_dir new_dir;
    switch (direction)
    {
        case UP:
            new_dir = movePlayerUp();
            break ;
        case DOWN:
            new_dir = movePlayerDown();
            break ;
        case LEFT:
            new_dir = movePlayerLeft();
            break ;
        case RIGHT:
            new_dir = movePlayerRight();
            break ;
        case DIAGUR:
            new_dir = movePlayerUpRight();
            break ;
        case DIAGUL:
            new_dir = movePlayerUpLeft();
            break ;
        case DIAGDR:
            new_dir = movePlayerDownRight();
            break ;
        case DIAGDL:
            new_dir = movePlayerDownLeft();
            break ;
        default:
            new_dir = NONE;
            break ;
    }
    return (new_dir);
}

t_dir SceneManager::movePlayer(int idx, t_dir direction)
{
    if (idx < 0 || idx >= players.size() || !players[idx].first)
        return (NONE);
    irr::core::vector3df pos = players[idx].first->getPosition();
    switch (direction)
    {
        case UP:
            pos.X -= (MOVESTEP * mapSize);
            break ;
        case DOWN:
            pos.X += (MOVESTEP * mapSize);
            break ;
        case LEFT:
            pos.Z -= (MOVESTEP * mapSize);
            break ;
        case RIGHT:
            pos.Z += (MOVESTEP * mapSize);
            break ;
        case DIAGUR:
            pos.X -= (MOVESTEP * mapSize);
            pos.Z += (MOVESTEP * mapSize);
            break ;
        case DIAGUL:
            pos.X -= (MOVESTEP * mapSize);
            pos.Z -= (MOVESTEP * mapSize);
            break ;
        case DIAGDR:
            pos.X += (MOVESTEP * mapSize);
            pos.Z += (MOVESTEP * mapSize);
            break ;
        case DIAGDL:
            pos.X += (MOVESTEP * mapSize);
            pos.Z -= (MOVESTEP * mapSize);
            break ;
        default:
            break ;
    }
    if (direction != NONE)
    {
        players[idx].first->setPosition(pos);
        if (!players[idx].second)
        {
        	players[idx].second = true;
        	players[idx].first->setFrameLoop(30, 59);
        }
        rotate(idx, direction);
    }
    else
    {
    	if (players[idx].second)
    	{
    		players[idx].second = false;
    		players[idx].first->setFrameLoop(0, 29);
    	}
    }
    return (direction);
}

void SceneManager::deleteMap()
{
    for (auto &it: cubeMap)
        it->remove();
    cubeMap.clear();
}

void SceneManager::deleteNode(int x, int y)
{
    if (mapEntity[y][x])
    {
        mapEntity[y][x]->remove();
        mapEntity[y][x] = NULL;
    }
}

void SceneManager::deleteAllNode()
{
    for (auto &heightIt: mapEntity)
    {
        for (auto &widthIt : heightIt)
        {
            if (widthIt)
                widthIt->remove();
            widthIt = NULL;
        }
    }
}

void SceneManager::deletePlayer(int idx)
{
    if (idx < 0 || idx >= players.size() || !players[idx].first)
        return ;
    players[idx].first->remove();
    players[idx].first = NULL;
}

void SceneManager::deleteAllPlayer()
{
    for (auto &it: players)
    {
    	if (it.first)
    		it.first->remove();
    }
    players.clear();
}

void SceneManager::clear()
{
    deleteMap();
    deleteAllNode();
    deleteAllPlayer();
}

void SceneManager::generateMap(const std::string &floor, const std::string &wall, int width, int height, int mapSize)
{
    irr::video::ITexture *floorTexture = driver->getTexture(floor.c_str());
    irr::video::ITexture *wallTexture = driver->getTexture(wall.c_str());
    mapEntity.resize(height);
    mapWidth = width;
    mapHeight = height;
    this->mapSize = mapSize;
    for (int y = 0; y != height; ++y)
    {
        mapEntity[y].resize(width);
        for (int x = 0; x != width; ++x)
            mapEntity[y][x] = NULL;
    }
    for (int y = 0; y != height; ++y)
    {
        for (int x = 0; x != width; ++x)
        	cubeMap.push_back(addCube(floorTexture, mapSize, irr::core::vector3df((y * mapSize) + mapSize, 0, (x * mapSize) + mapSize)));
    }
    for (int y = -1; y != (height + 1); ++y)
    {
        for (int x = -1; x != (width + 1); ++x)
        {
        	if (x == -1 || x == width || y == -1 || y == height)
        	{
        		cubeMap.push_back(addCube(wallTexture, mapSize, irr::core::vector3df((y * mapSize) + mapSize, 0, (x * mapSize) + mapSize)));
        		cubeMap.push_back(addCube(wallTexture, mapSize, irr::core::vector3df((y * mapSize) + mapSize, mapSize, (x * mapSize) + mapSize)));
        	}
        }

    }
    setCamera(width, height, mapSize);
}

bool SceneManager::isFlying()
{
    return (flying);
}

void SceneManager::render()
{
    irr::core::vector3df pos, target;
    if (flying)
    {
        pos = flyingCamera->getPosition();
        target = flyingCamera->getTarget();
        staticCamera->setPosition(pos);
        staticCamera->setTarget(target);
    }
    else
    {
        pos = staticCamera->getPosition();
        target = staticCamera->getTarget();
        flyingCamera->setPosition(pos);
        flyingCamera->setTarget(target);
    }
    sceneManager->drawAll();
    if (Debug::isDebug())
    {
        std::cout << getCameraStatus() << std::endl;
        std::cout << "Pos: x=" << pos.X << " y=" << pos.Y << " z=" << pos.Z << std::endl;
        std::cout << "Target: x=" << target.X << " y=" << target.Y << " z=" << target.Z << std::endl;
    }
}
