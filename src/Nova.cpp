#include "Nova.hpp"
#include "Map.hpp"
#include "SoundManager.hpp"
#include <SDL2/SDL.h>

void Nova::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
    m_currentRow = 1;
}

void Nova::draw(SDL_Renderer *pRenderer)
{
    GameObject::draw(pRenderer);
}

void Nova::update()
{
    m_currentIndex = int(((SDL_GetTicks() / 100) % 9));
	m_currentFrame = m_currentIndex%3;
	m_currentRow = m_currentIndex/3 + 1;
}

void Nova::clean()
{

}
