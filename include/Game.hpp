#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game
{
    public:
        Game();
        virtual ~Game();

        bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

        void render ();
        void update () {};
        void handleEvents ();
        void clean();

        bool running () { return m_bRunning; };
        
    protected:
    private:
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;

        bool m_bRunning;
};

#endif
