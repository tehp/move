//
//  coordinate.hpp
//  move
//
//  Created by maccraig on 2019-03-01.
//  Copyright © 2019 mcknzcrg. All rights reserved.
//

#ifndef coordinate_hpp
#define coordinate_hpp

#include <stdio.h>

#endif /* coordinate_hpp */

class Coordinate {
public:
    Coordinate(int x, int y);
    ~Coordinate();
    int getX();
    int getY();
    
private:
    int x;
    int y;
};
