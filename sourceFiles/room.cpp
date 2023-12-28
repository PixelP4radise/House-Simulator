//
// Created by guilh on 28/12/2023.
//

#include "../headerFiles/room.h"

room::room(unsigned int nLines, unsigned int nCollumns) : nLines(nLines), nCollums(nCollumns) {}

unsigned int room::getNLines() const {
    return nLines;
}

unsigned int room::getNCollums() const {
    return nCollums;
}

std::string room::getId() const {
    return "r" + getNum();
}