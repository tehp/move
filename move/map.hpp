//
//  map.hpp
//  move
//
//  Created by maccraig on 2019-03-01.
//  Copyright © 2019 mcknzcrg. All rights reserved.
//

#ifndef map_hpp
#define map_hpp

#include <stdio.h>
#include "terrain.hpp"
#include <list>

#endif /* map_hpp */

class Map {
public:
    Map();
    ~Map();
    void addTerrain(Terrain *terrain);
    std::list<Terrain*> getTerrain();
    
private:
    std::list<Terrain*> terrain;
};
