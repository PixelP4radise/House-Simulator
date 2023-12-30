//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/rule.h"

rule::rule(const std::shared_ptr<sensor> &sensorPtr, int parameter1) : detector(sensorPtr), state(false),
                                                                       firstParameter(parameter1) {
    static unsigned int counter{};
    num = counter++;
}

std::string rule::getId() const {
    return "r" + getNum();
}

std::string rule::describeSensor() const {
    auto sensor = detector.lock();
    if (sensor)
        return sensor->describe();
    throw acessError();
}