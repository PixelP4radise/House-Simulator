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

std::string room::describe() const {
    std::string description{};
//    for (auto &sensor: vectorSensors) {
//        // describe sensor
//    }
//    for (auto &device: vectorDevices) {
//        // describe device
//    }
    for (auto &processor: vectorProcessors) {
        description += processor->describe();
    }
    return description;
}

void room::addProcessor(std::string command) {
    std::shared_ptr<processor> ptr = std::make_shared<processor>(std::move(command));
    vectorProcessors.push_back(std::move(ptr));
}

void room::addSensor(const std::string &property) {
    std::unique_ptr<sensor> ptr{};
    if (property == "humidity")
        ptr = std::make_unique<humiditySensor>();
    if (property == "luminosity")
        ptr = std::make_unique<luminositySensor>();
    if (property == "movement")
        ptr = std::make_unique<movementSensor>();
    if (property == "radiation")
        ptr = std::make_unique<radiationSensor>();
    if (property == "smoke")
        ptr = std::make_unique<smokeSensor>();
    if (property == "sound")
        ptr = std::make_unique<soundSensor>();
    if (property == "temperature")
        ptr = std::make_unique<temperatureSensor>();
    vectorSensors.push_back(std::move(ptr));
}
