//
//  terrain.cpp
//  move
//
//  Created by maccraig on 2019-03-01.
//  Copyright © 2019 mcknzcrg. All rights reserved.
//

#include "terrain.hpp"

Terrain::Terrain(Coordinate *start, Coordinate *end):
start(*start), end(*end) { }

Terrain::~Terrain() {
    
}

Coordinate Terrain::getStart() {
    return this->start;
}

Coordinate Terrain::getEnd() {
    return this->end;
}
