//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_ROOM_H
#define HOUSE_SIMULATOR_ROOM_H

#include <vector>
#include <memory>
#include "houseElements.h"
#include "./sensors/sensor.h"
#include "./devices/devices.h"
#include "./processor.h"

class room : public houseElements {
private:
    unsigned int nLines, nCollums;
    std::vector<std::unique_ptr<sensor>> vectorSensors; //sensors for light, smoke, humidity, luminosity, movement, radiation, sound, temperature
    std::vector<std::shared_ptr<devices>> vectorDevices; // contains fridges, heaters, lamps, sprinklers
    std::vector<std::shared_ptr<processor>> vectorProcessors;
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
};


#endif //HOUSE_SIMULATOR_ROOM_H
