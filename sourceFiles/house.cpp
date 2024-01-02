//
// Created by guilh on 28/12/2023.
//

#include "../headerFiles/house.h"

house::house(unsigned int nLines, unsigned int nCollums) : nLines(nLines), nCollums(nCollums) {
    roomWindows.push_back(std::make_unique<term::Window>(62, 10, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(112, 10, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(162, 10, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(212, 10, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(62, 22, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(112, 22, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(162, 22, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(212, 22, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(62, 34, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(112, 34, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(162, 34, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(212, 34, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(62, 46, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(112, 46, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(162, 46, 25, 6, true));
    roomWindows.push_back(std::make_unique<term::Window>(212, 46, 25, 6, true));
}

void house::newRoom(unsigned int roomNlines, unsigned int roomNCollums) {
    for (auto &room: houseRooms)
        if (room->getNLines() == roomNlines)
            if (room->getNCollums() == roomNCollums)
                throw positionOcuppied();
    if (roomNlines > getNLines() or roomNCollums > getNCollums())
        throw invalidPosition();
    auto firstWindowIt = roomWindows.begin();
    auto &firstWindowPtr = *firstWindowIt;
    std::unique_ptr<room> ptr = std::make_unique<room>(roomNlines, roomNCollums, std::move(firstWindowPtr));
    roomWindows.erase(firstWindowIt);
    houseRooms.push_back(std::move(ptr));
}

void house::deleteRoom(const std::string &id) {
    auto it = findRoomItByID(id);
    auto &roomPtr = *it;
    roomWindows.push_back(roomPtr->getWindow());
    houseRooms.erase(it);
    for (auto &window: roomWindows) {
        window->clear();
    }
}

unsigned int house::getNLines() const {
    return nLines;
}

unsigned int house::getNCollums() const {
    return nCollums;
}

void house::newComponent(const std::string &idRoom, char type, const std::string &command) const {
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
}

void house::removeComponent(const std::string &idRoom, char type, const std::string &idComponent) const {
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
}

std::string house::describeRoom(const std::string &idRoom) const {
    auto roomIt = findRoomItByID(idRoom);
    auto &foundRoom = *roomIt;
    return foundRoom->describe();
}

std::string house::showPropertysOfRoom(const std::string &idRoom) const {
    auto roomIt = findRoomItByID(idRoom);
    auto &foundRoom = *roomIt;
    return foundRoom->showPropertys();
}

void
house::changePropertyOfRoom(const std::string &idRoom, const std::string &propertyTobeChanged, int valueToBe) const {
    auto roomIt = findRoomItByID(idRoom);
    auto &foundRoom = *roomIt;
    foundRoom->changeProperty(propertyTobeChanged, valueToBe);
}

void
house::addRule(const std::string &idRoom, const std::string &idProcessor, const std::string &idSensor,
               const std::string &type, int parameter1) const {
    auto roomIt = findRoomItByID(idRoom);
    auto &foundRoom = *roomIt;
    foundRoom->addRule(idProcessor, idSensor, type, parameter1);
}

void
house::addRule(const std::string &idRoom, const std::string &idProcessor, const std::string &idSensor,
               const std::string &type, int parameter1,
               int parameter2) const {
    auto roomIt = findRoomItByID(idRoom);
    auto &foundRoom = *roomIt;
    foundRoom->addRule(idProcessor, idSensor, type, parameter1, parameter2);
}

void house::removeRuleFrom(const std::string &idRoom, const std::string &idProcessor, const std::string &idRule) const {
    auto roomIt = findRoomItByID(idRoom);
    auto &foundRoom = *roomIt;
    foundRoom->removeRuleFrom(idProcessor, idRule);
}

void
house::changeCommandFromProcessor(const std::string &idRoom, const std::string &idProcessor,
                                  const std::string &newCommand) const {
    auto roomIt = findRoomItByID(idRoom);
    auto &foundRoom = *roomIt;
    foundRoom->changeCommandFromProcessor(idProcessor, newCommand);
}

std::string house::showRulesFrom(const std::string &idRoom, const std::string &idProcessor) const {
    std::string description{};
    auto roomIt = findRoomItByID(idRoom);
    auto &foundRoom = *roomIt;
    description += foundRoom->showRulesFrom(idProcessor);
    return description;
}

void
house::associateDeviceToProcessor(const std::string &idRoom, const std::string &idProcessor,
                                  const std::string &idDevice) const {
    auto roomIt = findRoomItByID(idRoom);
    auto &foundRoom = *roomIt;
    foundRoom->asocDeviceToProcessor(idProcessor, idDevice);
}

void
house::disaDeviceFromProcessor(const std::string &idRoom, const std::string &idProcessor,
                               const std::string &idDevice) const {
    auto roomIt = findRoomItByID(idRoom);
    auto &foundroom = *roomIt;
    foundroom->disaDeviceFromProcessor(idProcessor, idDevice);
}

void house::sendCommandToDevice(const std::string &idRoom, const std::string &idDevice,
                                const std::string &newCommand) const {
    auto roomIt = findRoomItByID(idRoom);
    auto &foundroom = *roomIt;
    foundroom->sendCommandToDevice(idDevice, newCommand);
}

std::vector<std::unique_ptr<room>>::const_iterator house::findRoomItByID(const std::string &idRoom) const {
    auto roomIt = std::find_if(houseRooms.begin(), houseRooms.end(),
                               [idRoom](const auto &obj) { return obj->getId() == idRoom; });
    if (roomIt == houseRooms.end())
        throw roomNotFound();
    return roomIt;
}

void house::saveProcessor(const std::string &idRoom, const std::string &idProcessor, const std::string &name) {
    if (!processorMemory.empty()) {
        auto nameIt = processorMemory.find(name);
        if (nameIt != processorMemory.end())
            throw nameAlreadyExists();
    }
    auto roomIt = findRoomItByID(idRoom);
    auto &foundRoom = *roomIt;
    processorMemory[name] = foundRoom->copyProcessor(idProcessor);
}

void house::restoreProcessor(const std::string &name) {
    auto nameIt = processorMemory.find(name);
    if (nameIt != processorMemory.end()) {
        //if it finds the name
        auto roomToBeFound = processorMemory[name]->getRoomId();
        auto roomIt = findRoomItByID(roomToBeFound);
        //if it finds the rooms
        auto &foundRoom = *roomIt;
        foundRoom->restoreProcessor(*processorMemory[name]);
    }
}

void house::removeProcessorFromMemory(const std::string &name) {
    auto nameIt = processorMemory.find(name);
    if (nameIt == processorMemory.end())
        throw nameNotFound();
    processorMemory.erase(nameIt);
}

std::string house::showProcessorsFromMemory() const {
    std::string description{};
    for (const auto &[key, value]: processorMemory) {
        description += key + ' ' + value->getId() + ' ' + value->getRoomId() + '\n';
    }
    return description;
}

std::string house::describeHouse() const {
    std::string description{};
    for (const auto &roomPtr: houseRooms) {
        description +=
                roomPtr->getId() + ' ' + std::to_string(roomPtr->getNSensors()) + ' ' +
                std::to_string(roomPtr->getNProcessors()) + ' ' +
                std::to_string(roomPtr->getNDevices()) + '\n';
    }
    return description;
}

void house::carryOut() const {
    for (auto &roomPtr: houseRooms)
        roomPtr->carryOut();
}