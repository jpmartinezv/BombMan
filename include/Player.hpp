#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "GameObject.hpp"

class Player : public GameObject
{
public:
    void load(int x, int y, int width, int height, std::string textureID);

    void draw(SDL_Renderer *pRenderer);

    void update();

    void clean();

    void mov(int dir, int dx, int dy);

    void stop();

private:
    bool m_ismov = false;

    int m_dx = 0;
    int m_dy = 0;
};

#endif
