#include "game.h"

int main(int argc, char* argv[]) {
    game g;
    g.init("Smovie",640, 480, 32, false);

    while(g.isRunning()) {
        g.handleEvents(&g);
        g.update();
        g.draw();
    }
    g.clean();
    return 0;
}
