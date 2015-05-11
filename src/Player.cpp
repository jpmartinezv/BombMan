#include "Player.hpp"
#include <SDL2/SDL.h>

void Player::load(int x, int y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
	m_currentRow = 2;
}

void Player::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}

void Player::update()
{
	if ( m_ismov )
		m_currentFrame = int(((SDL_GetTicks() / 100) % 3));
	else
		m_currentFrame = 1;
	m_x += m_dx; 
	m_y += m_dy; 
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
