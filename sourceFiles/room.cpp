//
// Created by guilh on 28/12/2023.
//

#include "../headerFiles/room.h"

room::room(unsigned int nLines, unsigned int nCollumns, std::unique_ptr<term::Window> _window)
        : nLines(nLines), nCollums(nCollumns), window(std::move(_window)) {
    static unsigned int counter{};
    num = counter++;

    roomPropertys["temperature"] = std::make_shared<temperature>();
    roomPropertys["light"] = std::make_shared<luminosity>();
    roomPropertys["radiation"] = std::make_shared<radiation>();
    roomPropertys["vibration"] = std::make_shared<vibration>();
    roomPropertys["humidity"] = std::make_shared<humidity>();
    roomPropertys["smoke"] = std::make_shared<smoke>();
    roomPropertys["sound"] = std::make_shared<sound>();
    updateWindow();
}

std::unique_ptr<term::Window> room::getWindow() {
    return std::move(window);
}

unsigned int room::getNLines() const {
    return nLines;
}

unsigned int room::getNCollums() const {
    return nCollums;
}

std::string room::getId() const {
    return "r" + std::to_string(getNum());
}

size_t room::getNSensors() const {
    return vectorSensors.size();
}

size_t room::getNProcessors() const {
    return vectorProcessors.size();
}

size_t room::getNDevices() const {
    return vectorDevices.size();
}

std::string room::describe() const {
    std::string description{};
    for (auto &sensor: vectorSensors)
        description += sensor->describe() + '\n';
    for (auto &device: vectorDevices) {
        auto deviceDescription = device->describe();
        if (device->getCommand() == "on")
            deviceDescription[0] = 'D';
        description += deviceDescription + '\n';
    }
    for (auto &processor: vectorProcessors)
        description += processor->describe() + '\n';
    return description;
}

void room::addProcessor(std::string command) {
    std::shared_ptr<processor> ptr = std::make_shared<processor>(std::move(command), getId());
    vectorProcessors.push_back(std::move(ptr));
    updateWindow();
}

void room::removeProcessor(const std::string &idProcessor) {
    auto processorIt = findProcessorItById(idProcessor);
    vectorProcessors.erase(processorIt);
    updateWindow();
}

void room::addSensor(const std::string &property) {
    std::shared_ptr<sensor> ptr{};
    if (property == "humidity")
        ptr = std::make_shared<humiditySensor>(roomPropertys.at("humidity"));
    else if (property == "luminosity")
        ptr = std::make_shared<luminositySensor>(roomPropertys.at("light"));
    else if (property == "vibration")
        ptr = std::make_shared<movementSensor>(roomPropertys.at("vibration"));
    else if (property == "radiation")
        ptr = std::make_shared<radiationSensor>(roomPropertys.at("radiation"));
    else if (property == "smoke")
        ptr = std::make_shared<smokeSensor>(roomPropertys.at("smoke"));
    else if (property == "sound")
        ptr = std::make_shared<soundSensor>(roomPropertys.at("sound"));
    else if (property == "temperature")
        ptr = std::make_shared<temperatureSensor>(roomPropertys.at("temperature"));
    else
        throw invalidSensorType();
    vectorSensors.push_back(std::move(ptr));
    updateWindow();
}

void room::removeSensor(const std::string &idSensor) {
    auto sensorIt = findSensorItById(idSensor);
    vectorSensors.erase(sensorIt);
    updateWindow();
}

void room::addDevice(const std::string &device) {
    std::shared_ptr<devices> ptr{};
    if (device == "heater")
        ptr = std::make_shared<heater>(roomPropertys.at("temperature"), roomPropertys.at("sound"));
    else if (device == "lamp")
        ptr = std::make_shared<lamp>(roomPropertys.at("light"));
    else if (device == "cooler")
        ptr = std::make_shared<cooler>(roomPropertys.at("temperature"), roomPropertys.at("sound"));
    else if (device == "sprinkler")
        ptr = std::make_shared<sprinkler>(roomPropertys.at("humidity"), roomPropertys.at("vibration"),
                                          roomPropertys.at("smoke"));
    else
        throw invalidDeviceType();
    vectorDevices.push_back(std::move(ptr));
    updateWindow();
}

void room::removeDevice(const std::string &idDevice) {
    auto deviceIt = findDeviceItById(idDevice);
    vectorDevices.erase(deviceIt);
    updateWindow();
}

std::string room::showPropertys() const {
    std::string description{};
    for (const auto &[key, value]: roomPropertys) {
        description += key + ' ' + std::to_string(value->getValue()) + '\n';
    }
    return description;
}

void room::changeProperty(const std::string &propertyTobeChanged, int valueToBe) {
    roomPropertys.at(propertyTobeChanged)->setValue(valueToBe);
}

void
room::addRule(const std::string &idProcessor, const std::string &idSensor, const std::string &type,
              int parameter1) const {
    auto processadorIt = findProcessorItById(idProcessor);
    auto sensorIt = findSensorItById(idSensor);
    auto &processor = *processadorIt;
    auto &sensor = *sensorIt;
    processor->addRule(sensor, type, parameter1);
}

void room::addRule(const std::string &idProcessor, const std::string &idSensor, const std::string &type, int parameter1,
                   int parameter2) const {
    auto processorIt = findProcessorItById(idProcessor);
    auto sensorIt = findSensorItById(idSensor);
    auto &processor = *processorIt;
    auto &sensor = *sensorIt;
    processor->addRule(sensor, type, parameter1, parameter2);
}

void room::removeRuleFrom(const std::string &idProcessor, const std::string &idRule) const {
    auto processorIt = findProcessorItById(idProcessor);
    auto &processor = *processorIt;
    processor->removeRule(idRule);
}

void room::changeCommandFromProcessor(const std::string &idProcessor, const std::string &newCommand) const {
    auto processorIt = findProcessorItById(idProcessor);
    auto &processor = *processorIt;
    processor->setCommand(newCommand);
}

std::string room::showRulesFrom(const std::string &idProcessor) const {
    std::string description{};
    auto processorIt = findProcessorItById(idProcessor);
    auto &processor = *processorIt;
    description += processor->showRules();
    return description;
}

void room::asocDeviceToProcessor(const std::string &idProcessor, const std::string &idDevice) const {
    auto processorIt = findProcessorItById(idProcessor);
    auto deviceIt = findDeviceItById(idDevice);
    auto &processor = *processorIt;
    auto &device = *deviceIt;
    processor->associateDevice(device);
}

void room::disaDeviceFromProcessor(const std::string &idProcessor, const std::string &idDevice) const {
    auto processorIt = findProcessorItById(idProcessor);
    auto &processor = *processorIt;
    processor->disassociateDevice(idDevice);
}

void room::sendCommandToDevice(const std::string &idDevice, const std::string &newCommand) const {
    auto deviceIt = findDeviceItById(idDevice);
    auto &device = *deviceIt;
    device->setCommand(newCommand);
}

std::vector<std::shared_ptr<sensor>>::const_iterator room::findSensorItById(const std::string &idSensor) const {
    auto sensorIt = std::find_if(vectorSensors.begin(), vectorSensors.end(),
                                 [idSensor](const auto &obj) { return obj->getId() == idSensor; });
    if (sensorIt == vectorSensors.end())
        throw sensorNotFound();
    return sensorIt;
}

std::vector<std::shared_ptr<devices>>::const_iterator room::findDeviceItById(const std::string &idDevice) const {
    auto deviceIt = std::find_if(vectorDevices.begin(), vectorDevices.end(),
                                 [idDevice](const auto &obj) { return obj->getId() == idDevice; });
    if (deviceIt == vectorDevices.end())
        throw deviceNotFound();
    return deviceIt;
}

std::vector<std::shared_ptr<processor>>::const_iterator
room::findProcessorItById(const std::string &idProcessor) const {
    auto processorIt = std::find_if(vectorProcessors.begin(), vectorProcessors.end(),
                                    [idProcessor](const auto &obj) { return obj->getId() == idProcessor; });
    if (processorIt == vectorProcessors.end())
        throw processorNotFound();
    return processorIt;
}

std::unique_ptr<processor> room::copyProcessor(const std::string &idProcessor) const {
    auto processorIt = findProcessorItById(idProcessor);
    const auto &processorPtr = *processorIt;
    return std::make_unique<processor>(*processorPtr);
}

void room::restoreProcessor(const processor &toBeRestored) {
    auto processorToBeFound = toBeRestored.getId();
    try {
        auto processorIt = findProcessorItById(processorToBeFound);
        removeProcessor(processorToBeFound);
    } catch (const processorNotFound &ex) {
    }
    vectorProcessors.push_back(std::make_shared<processor>(toBeRestored));
    updateWindow();
}

void room::carryOut() const {
    for (auto &processorPtr: vectorProcessors)
        processorPtr->carryOut();
    for (auto &devicePtr: vectorDevices)
        devicePtr->carryOut();
    updateWindow();
}

void room::updateWindow() const {
    window->clear();
    std::string description{};
    description += getId() + '\n';
    for (auto &processorPtr: vectorProcessors)
        description += processorPtr->getId() + ' ';
    for (auto &devicePtr: vectorDevices) {
        auto deviceId = devicePtr->getId();
        if (devicePtr->getCommand() == "on")
            deviceId[0] = 'D';
        description += deviceId + ' ';
    }
    for (auto &sensorPtr: vectorSensors)
        description += sensorPtr->getId() + ' ';
    *window << description;
}