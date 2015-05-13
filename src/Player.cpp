#include "Player.hpp"
#include "Map.hpp"
#include "SoundManager.hpp"
#include <SDL2/SDL.h>

void Player::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
    m_currentRow = 1;
}

void Player::draw(SDL_Renderer *pRenderer)
{
    GameObject::draw(pRenderer);
}

void Player::update(Map *map)
{
    if (m_ismov)
        m_currentFrame = int(((SDL_GetTicks() / 100) % 3));

    int t_x, t_y;
    t_x = m_x + m_dx;
    t_y = m_y + m_dy;
    if (map->isfree(t_x + 48, t_y + 48))
    {
        m_x = t_x;
        m_y = t_y;
    } else {
        SoundManager::Instance()->playSound("high");
    }
}

void Player::mov(int dir, int dx, int dy)
{
    m_currentRow = dir;
    m_dx = dx;
    m_dy = dy;
    m_ismov = true;
}

void Player::stop()
{
    m_dx = 0;
    m_dy = 0;
    m_ismov = false;
}
