//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/lesserThan.h"

lesserThan::lesserThan(const std::shared_ptr<sensor> &sensorPtr, int parameter1) : rule(sensorPtr, parameter1) {}

void lesserThan::evaluate() {}

std::string lesserThan::describe() const {
    return "Less than " + getId() + ' ' + describeSensor();
}