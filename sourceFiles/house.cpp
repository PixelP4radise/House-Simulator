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

void house::newComponent(const std::string &idRoom, char type, const std::string &command) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundRoom = *roomIt;
        if (type == 's') {
            foundRoom->addSensor(command);
        } else if (type == 'p') {
            foundRoom->addProcessor(command);
        } else if (type == 'd') {
            foundRoom->addDevice(command);
        } else {
            throw invalidDeviceType();
        }
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    } catch (const invalidDeviceType &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::removeComponent(const std::string &idRoom, char type, const std::string &idComponent) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundRoom = *roomIt;
        if (type == 's')
            foundRoom->removeSensor(idComponent);
        else if (type == 'p')
            foundRoom->removeProcessor(idComponent);
        else if (type == 'd')
            foundRoom->removeDevice(idComponent);
        else
            throw invalidDeviceType();
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    } catch (const invalidDeviceType &ex) {
        std::cout << ex.what() << std::endl;
    }
}

std::string house::describeRoom(const std::string &idRoom) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundRoom = *roomIt;
        return foundRoom->describe();
    } catch (const roomNotFound &ex) {
        return ex.what();
    }
}

std::string house::showPropertysOfRoom(const std::string &idRoom) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundRoom = *roomIt;
        return foundRoom->showPropertys();
    } catch (const roomNotFound &ex) {
        return ex.what();
    }
}

void
house::changePropertyOfRoom(const std::string &idRoom, const std::string &propertyTobeChanged, int valueToBe) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundRoom = *roomIt;
        foundRoom->changeProperty(propertyTobeChanged, valueToBe);
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void
house::addRule(const std::string &idRoom, const std::string &idProcessor, const std::string &idSensor,
               const std::string &type, int parameter1) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundRoom = *roomIt;
        foundRoom->addRule(idProcessor, idSensor, type, parameter1);
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void
house::addRule(const std::string &idRoom, const std::string &idProcessor, const std::string &idSensor,
               const std::string &type, int parameter1,
               int parameter2) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundRoom = *roomIt;
        foundRoom->addRule(idProcessor, idSensor, type, parameter1, parameter2);
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::removeRuleFrom(const std::string &idRoom, const std::string &idProcessor, const std::string &idRule) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundRoom = *roomIt;
        foundRoom->removeRuleFrom(idProcessor, idRule);
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void
house::changeCommand(const std::string &idRoom, const std::string &idProcessor, const std::string &newCommand) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundRoom = *roomIt;
        foundRoom->changeCommand(idProcessor, newCommand);
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::showRulesFrom(const std::string &idRoom, const std::string &idProcessor) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundRoom = *roomIt;
        foundRoom->showRulesFrom(idProcessor);
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void
house::associateDeviceToProcessor(const std::string &idRoom, const std::string &idProcessor,
                                  const std::string &idDevice) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundRoom = *roomIt;
        foundRoom->asocDeviceToProcessor(idProcessor, idDevice);
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void
house::disaDeviceFromProcessor(const std::string &idRoom, const std::string &idProcessor,
                               const std::string &idDevice) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundroom = *roomIt;
        foundroom->disaDeviceFromProcessor(idProcessor, idDevice);
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::sendCommandTo(const std::string &idRoom, const std::string &idDevice, const std::string &newCommand) const {
    try {
        auto roomIt = findRoomItByID(idRoom);
        auto &foundroom = *roomIt;
        foundroom->sendCommandTo(idDevice, newCommand);
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

std::vector<std::unique_ptr<room>>::const_iterator house::findRoomItByID(const std::string &idRoom) const {
    auto roomIt = std::find_if(houseRooms.begin(), houseRooms.end(),
                               [idRoom](const auto &obj) { return obj->getId() == idRoom; });
    if (roomIt == houseRooms.end())
        throw roomNotFound();
    return roomIt;
}

void house::saveProcessor(const std::string &idRoom, const std::string &idProcessor, const std::string &name) {
    try {
        if (processorMemory.size() > 0) {
            auto nameIt = processorMemory.find(name);
            if (nameIt != processorMemory.end())
                throw nameAlreadyExists();
        }
        auto roomIt = findRoomItByID(idRoom);
        auto &foundRoom = *roomIt;
        processorMemory[name] = foundRoom->copyProcessor(idProcessor);
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    } catch (const nameAlreadyExists &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::restoreProcessor(const std::string &name) {
    try {
        auto nameIt = processorMemory.find(name);
        if (nameIt != processorMemory.end()) {
            //if it finds the name
            auto roomToBeFound = processorMemory[name]->getRoomId();
            auto roomIt = findRoomItByID(roomToBeFound);
            //if it finds the rooms
            auto &foundRoom = *roomIt;
            foundRoom->restoreProcessor(*processorMemory[name]);
        }
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::removeProcessorFromMemory(const std::string &name) {
    try {
        auto nameIt = processorMemory.find(name);
        if (nameIt == processorMemory.end())
            throw nameNotFound();
        processorMemory.erase(nameIt);
    } catch (const nameNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::showProcessorsFromMemory() const {
    std::string description{};
    for (const auto &[key, value]: processorMemory) {
        description += key + ' ' + value->getId() + ' ' + value->getRoomId() + '\n';
    }
    std::cout << description << std::endl;
}