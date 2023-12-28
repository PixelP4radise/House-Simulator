//
// Created by guilh on 28/12/2023.
//

#include "../headerFiles/house.h"

house::house(unsigned int nLines, unsigned int nCollums) : nLines(nLines), nCollums(nCollums) {}

void house::newRoom(unsigned int roomNlines, unsigned int roomNCollums) {
    try {
        for (auto &room: houseRooms)
            if (room->getNLines() == roomNlines)
                if (room->getNCollums() == roomNCollums)
                    throw positionOcuppied();
        if (roomNlines > getNLines() or roomNCollums > getNCollums())
            throw invalidPosition();
        std::unique_ptr<room> ptr = std::make_unique<room>(roomNlines, roomNCollums);
        houseRooms.push_back(std::move(ptr));
    } catch (const std::bad_alloc &ex) {
        std::cout << "Couldn't allocate." << std::endl;
    } catch (const positionOcuppied &ex) {
        std::cout << ex.what() << std::endl;
    } catch (const invalidPosition &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::deleteRoom(const std::string &id) {
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

unsigned int house::getNLines() const {
    return nLines;
}

unsigned int house::getNCollums() const {
    return nCollums;
}

void house::newComponent(const std::string &id, char tipo, const std::string &command) {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it != houseRooms.end()) {
            auto &foundRoom = *it;
            if (tipo == 's') {
                foundRoom->addSensor(command);
            } else if (tipo == 'p') {
                foundRoom->addProcessor(command);
            } else if (tipo == 'd') {
                foundRoom->addDevice(command);
            } else {
                throw invalidDeviceType();
            }
        } else {
            throw roomNotFound();
        }
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    } catch (const invalidDeviceType &ex) {
        std::cout << ex.what() << std::endl;
    }
}

std::string house::describeRoom(const std::string &id) const {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it != houseRooms.end()) {
            auto &foundRoom = *it;
            return foundRoom->describe();
        } else {
            throw roomNotFound();
        }
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}
