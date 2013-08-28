#include "game.h"

game::game() {
}

void game::init(const char* title, int width, int height, int bpp,bool fullscreen) {
    int flags = 0;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_WM_SetCaption(title, title);

    TTF_Init();

    TTF_Font *font;
    font = TTF_OpenFont("FreeSans.tff", 24);
    SDL_Surface *text;
    SDL_Color text_color = {255, 255, 255};


    if (fullscreen) {
        flags = SDL_FULLSCREEN;
    }

    screen = SDL_SetVideoMode(width, height, bpp, flags);

    m_bFullscreen = fullscreen;

    m_bRunning = true;

}

void game::handleEvents(game* g) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                g->quit();
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        g->quit();
                        break;
                    default:
                        break;
                }
                case SDL_MOUSEMOTION:
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    break;

        }
    }
}

void game::update() {
}

void game::draw() {
    SDL_FillRect(screen, NULL, SDL_MapRGB( screen->format, 0,0,0));
    //text = TTF_RenderText_Solid(font, "TESTING THE TEXT, YER DUMMY.", text_color);
    /*text == NULL;
    if (text == NULL)
    {
        //cerr << "TTF_RenderText_Solid() Failed: " << TTF_GetError() << endl;
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }*/
    SDL_BlitSurface(text, NULL, screen, NULL);
    SDL_Flip(screen);
}

bool game::isRunning() {
    return m_bRunning;
}

void game::clean() {
    SDL_FreeSurface(screen);
    //SDL_FreeSurface(text);
    //TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}

void game::quit() {
    m_bRunning = false;
}
