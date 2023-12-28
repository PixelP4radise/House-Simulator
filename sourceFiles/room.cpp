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
    try {
        std::unique_ptr<sensor> ptr{};
        if (property == "humidity")
            ptr = std::make_unique<humiditySensor>();
        else if (property == "luminosity")
            ptr = std::make_unique<luminositySensor>();
        else if (property == "movement")
            ptr = std::make_unique<movementSensor>();
        else if (property == "radiation")
            ptr = std::make_unique<radiationSensor>();
        else if (property == "smoke")
            ptr = std::make_unique<smokeSensor>();
        else if (property == "sound")
            ptr = std::make_unique<soundSensor>();
        else if (property == "temperature")
            ptr = std::make_unique<temperatureSensor>();
        else
            throw invalidSensorType();
        vectorSensors.push_back(std::move(ptr));
    } catch (const invalidSensorType &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::addDevice(const std::string &device) {
    try {
        std::shared_ptr<devices> ptr{};
        if (device == "heater")
            ptr = std::make_shared<heater>();
        else if (device == "lamp")
            ptr = std::make_shared<lamp>();
        else if (device == "refrigerator")
            ptr = std::make_shared<refrigerator>();
        else if (device == "sprinkler")
            ptr = std::make_shared<sprinkler>();
        else
            throw invalidDeviceType();
    } catch (const invalidDeviceType &ex) {
        std::cout << ex.what() << std::endl;
    }
}
