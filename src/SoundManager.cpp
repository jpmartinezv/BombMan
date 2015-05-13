#include "SoundManager.hpp"
#include <SDL2/SDL_mixer.h>

SoundManager *SoundManager::s_pInstance = NULL;

bool SoundManager::loadMusic(std::string fileName, std::string id)
{
	Mix_Music *pTempMusic = Mix_LoadMUS(fileName.c_str());
	if (pTempMusic == NULL)
	{
		printf( "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
		return false;
	} 
	m_musicGame[id] = pTempMusic;
	return true;

}

bool SoundManager::loadSound(std::string fileName, std::string id)
{
	Mix_Chunk *pTempSound = Mix_LoadWAV(fileName.c_str());
	if (pTempSound == NULL)
	{
		printf( "Failed to load sound! SDL_mixer Error: %s\n", Mix_GetError() );
		return false;
	} 
	m_soundGame[id] = pTempSound;
	return true;
}

void SoundManager::playMusic(std::string id)
{
	Mix_PlayMusic( m_musicGame[id], -1 );
}

void SoundManager::playSound(std::string id)
{
	Mix_PlayChannel( -1, m_soundGame[id], 0 );
}

SoundManager *SoundManager::Instance()
{
	if(!s_pInstance)
	{
		s_pInstance = new SoundManager();
		return s_pInstance;
	}
	return s_pInstance;
}
