//
// Created by guilh on 28/12/2023.
//

#include "../headerFiles/room.h"

room::room(unsigned int nLines, unsigned int nCollumns) : nLines(nLines), nCollums(nCollumns) {
    static unsigned int counter{};
    num = counter++;

    roomPropertys["temperature"] = std::make_shared<temperature>();
    roomPropertys["light"] = std::make_shared<luminosity>();
    roomPropertys["radiation"] = std::make_shared<radiation>();
    roomPropertys["vibration"] = std::make_shared<vibration>();
    roomPropertys["humidity"] = std::make_shared<humidity>();
    roomPropertys["smoke"] = std::make_shared<smoke>();
    roomPropertys["sound"] = std::make_shared<sound>();
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
    for (auto &device: vectorDevices)
        description += device->describe() + '\n';
    for (auto &processor: vectorProcessors)
        description += processor->describe() + '\n';
    return description;
}

void room::addProcessor(std::string command) {
    std::shared_ptr<processor> ptr = std::make_shared<processor>(std::move(command), getId());
    vectorProcessors.push_back(std::move(ptr));
}

void room::removeProcessor(const std::string &idProcessor) {
    try {
        auto processorIt = findProcessorItById(idProcessor);
        vectorProcessors.erase(processorIt);
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::addSensor(const std::string &property) {
    try {
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
    } catch (const invalidSensorType &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::removeSensor(const std::string &idSensor) {
    try {
        auto sensorIt = findSensorItById(idSensor);
        vectorSensors.erase(sensorIt);
    } catch (const processorNotFound &ex) {
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
        else if (device == "cooler")
            ptr = std::make_shared<cooler>();
        else if (device == "sprinkler")
            ptr = std::make_shared<sprinkler>();
        else
            throw invalidDeviceType();
        vectorDevices.push_back(std::move(ptr));
    } catch (const invalidDeviceType &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::removeDevice(const std::string &idDevice) {
    try {
        auto deviceIt = findDeviceItById(idDevice);
        vectorDevices.erase(deviceIt);
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
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
    try {
        auto processadorIt = findProcessorItById(idProcessor);
        auto sensorIt = findSensorItById(idSensor);
        auto &processor = *processadorIt;
        auto &sensor = *sensorIt;
        processor->addRule(sensor, type, parameter1);
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    } catch (const sensorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::addRule(const std::string &idProcessor, const std::string &idSensor, const std::string &type, int parameter1,
                   int parameter2) const {
    try {
        auto processorIt = findProcessorItById(idProcessor);
        auto sensorIt = findSensorItById(idSensor);
        auto &processor = *processorIt;
        auto &sensor = *sensorIt;
        processor->addRule(sensor, type, parameter1, parameter2);
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    } catch (const sensorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::removeRuleFrom(const std::string &idProcessor, const std::string &idRule) const {
    try {
        auto processorIt = findProcessorItById(idProcessor);
        auto &processor = *processorIt;
        processor->removeRule(idRule);
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::changeCommand(const std::string &idProcessor, const std::string &newCommand) const {
    try {
        auto processorIt = findProcessorItById(idProcessor);
        auto &processor = *processorIt;
        processor->setCommand(newCommand);
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::showRulesFrom(const std::string &idProcessor) const {
    try {
        auto processorIt = findProcessorItById(idProcessor);
        auto &processor = *processorIt;
        processor->showRules();
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::asocDeviceToProcessor(const std::string &idProcessor, const std::string &idDevice) const {
    try {
        auto processorIt = findProcessorItById(idProcessor);
        auto deviceIt = findDeviceItById(idDevice);
        auto &processor = *processorIt;
        auto &device = *deviceIt;
        processor->associateDevice(device);
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    } catch (const deviceNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::disaDeviceFromProcessor(const std::string &idProcessor, const std::string &idDevice) const {
    try {
        auto processorIt = findProcessorItById(idProcessor);
        auto &processor = *processorIt;
        processor->disassociateDevice(idDevice);
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::sendCommandTo(const std::string &idDevice, const std::string &newCommand) const {
    try {
        auto deviceIt = findDeviceItById(idDevice);
        auto &device = *deviceIt;
        device->setCommand(newCommand);
    } catch (const deviceNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
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
}