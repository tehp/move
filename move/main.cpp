//
//  main.cpp
//  move
//
//  Created by maccraig on 2018-12-15.
//  Copyright © 2018 mcknzcrg. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>

#include "game.hpp"
#include "logger.hpp"

using namespace std;


int main() {
    Game *game = new Game();
    
    game->init("move", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 700, false);
    
    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }
    
    game->clean();
    
    return 0;
}
