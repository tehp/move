//
//  terrain.hpp
//  move
//
//  Created by maccraig on 2019-03-01.
//  Copyright © 2019 mcknzcrg. All rights reserved.
//

#ifndef terrain_hpp
#define terrain_hpp

#include <stdio.h>
#include "coordinate.hpp"

#endif /* terrain_hpp */

class Terrain {
public:
    Terrain(Coordinate *start, Coordinate *end);
    ~Terrain();
    Coordinate getStart();
    Coordinate getEnd();
    
private:
    Coordinate start;
    Coordinate end;
};
