#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>
#include <SDL_ttf.h>

class game {
public:
    game();
    void init(const char* title, int width, int height, int bpp,bool fullscreen);
    bool isRunning();
    void handleEvents(game* g);
    void update();
    void draw();
    void clean();
    void quit();
private:
    bool m_bRunning;
    bool m_bFullscreen;
    SDL_Surface* screen;
    SDL_Surface* text;
    SDL_Color text_color;
    TTF_Font* font;
};

#endif
