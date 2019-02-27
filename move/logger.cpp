//
//  logger.cpp
//  move
//
//  Created by maccraig on 2018-12-15.
//  Copyright © 2018 mcknzcrg. All rights reserved.
//

#include "logger.hpp"

Logger::Logger() {
    
}

Logger::~Logger() {
    
}

void Logger::info(const char *message) {
    std::cout << "[INFO] " << message << std::endl;
}

void Logger::warning(const char *message) {
    std::cout << "[WARN] " << message << std::endl;
}

void Logger::error(const char *message) {
    std::cout << "[ERR!] " << message << std::endl;
}

void Logger::tick(int tick) {
    std::cout << "[TICK] " << tick << std::endl;
}
