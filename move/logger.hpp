//
//  logger.hpp
//  move
//
//  Created by maccraig on 2018-12-15.
//  Copyright © 2018 mcknzcrg. All rights reserved.
//

#include <stdio.h>
#include <iostream>

class Logger {
public:
    Logger();
    ~Logger();
    
    void info(const char* message);
    void warning(const char* message);
    void error(const char* message);
    void tick(int tick);

private:
    
};
