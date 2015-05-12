#ifndef MAP_H
#define MAP_H

#include <vector>

#include <SDL2/SDL.h>
#include "Obstacle.hpp"
#include "GameObject.hpp"

class Map
{
public:
    Map(int width, int height);

    void draw(SDL_Renderer *pRenderer);

    void update();

    void generate_obstacles(int n);
    
    bool isfree(int x, int y);
    
    std::vector< std::pair<int, int> > bfs(int sx, int sy, int ex, int ey);

protected:
    int m_width;
    int m_height;

    std::vector< std::vector<int> > m_matrix;
    std::vector< GameObject* > m_gameObstacles;

    std::vector< std::vector<bool> > m_visited;
    std::vector< std::vector<std::pair<int,int> > > m_dad;
};

#endif
