#ifndef OBSTACLE_H 
#define OBSTACLE_H
    
#include <iostream>
#include "GameObject.hpp"

class Obstacle : public GameObject
{
    public:
        void load(int x, int y, int width, int height, std::string textureID);
        void draw(SDL_Renderer* pRenderer); 
        void update();
        void clean();
};

#endif
