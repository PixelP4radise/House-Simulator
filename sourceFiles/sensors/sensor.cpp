//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/sensor.h"

sensor::sensor(const std::shared_ptr<property> &sharedPtr) : prop(sharedPtr) {
    static unsigned int counter{};
    num = counter++;
}

std::string sensor::getId() const {
    return "s" + std::to_string(getNum());
}

int sensor::getValue() const {
    auto sharedProp = prop.lock();
    if (sharedProp)
        return sharedProp->getValue();
    throw acessError();
}