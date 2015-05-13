#ifndef NOVA_H
#define NOVA_H

#include "GameObject.hpp"

class Nova : public GameObject
{
public:
    void load(int x, int y, int width, int height, std::string textureID);

    void draw(SDL_Renderer *pRenderer);

    void update();

    void clean();

private:
    int m_currentIndex;
};

#endif
