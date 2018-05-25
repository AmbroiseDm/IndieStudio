//
// Created by theogalh on 14/06/17.
//

#ifndef SOUND_HPP
#define SOUND_HPP

#include <irrKlang.h>
#include <memory>
#include "path.hpp"
#include "Bomberman.hpp"

class Bomberman;

class Sound
{
private:
    bool    menu;
    irrklang::ISoundSource *m_menu;
    irrklang::ISoundSource *m_game;
    irrklang::ISoundSource *explode;
    irrklang::ISound       *music_menu;
    irrklang::ISound       *music_game;
    irrklang::ISoundEngine *engine;
    irrklang::ik_f32  volume;
    irrklang::ik_f32  exvolume;
    bool    game;

    public:
    Sound() : menu(true), game(false)
    {
        engine = irrklang::createIrrKlangDevice();
        m_menu = engine->addSoundSourceFromFile(MUSIC_MENU);
        m_game = engine->addSoundSourceFromFile(MUSIC_GAME);
        explode = engine->addSoundSourceFromFile(EXPLODE_SOUND);
        volume = 1;
        exvolume = 0;
        start_m_menu();
    }

    ~Sound()
    {
        engine->drop();
    }

    void    up_volume() {
        if (volume < 1.0) {
            volume = volume + 0.1f;
            engine->setSoundVolume(volume);
        }
    }

    void    down_volume()
    {
        if (volume > 0.0) {
            volume = volume - 0.1f;
            engine->setSoundVolume(volume);
        }
    }

    void    mute_volume()
    {
        if (engine->getSoundVolume() == volume) {
            exvolume = volume;
            volume = 0;
            engine->setSoundVolume(volume);
        }
        else
        {
            volume = exvolume;
            engine->setSoundVolume(volume);
        }
    }

    void    pause_m_menu()
    {
        engine->stopAllSounds();
    }

    void    pause_m_game()
    {
        engine->stopAllSounds();
    }

    void    start_m_menu()
    {
        music_menu = engine->play2D(m_menu, true);
    }

    void    start_m_game()
    {
        music_game = engine->play2D(m_game, true);
    }

    void    start_explode()
    {
        engine->play2D(explode, false);
    }

};

#endif //SOUND_HPP
