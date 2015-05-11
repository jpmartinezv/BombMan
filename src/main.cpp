#include <SDL2/SDL.h>
#include <iostream>
#include "Game.hpp"

Game* g_game;

int main(int argc, char* argv[])
{
	g_game = new Game();
	g_game->init("BombMan", 100, 100, 1280, 960, SDL_WINDOW_FULLSCREEN);
	//g_game->init("BombMan", 100, 100, 1280, 960, 0);
	
	while(g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();

		SDL_Delay(10);
	}
	g_game->clean();
	return 0;
}
