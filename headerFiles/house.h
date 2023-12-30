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
#include "../exceptions/invalidPosition.h"
#include "../exceptions/invalidDeviceType.h"

class house {
private:
    std::vector<std::unique_ptr<room>> houseRooms;
    unsigned int nLines, nCollums;
public:
    explicit house(unsigned int nLines = 2,
                   unsigned int nCollums = 2); //int are all 32 bits // size_t can vary depending on your system

    ~house() = default;

    void newRoom(unsigned int roomNlines, unsigned int roomNCollums);

    void deleteRoom(const std::string &id);

    void listRooms() const;

    [[nodiscard]]
    unsigned int getNLines() const;

    [[nodiscard]]
    unsigned int getNCollums() const;

    void newComponent(const std::string &id, char type, const std::string &command);

    void removeComponent(const std::string &idOfRoom, char type, const std::string &idOfComponent);

    [[nodiscard]]
    std::string describeRoom(const std::string &id) const;

    [[nodiscard]]
    std::string showPropertysOfRoom(const std::string &id) const;

    void changePropertyOfRoom(const std::string &id, const std::string &propertyTobeChanged, int valueToBe);

    void
    addRule(const std::string &id, const std::string &idProcessor, const std::string &idSensor, const std::string &type,
            int parameter1);

    void removeRuleFrom(const std::string &id, const std::string &idProcessor, const std::string &idRule);

    void
    addRule(const std::string &id, const std::string &idProcessor, const std::string &idSensor, const std::string &type,
            int parameter1,
            int parameter2);

    void changeCommand(const std::string &id, const std::string &idProcessor, const std::string &newCommand);

    void showRulesFrom(const std::string &id, const std::string &idProcessor);

    void associateDeviceToProcessor(const std::string &id, const std::string &idProcessor, const std::string &idDevice);

    void disaDeviceFromProcessor(const std::string &id, const std::string &idProcessor, const std::string &idDevice);

    void sendCommandTo(const std::string &id, const std::string &idDevice, const std::string &newCommand);
};


#endif //HOUSE_SIMULATOR_HOUSE_H