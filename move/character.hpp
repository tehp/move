//
//  character.hpp
//  move
//
//  Created by maccraig on 2018-12-15.
//  Copyright © 2018 mcknzcrg. All rights reserved.
//

#include <stdio.h>
#include <vector>

class Character {
public:
    Character(int x, int y, int size, int jumps);
    ~Character();
    
    void right();
    void left();
    void up();
    void down();
    
    void gravity();
    
    void coords();
    
    int get_x();
    int get_y();
    int get_size();
    
    int get_jumps();
    void set_jumps(int jumps);

    
private:
    int x;
    int y;
    int size;
    int jumps;
    
    // acceleration variables
    float ay;
    float ax;
};
