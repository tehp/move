//
//  coordinate.cpp
//  move
//
//  Created by maccraig on 2019-03-01.
//  Copyright © 2019 mcknzcrg. All rights reserved.
//

#include "coordinate.hpp"

Coordinate::Coordinate(int x, int y):
x(x), y(y) { }

Coordinate::~Coordinate() {
    
}

int Coordinate::getX() {
    return x;
}

int Coordinate::getY() {
    return y;
}
