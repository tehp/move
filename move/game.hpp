//
//  game.hpp
//  move
//
//  Created by maccraig on 2018-12-15.
//  Copyright © 2018 mcknzcrg. All rights reserved.
//

#include "SDL2/SDL.h"
#include <iostream>
#include "map.hpp"

class Game {
public:
    Game();
    ~Game();
    
    void init(const char* title, int x, int y, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running() {
        return isRunning;
    }
    
private:
    int ticks;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    Map *map;
};
