//
// Created by guilh on 28/12/2023.
//

#include "../headerFiles/room.h"

room::room(unsigned int nLines, unsigned int nCollumns) : nLines(nLines), nCollums(nCollumns) {
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
    return "r" + getNum();
}

std::string room::describe() const {
    std::string description{};
    for (auto &sensor: vectorSensors) {
        description += sensor->describe() + '\n';
    }
    for (auto &device: vectorDevices) {
        description += device->describe() + '\n';
    }
    for (auto &processor: vectorProcessors) {
        description += processor->describe() + '\n';
    }
    return description;
}

void room::addProcessor(std::string command) {
    std::shared_ptr<processor> ptr = std::make_shared<processor>(std::move(command));
    vectorProcessors.push_back(std::move(ptr));
}

void room::removeProcessor(const std::string &idOfComponent) {
    auto it = std::find_if(vectorProcessors.begin(), vectorProcessors.end(),
                           [idOfComponent](const auto &obj) { return obj->getId() == idOfComponent; });
    try {

        if (it != vectorProcessors.end())
            vectorProcessors.erase(it);
        else
            throw processorNotFound();

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

void room::removeSensor(const std::string &idOfComponent) {
    auto it = std::find_if(vectorSensors.begin(), vectorSensors.end(),
                           [idOfComponent](const auto &obj) { return obj->getId() == idOfComponent; });
    try {

        if (it != vectorSensors.end())
            vectorSensors.erase(it);
        else
            throw processorNotFound();

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
        else if (device == "refrigerator")
            ptr = std::make_shared<refrigerator>();
        else if (device == "sprinkler")
            ptr = std::make_shared<sprinkler>();
        else
            throw invalidDeviceType();
        vectorDevices.push_back(std::move(ptr));
    } catch (const invalidDeviceType &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::removeDevice(const std::string &idOfComponent) {
    auto it = std::find_if(vectorDevices.begin(), vectorDevices.end(),
                           [idOfComponent](const auto &obj) { return obj->getId() == idOfComponent; });
    try {

        if (it != vectorDevices.end())
            vectorDevices.erase(it);
        else
            throw processorNotFound();

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
room::addRule(const std::string &idProcessor, const std::string &idSensor, const std::string &type, int parameter1) {
    auto processadorIt = std::find_if(vectorProcessors.begin(), vectorProcessors.end(),
                                      [idProcessor](const auto &obj) { return obj->getId() == idProcessor; });
    auto sensorIt = std::find_if(vectorSensors.begin(), vectorSensors.end(),
                                 [idSensor](const auto &obj) { return obj->getId() == idSensor; });
    try {
        if (processadorIt != vectorProcessors.end()) {
            if (sensorIt != vectorSensors.end()) {
                auto &processor = *processadorIt;
                auto &sensor = *sensorIt;
                processor->addRule(sensor, type, parameter1);
            } else {
                throw sensorNotFound();
            }
        } else {
            throw processorNotFound();
        }
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    } catch (const sensorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::addRule(const std::string &idProcessor, const std::string &idSensor, const std::string &type, int parameter1,
                   int parameter2) {
    auto processorIt = std::find_if(vectorProcessors.begin(), vectorProcessors.end(),
                                    [idProcessor](const auto &obj) { return obj->getId() == idProcessor; });
    auto sensorIt = std::find_if(vectorSensors.begin(), vectorSensors.end(),
                                 [idSensor](const auto &obj) { return obj->getId() == idSensor; });
    try {
        if (processorIt != vectorProcessors.end()) {
            if (sensorIt != vectorSensors.end()) {
                auto &processor = *processorIt;
                auto &sensor = *sensorIt;
                processor->addRule(sensor, type, parameter1, parameter2);
            } else {
                throw sensorNotFound();
            }
        } else {
            throw processorNotFound();
        }
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    } catch (const sensorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::removeRuleFrom(const std::string &idProcessor, const std::string &idRule) {
    auto processorIt = std::find_if(vectorProcessors.begin(), vectorProcessors.end(),
                                    [idProcessor](const auto &obj) { return obj->getId() == idProcessor; });
    try {
        if (processorIt != vectorProcessors.end()) {
            auto &processor = *processorIt;
            processor->removeRule(idRule);
        } else {
            throw processorNotFound();
        }
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;

    }

}

void room::setCommand(const std::string &idProcessor, const std::string &newCommand) {
    auto processorIt = std::find_if(vectorProcessors.begin(), vectorProcessors.end(),
                                    [idProcessor](const auto &obj) { return obj->getId() == idProcessor; });
    try {
        if (processorIt != vectorProcessors.end()) {
            auto &processor = *processorIt;
            processor->setCommand(newCommand);
        } else {
            throw processorNotFound();
        }
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;

    }
}

void room::showRulesFrom(const std::string &idProcessor) {
    auto processorIt = std::find_if(vectorProcessors.begin(), vectorProcessors.end(),
                                    [idProcessor](const auto &obj) { return obj->getId() == idProcessor; });
    try {
        if (processorIt != vectorProcessors.end()) {
            auto &processor = *processorIt;
            processor->showRules();
        } else {
            throw processorNotFound();
        }
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void room::asocDeviceToProcessor(const std::string &idProcessor, const std::string &idDevice) {
    auto processorIt = std::find_if(vectorProcessors.begin(), vectorProcessors.end(),
                                    [idProcessor](const auto &obj) { return obj->getId() == idProcessor; });
    auto deviceIt = std::find_if(vectorDevices.begin(), vectorDevices.end(),
                                 [idDevice](const auto &obj) { return obj->getId() == idDevice; });
    try {
        if (processorIt == vectorProcessors.end())
            throw processorNotFound();
        if (deviceIt == vectorDevices.end())
            throw deviceNotFound();
        auto &processor = *processorIt;
        auto &device = *deviceIt;
        processor->associateDevice(device);
    } catch (const processorNotFound &ex) {
        std::cout << ex.what() << std::endl;
    } catch (const deviceNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}