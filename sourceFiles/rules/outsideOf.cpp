//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/outsideOf.h"

outsideOf::outsideOf(const std::shared_ptr<sensor> &sensorPtr, int parameter1, int parameter2)
        : rule(sensorPtr, parameter1), secondParameter(parameter2) {}

void outsideOf::evaluate() {}

std::string outsideOf::describe() const {
    return "Outside " + getId() + ' ' + describeSensor();
}