//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_ROOM_H
#define HOUSE_SIMULATOR_ROOM_H

#include <vector>
#include <memory>
#include <map>
#include <algorithm>
#include "Terminal.h"
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
#include "./devices/cooler.h"
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
#include "../exceptions/deviceNotFound.h"


class room : public houseElements {
private:
    unsigned int nLines, nCollums;
    std::unique_ptr<term::Window> window;
    std::vector<std::shared_ptr<sensor>> vectorSensors; //sensors for light, smoke, humidity, luminosity, vibration, radiation, sound, temperature
    std::vector<std::shared_ptr<devices>> vectorDevices; // contains fridges, heaters, lamps, sprinklers
    std::vector<std::shared_ptr<processor>> vectorProcessors;
    std::map<std::string, std::shared_ptr<property>> roomPropertys;
public:
    room(unsigned int nLines, unsigned int nCollumns, std::unique_ptr<term::Window> janela);

    ~room() override = default;

    [[nodiscard]]
    std::unique_ptr<term::Window> getWindow();

    void updateWindow() const;

    [[nodiscard]]
    unsigned int getNLines() const;

    [[nodiscard]]
    unsigned int getNCollums() const;

    [[nodiscard]]
    std::string getId() const override;

    [[nodiscard]]
    size_t getNSensors() const;

    [[nodiscard]]
    size_t getNProcessors() const;

    [[nodiscard]]
    size_t getNDevices() const;

    [[nodiscard]]
    std::string describe() const override;

    void addProcessor(std::string command);

    void removeProcessor(const std::string &idProcessor);

    void addSensor(const std::string &property);

    void removeSensor(const std::string &idOfComponent);

    void addDevice(const std::string &device);

    void removeDevice(const std::string &idDevice);

    [[nodiscard]]
    std::string showPropertys() const;

    void changeProperty(const std::string &propertyTobeChanged, int valueToBe);

    void addRule(const std::string &idProcessor, const std::string &idSensor, const std::string &type,
                 int parameter1) const;

    void addRule(const std::string &idProcessor, const std::string &idSensor, const std::string &type,
                 int parameter1, int parameter2) const;

    void removeRuleFrom(const std::string &idProcessor, const std::string &idRule) const;

    void changeCommandFromProcessor(const std::string &idProcessor, const std::string &newCommand) const;

    [[nodiscard]]
    std::string showRulesFrom(const std::string &idProcessor) const;

    void asocDeviceToProcessor(const std::string &idProcessor, const std::string &idDevice) const;

    void disaDeviceFromProcessor(const std::string &idProcessor, const std::string &idDevice) const;

    void sendCommandToDevice(const std::string &idDevice, const std::string &newCommand) const;

    [[nodiscard]]
    std::vector<std::shared_ptr<sensor>>::const_iterator findSensorItById(const std::string &idSensor) const;

    [[nodiscard]]
    std::vector<std::shared_ptr<devices>>::const_iterator findDeviceItById(const std::string &idDevice) const;

    [[nodiscard]]
    std::vector<std::shared_ptr<processor>>::const_iterator findProcessorItById(const std::string &idProcessor) const;

    [[nodiscard]]
    std::unique_ptr<processor> copyProcessor(const std::string &idProcessor) const;

    void restoreProcessor(const processor &toBeRestored);

    void carryOut() const;
};


#endif //HOUSE_SIMULATOR_ROOM_H
