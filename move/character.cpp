//
//  character.cpp
//  move
//
//  Created by maccraig on 2018-12-15.
//  Copyright © 2018 mcknzcrg. All rights reserved.
//

#include "character.hpp"
#include <vector>
#include <iostream>
#include "constants.hpp"

Character::Character(int x, int y, int size, int jumps):
x(x), y(y), size(size), ay(0.0), ax(0.0), jumps(jumps) { }

void Character::right() {
    if (this->x < WIDTH - size) {
        this->x += 8;
    }
}

void Character::left() {
    if (this->x > 0) {
        this->x -= 8;
    }
}

void Character::up() {
    if ((ay == 0 || jumps > 0) && ay < 3.0) {
        if (this->y < HEIGHT - size) {
            jumps--;
            this->ay = 6.0;
        }
    }
}

void Character::down() {
    if (this->y > 0) {
        this->y--;
    }
}

void Character::gravity() {
    if (ay > -10 && ay < 10) {
        ay -= 0.25;
    }
    if (ay > 0) {
        y += ay;
    }
    if (y > 0) {
        if (y + ay < 0) { // stops players going below the floor
            y = 0;
        } else {
            y += ay;
        }
    }
    if (y <= 0) {
        ay = 0.0;
        jumps = 2;
    }
}

void Character::coords() {
    std::cout << this->x << ", " << this->y << std::endl;
}

int Character::get_x() {
    return this->x;
}

int Character::get_y() {
    return this->y;
}

int Character::get_size() {
    return this->size;
}

int Character::get_jumps() {
    return this->jumps;
}
void Character::set_jumps(int jumps) {
    this->jumps = jumps;
}
