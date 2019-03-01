//
//  game.cpp
//  move
//
//  Created by maccraig on 2018-12-15.
//  Copyright © 2018 mcknzcrg. All rights reserved.
//

#include "game.hpp"
#include "logger.hpp"
#include "character.hpp"
#include "constants.hpp"

Logger *logger = new Logger();
Character *character;

Game::Game() {

}

Game::~Game() {
    
}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {
    
    map = new Map();
    map->addTerrain(new Terrain(new Coordinate(300, 100), new Coordinate(500, 120)));

    int flags = 0;
    ticks = 0;
    
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        logger->info("subsystem good");
        
        window = SDL_CreateWindow(title, x, y, width, height, flags);
        if (window) {
            logger->info("window good");
        }
        
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            logger->info("renderer good");
        }
        
        isRunning = true;
    } else {
        isRunning = false;
    }
    
    character = new Character(0, 0, DEFAULT_CHARACTER_SIZE, 2);
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
    
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if(keystates[SDL_SCANCODE_W]) {
        character->up();
    }
    if(keystates[SDL_SCANCODE_A]) {
        character->left();
    }
    if(keystates[SDL_SCANCODE_S]) {
        character->down();
    }
    if(keystates[SDL_SCANCODE_D]) {
        character->right();
    }
    if(keystates[SDL_SCANCODE_SPACE]) {
        character->up();
    }
}

void Game::update() {
    ticks++;
    character->coords();
    character->gravity();
    if (character->get_x() == 0) {
        character->set_jumps(1);
    }
}

void Game::render() {
    // Background
    SDL_SetRenderDrawColor( renderer, 200, 200, 200, 255 );
    SDL_RenderClear(renderer);
    
    // Loop through pieces of terrain
    for (auto const& i : map->getTerrain()) {
        int startX = i->getStart().getX();
        int startY = HEIGHT - i->getStart().getY();
        
        int endX = i->getEnd().getX() - startX;
        int endY = HEIGHT - i->getEnd().getY() - startY;
        
        // Draw each piece of terrain
        SDL_Rect *terrain =  new SDL_Rect();
        terrain->x = startX;
        terrain->y = startY;
        terrain->w = endX;
        terrain->h = endY;
        
        SDL_SetRenderDrawColor( renderer, 255, 0, 255, 255 );
        SDL_RenderFillRect(renderer, terrain);
    }
    
    SDL_Rect *player = new SDL_Rect();
    player->x = character->get_x() - character->get_size()/2;
    player->y = HEIGHT - character->get_y() - character->get_size();
    player->w = character->get_size();
    player->h = character->get_size();
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
    SDL_RenderFillRect(renderer, player);
    
    SDL_RenderPresent(renderer);
    
    SDL_Delay(1000/60);
    
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    logger->info("cleaned");
}
