//
// Created by guilh on 28/12/2023.
//

#include "../headerFiles/house.h"

house::house(unsigned int nLines, unsigned int nCollums) : nLines(nLines), nCollums(nCollums) {}

void house::newRoom(unsigned int nLines, unsigned int nCollums) {
    try {
        for (auto &room: houseRooms)
            if (room->getNLines() == nLines)
                if (room->getNCollums() == nCollums)
                    throw positionOcuppied();
        std::unique_ptr<room> ptr = std::make_unique<room>(nLines, nCollums);
        houseRooms.push_back(std::move(ptr));
    } catch (const std::bad_alloc &ex) {
        std::cout << "Couldn't allocate." << std::endl;
    } catch (const positionOcuppied &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::deleteRoom(std::string &id) {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it != houseRooms.end()) {
            houseRooms.erase(it);
        } else {
            throw roomNotFound();
        }
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::listRooms() const {
    for (auto &room: houseRooms) {
        std::cout << room->getId() << std::endl;
    }
}