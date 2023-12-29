//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_ROOM_H
#define HOUSE_SIMULATOR_ROOM_H

#include <vector>
#include <memory>
#include <map>
#include <algorithm>
#include "houseElements.h"
#include"./sensors/humiditySensor.h"
#include"./sensors/luminositySensor.h"
#include"./sensors/movementSensor.h"
#include"./sensors/radiationSensor.h"
#include"./sensors/smokeSensor.h"
#include"./sensors/soundSensor.h"
#include"./sensors/temperatureSensor.h"
#include "./devices/heater.h"
#include "./devices/lamp.h"
#include "./devices/refrigerator.h"
#include "./devices/sprinkler.h"
#include "./processor.h"
#include "./propertys/humidity.h"
#include "./propertys/luminosity.h"
#include "./propertys/vibration.h"
#include "./propertys/radiation.h"
#include "./propertys/smoke.h"
#include "./propertys/sound.h"
#include "./propertys/temperature.h"
#include "../exceptions/invalidSensorType.h"
#include "../exceptions/invalidDeviceType.h"
#include "../exceptions/processorNotFound.h"
#include "../exceptions/sensorNotFound.h"


class room : public houseElements {
private:
    unsigned int nLines, nCollums;
    std::vector<std::shared_ptr<sensor>> vectorSensors; //sensors for light, smoke, humidity, luminosity, vibration, radiation, sound, temperature
    std::vector<std::shared_ptr<devices>> vectorDevices; // contains fridges, heaters, lamps, sprinklers
    std::vector<std::shared_ptr<processor>> vectorProcessors;
    std::map<std::string, std::shared_ptr<property>> roomPropertys;
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

    void removeProcessor(const std::string &idOfComponent);

    void addSensor(const std::string &property);

    void removeSensor(const std::string &idOfComponent);

    void addDevice(const std::string &device);

    void removeDevice(const std::string &idOfComponent);

    [[nodiscard]]
    std::string showPropertys() const;

    void changeProperty(const std::string &propertyTobeChanged, int valueToBe);

    void addRule(const std::string &idProcessor, const std::string &idSensor, const std::string &type,
                 int parameter1);

    void addRule(const std::string &idProcessor, const std::string &idSensor, const std::string &type,
                 int parameter1, int parameter2);

    void setCommand(const std::string &idProcessor, const std::string &newCommand);

    void showRulesFrom(const std::string &idProcessor);
};


#endif //HOUSE_SIMULATOR_ROOM_H
