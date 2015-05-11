#include "Game.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
    // attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success" << std::endl;
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        // window init success
        if(m_pWindow != 0)
        {
            std::cout << "window creation success" << std::endl;
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            // renderer init success
            if(m_pRenderer != 0) 
            {
                std::cout << "renderer creation success" << std::endl;
                SDL_SetRenderDrawColor(m_pRenderer, 255,255,255,255);
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
    }
    else
    {
        std::cout << "SDL init fail" << std::endl;
        return false; // SDL init fail
    }
    std::cout << "init success" << std::endl;
    m_bRunning = true;// everything inited successfully, start the main loop


    // LOAD IMG
    if(!TextureManager::Instance()->load("assets/monster.png", "animate", m_pRenderer))
    {
        return false;
    }
    
    if(!TextureManager::Instance()->load("assets/bh.png", "bh", m_pRenderer))
    {
        return false;
    }
    m_player = new Player();
    m_player->load(300, 300, 96, 96, "animate");
    
    m_obstacle = new Obstacle();
    m_obstacle->load(400, 400, 80, 80, "bh");

    m_gameObstacles.push_back(m_obstacle);
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color

    m_player->draw(m_pRenderer);
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObstacles.size(); i++)
    {
        m_gameObstacles[i]->draw(m_pRenderer);
    }

    SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::update()
{
    m_obstacle->update();
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObstacles.size(); i++)
    {
        m_gameObstacles[i]->update();
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){
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
