//
//  map.cpp
//  move
//
//  Created by maccraig on 2019-03-01.
//  Copyright © 2019 mcknzcrg. All rights reserved.
//

#include "map.hpp"

Map::Map() {
    this->terrain = {};
}

Map::~Map() {
    
}

void Map::addTerrain(Terrain *terrain) {
    this->terrain.push_back(terrain);
}

std::list<Terrain*> Map::getTerrain() {
    return this->terrain;
}
