#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "TextureManager.hpp"

class Game
{
    public:
        Game();
        virtual ~Game();

        bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

        void render ();
        void update ();
        void handleEvents ();
        void clean();

        bool running () { return m_bRunning; };
        
    protected:
    private:
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;

        int m_currentFrame;

        bool m_bRunning;
};

#endif
