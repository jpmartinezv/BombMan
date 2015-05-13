#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SDL2/SDL_mixer.h>
#include <map>
#include <string>

class SoundManager
{
public:
    static SoundManager *Instance();

    bool loadMusic(std::string fileName, std::string id);

    bool loadSound(std::string fileName, std::string id);

    void playMusic(std::string id);

    void playSound(std::string id);

protected:
private:
    SoundManager()
    { };

    SoundManager(SoundManager const&)
    { };

    SoundManager &operator=(SoundManager const&)
    { };

    static SoundManager *s_pInstance;
    std::map<std::string, Mix_Chunk *> m_soundGame;
    std::map<std::string, Mix_Music *> m_musicGame;

};

#endif
