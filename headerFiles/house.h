//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_HOUSE_H
#define HOUSE_SIMULATOR_HOUSE_H

#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
#include "room.h"
#include "../exceptions/positionOcuppied.h"
#include "../exceptions/roomNotFound.h"

class house {
private:
    std::vector<std::unique_ptr<room>> houseRooms;
    unsigned int nLines, nCollums;
public:
    explicit house(unsigned int nLines = 2,
                   unsigned int nCollums = 2); //int are all 32 bits // size_t can vary depending on your system

    ~house() = default;

    void newRoom(unsigned int nLines, unsigned int nCollums);

    void deleteRoom(std::string &id);

    void listRooms() const;
};


#endif //HOUSE_SIMULATOR_HOUSE_H
