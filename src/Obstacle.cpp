#include "Obstacle.hpp"
#include <SDL2/SDL.h>

void Obstacle::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Obstacle::draw(SDL_Renderer *pRenderer)
{
    GameObject::draw(pRenderer);
}

void Obstacle::update()
{
    m_currentFrame = int(((SDL_GetTicks() / 101) % 3));
}
