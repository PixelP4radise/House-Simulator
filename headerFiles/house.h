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

    void newComponent(const std::string &idRoom, char type, const std::string &command) const;

    void removeComponent(const std::string &idRoom, char type, const std::string &idComponent) const;

    [[nodiscard]]
    std::string describeRoom(const std::string &idRoom) const;

    [[nodiscard]]
    std::string showPropertysOfRoom(const std::string &idRoom) const;

    void changePropertyOfRoom(const std::string &idRoom, const std::string &propertyTobeChanged, int valueToBe) const;

    void
    addRule(const std::string &idRoom, const std::string &idProcessor, const std::string &idSensor,
            const std::string &type,
            int parameter1) const;

    void
    addRule(const std::string &idRoom, const std::string &idProcessor, const std::string &idSensor,
            const std::string &type,
            int parameter1,
            int parameter2) const;

    void removeRuleFrom(const std::string &idRoom, const std::string &idProcessor, const std::string &idRule) const;


    void changeCommand(const std::string &idRoom, const std::string &idProcessor, const std::string &newCommand) const;

    void showRulesFrom(const std::string &idRoom, const std::string &idProcessor) const;

    void
    associateDeviceToProcessor(const std::string &idRoom, const std::string &idProcessor,
                               const std::string &idDevice) const;

    void
    disaDeviceFromProcessor(const std::string &id, const std::string &idProcessor, const std::string &idDevice) const;

    void sendCommandTo(const std::string &id, const std::string &idDevice, const std::string &newCommand) const;

    [[nodiscard]]
    std::vector<std::unique_ptr<room>>::const_iterator findRoomById(const std::string &idRoom) const;
};


#endif //HOUSE_SIMULATOR_HOUSE_H