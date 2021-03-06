#include "Game.hpp"
#include <SDL2/SDL_mixer.h>

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags)
{
    // attempt to initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success" << std::endl;
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        // window init success
        if (m_pWindow != 0)
        {
            std::cout << "window creation success" << std::endl;
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            // renderer init success
            if (m_pRenderer != 0)
            {
                std::cout << "renderer creation success" << std::endl;
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
            }
            else
            {
                std::cout << "renderer init fail" << std::endl;
                return false; // renderer init fail
            }
        }
        else
        {
            std::cout << "window init fail" << std::endl;
            return false; // window init fail
        }
        //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            std::cout << "SDL_mixer could not initialize! SDL_mixer Error:" << Mix_GetError() << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "SDL init fail" << std::endl;
        return false; // SDL init fail
    }
    std::cout << "init success" << std::endl;
    m_bRunning = true;// everything inited successfully, start the main loop

    // LOAD MUSIC
    if (!SoundManager::Instance()->loadMusic("assets/beat.wav", "beat") )
    {
        return false;
    }
    if (!SoundManager::Instance()->loadSound("assets/high.wav", "high") )
    {
        return false;
    }
    SoundManager::Instance()->playMusic("beat");

    // LOAD IMG
    if (!TextureManager::Instance()->load("assets/monster.png", "monster", m_pRenderer))
    {
        return false;
    }

    if (!TextureManager::Instance()->load("assets/bh.png", "bh", m_pRenderer))
    {
        return false;
    }
    
    if (!TextureManager::Instance()->load("assets/supernova.png", "supernova", m_pRenderer))
    {
        return false;
    }

    m_player = new Player();
    m_player->load(100, 100, 96, 96, "monster");

    m_nova = new Nova();
    m_nova->load(width - 150, height - 150, 150, 131, "supernova");

    m_map = new Map(width, height);
    m_map->generate_obstacles(20);

    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color

    m_player->draw(m_pRenderer);
    m_nova->draw(m_pRenderer);
    m_map->draw(m_pRenderer);

    SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::update()
{
    m_player->update(m_map);
    m_nova->update();
    m_map->update();
}

void Game::handleEvents()
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        m_player->mov(2, -3, 0);
                        break;
                    case SDLK_RIGHT:
                        m_player->mov(3, 3, 0);
                        break;
                    case SDLK_UP:
                        m_player->mov(4, 0, -3);
                        break;
                    case SDLK_DOWN:
                        m_player->mov(1, 0, 3);
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                m_player->stop();
                break;
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::clean()
{
    std::cout << "cleaning game" << std::endl;
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}
