//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/within.h"

within::within(const std::shared_ptr<sensor> &sensorPtr, int parameter1, int parameter2)
        : rule(sensorPtr, parameter1), secondParameter(parameter2) {}

void within::evaluate() {}

std::string within::describe() const {
    return "In between " + getId() + ' ' + describeSensor();
}