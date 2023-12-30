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

void house::newComponent(const std::string &id, char type, const std::string &command) {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it != houseRooms.end()) {
            auto &foundRoom = *it;
            if (type == 's') {
                foundRoom->addSensor(command);
            } else if (type == 'p') {
                foundRoom->addProcessor(command);
            } else if (type == 'd') {
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

void house::removeComponent(const std::string &idOfRoom, char type, const std::string &idOfComponent) {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(),
                           [idOfRoom](const auto &obj) { return obj->getId() == idOfRoom; });
    try {
        if (it != houseRooms.end()) {
            auto &foundRoom = *it;
            if (type == 's')
                foundRoom->removeSensor(idOfComponent);
            else if (type == 'p')
                foundRoom->removeProcessor(idOfComponent);
            else if (type == 'd')
                foundRoom->removeDevice(idOfComponent);
            else
                throw invalidDeviceType();
        } else {
            throw roomNotFound();
        }
    } catch (const roomNotFound &ex) {
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
        return ex.what();
    }
}

std::string house::showPropertysOfRoom(const std::string &id) const {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it != houseRooms.end()) {
            auto &foundRoom = *it;
            return foundRoom->showPropertys();
        } else {
            throw roomNotFound();
        }
    } catch (const roomNotFound &ex) {
        return ex.what();
    }
}

void house::changePropertyOfRoom(const std::string &id, const std::string &propertyTobeChanged, int valueToBe) {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it != houseRooms.end()) {
            auto &foundRoom = *it;
            foundRoom->changeProperty(propertyTobeChanged, valueToBe);
        } else {
            throw roomNotFound();
        }
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void
house::addRule(const std::string &id, const std::string &idProcessor, const std::string &idSensor,
               const std::string &type, int parameter1) {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it != houseRooms.end()) {
            auto &foundRoom = *it;
            foundRoom->addRule(idProcessor, idSensor, type, parameter1);
        } else {
            throw roomNotFound();
        }
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void
house::addRule(const std::string &id, const std::string &idProcessor, const std::string &idSensor,
               const std::string &type, int parameter1,
               int parameter2) {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it != houseRooms.end()) {
            auto &foundRoom = *it;
            foundRoom->addRule(idProcessor, idSensor, type, parameter1, parameter2);
        } else {
            throw roomNotFound();
        }
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::removeRuleFrom(const std::string &id, const std::string &idProcessor, const std::string &idRule) {
    auto roomIt = std::find_if(houseRooms.begin(), houseRooms.end(),
                               [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (roomIt != houseRooms.end()) {
            auto &foundRoom = *roomIt;
            foundRoom->removeRuleFrom(idProcessor, idRule);
        } else {
            throw roomNotFound();
        }
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::changeCommand(const std::string &id, const std::string &idProcessor, const std::string &newCommand) {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it != houseRooms.end()) {
            auto &foundRoom = *it;
            foundRoom->setCommand(idProcessor, newCommand);
        } else {
            throw roomNotFound();
        }
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::showRulesFrom(const std::string &id, const std::string &idProcessor) {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it != houseRooms.end()) {
            auto &foundRoom = *it;
            foundRoom->showRulesFrom(idProcessor);
        } else {
            throw roomNotFound();
        }
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void
house::associateDeviceToProcessor(const std::string &id, const std::string &idProcessor, const std::string &idDevice) {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it != houseRooms.end()) {
            auto &foundRoom = *it;
            foundRoom->asocDeviceToProcessor(idProcessor, idDevice);
        } else {
            throw roomNotFound();
        }
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void
house::disaDeviceFromProcessor(const std::string &id, const std::string &idProcessor, const std::string &idDevice) {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it == houseRooms.end())
            throw roomNotFound();
        auto &foundroom = *it;
        foundroom->disaDeviceFromProcessor(idProcessor, idDevice);
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void house::sendCommandTo(const std::string &id, const std::string &idDevice, const std::string &newCommand) {
    auto it = std::find_if(houseRooms.begin(), houseRooms.end(), [id](const auto &obj) { return obj->getId() == id; });
    try {
        if (it == houseRooms.end())
            throw roomNotFound();
        auto &foundroom = *it;
        foundroom->sendCommandTo(idDevice, newCommand);
    } catch (const roomNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}