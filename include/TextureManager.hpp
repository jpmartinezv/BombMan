#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL.h>
#include <map>
#include <string>

class TextureManager
{
public:
    static TextureManager *Instance();

    bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer);

    void draw(std::string id, int x, int y, int width, int height,
              SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height,
                   int currentRow, int currentFrame, SDL_Renderer *pRenderer,
                   SDL_RendererFlip flip = SDL_FLIP_NONE);

protected:
private:
    TextureManager()
    { };

    TextureManager(TextureManager const &)
    { };

    TextureManager &operator=(TextureManager const &)
    { };
    static TextureManager *s_pInstance;
    std::map<std::string, SDL_Texture *> m_textureMap;
};

typedef TextureManager TheTextureManager;

#endif
