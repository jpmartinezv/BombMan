#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

#include "Map.hpp"

Map::Map(int width, int height)
{
	// Matrix map
	m_matrix.resize(width);
	for (int i = 0; i < width; ++i)
		m_matrix[i].resize(height);

	// Matrix visited for bfs
	m_visited.resize(width);
	for (int i = 0; i < width; ++i)
		m_visited[i].resize(height);
	
	// Matrix visited for bfs
	m_dad.resize(width);
	for (int i = 0; i < width; ++i)
		m_dad[i].resize(height);

	m_width = width;
	m_height = height;
}

void Map::draw(SDL_Renderer *pRenderer)
{
    for (std::vector<GameObject *>::size_type i = 0; 
			i != m_gameObstacles.size(); i++)
    {
        m_gameObstacles[i]->draw(pRenderer);
    }
}

void Map::update()
{
    for (std::vector<GameObject *>::size_type i = 0; 
			i != m_gameObstacles.size(); i++)
    {
        m_gameObstacles[i]->update();
	}
}

bool eval(int cx, int cy, int r, int px, int py)
{
	if ((cx - px)*(cx - px) + (cy - py)*(cy - py) <= r*r - 1500)
		return true;
	return false;
}

void Map::generate_obstacles(int n)
{
	int px, py;
	int w_player = 48;
	int w_obstacle = 80;

	for (int i = 0; i < n; ++i)
	{
		Obstacle *m_obstacle = new Obstacle();

		px = rand() % m_width;
		py = rand() % m_height;

		for (int x = px - w_player; x < px + w_obstacle + w_player; ++x)
			for (int y = py - w_player; y < py + w_obstacle + w_player; ++y)
				if (x >= 0 and x < m_width and
					y >= 0 and y < m_height and
					eval( px + w_obstacle/2, py + w_obstacle/2, w_player + w_obstacle/2, x, y))
				{
					m_matrix[x][y] = 1;
				}

    	m_obstacle->load(px, py, 80, 80, "bh");
		m_gameObstacles.push_back(m_obstacle);
	}
}

bool Map::isfree(int x, int y)
{
	return m_matrix[x][y] == 0;
}

std::vector< std::pair<int, int> > Map::bfs(int sx, int sy, int ex, int ey)
{
	for (int i = 0; i < m_width; ++i)
		std::fill(m_visited[i].begin(), m_visited[i].end(), false);
	
	for (int i = 0; i < m_width; ++i)
		std::fill(m_dad[i].begin(), m_dad[i].end(), std::make_pair(-1, -1) );

	std::queue<std::pair<int, int> > Q;
	Q.push(std::make_pair(sx, sy));
	m_visited[sx][sy] = true;

	int mov_x[] = {1, 0, -1, 0};
	int mov_y[] = {0, -1, 0, 1};

	std::pair<int, int> cur;

	while (!Q.empty())
	{
		cur = Q.front();
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.first + mov_x[i];
			int ny = cur.second + mov_y[i];

			if (nx >= 0 and nx < m_width and ny >= 0 and ny < m_height and
				m_matrix[nx][ny] == 0 and m_visited[nx][ny])
			{
				m_dad[nx][ny] = cur;
				m_visited[nx][ny] = true;
				Q.push(std::make_pair(nx, ny));
			}

		}
	}

	std::vector< std::pair<int, int> > path;
	return path;
}
