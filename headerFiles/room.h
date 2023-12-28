//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_ROOM_H
#define HOUSE_SIMULATOR_ROOM_H

#include <vector>
#include <memory>
#include <map>
#include "houseElements.h"
#include"./sensors/humiditySensor.h"
#include"./sensors/luminositySensor.h"
#include"./sensors/movementSensor.h"
#include"./sensors/radiationSensor.h"
#include"./sensors/smokeSensor.h"
#include"./sensors/soundSensor.h"
#include"./sensors/temperatureSensor.h"
#include "./devices/devices.h"
#include "./processor.h"
#include "./propertys/property.h"
#include "../exceptions/invalidSensorType.h"


class room : public houseElements {
private:
    unsigned int nLines, nCollums;
    std::vector<std::unique_ptr<sensor>> vectorSensors; //sensors for light, smoke, humidity, luminosity, movement, radiation, sound, temperature
    std::vector<std::shared_ptr<devices>> vectorDevices; // contains fridges, heaters, lamps, sprinklers
    std::vector<std::shared_ptr<processor>> vectorProcessors;
    std::map<std::string, std::unique_ptr<property>> roomPropertys;
public:
    room(unsigned int nLines, unsigned int nCollumns);

    [[nodiscard]]
    unsigned int getNLines() const;

    [[nodiscard]]
    unsigned int getNCollums() const;

    [[nodiscard]]
    std::string getId() const override;

    [[nodiscard]]
    std::string describe() const override;

    void addProcessor(std::string command);

    void addSensor(const std::string &property);
};


#endif //HOUSE_SIMULATOR_ROOM_H
