//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/equalTo.h"

equalTo::equalTo(const std::shared_ptr<sensor> &sensorPtr, int parameter1) : rule(sensorPtr, parameter1) {}

void equalTo::evaluate() {}

std::string equalTo::describe() const {
    return "equal to " + getId() + ' ' + describeSensor();
}