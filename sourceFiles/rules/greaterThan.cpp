//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/greaterThan.h"

greaterThan::greaterThan(const std::shared_ptr<sensor> &sensorPtr, int parameter1) : rule(sensorPtr, parameter1) {}

void greaterThan::evaluate() {}

std::string greaterThan::describe() const {
    return "Greater than " + getId() + ' ' + describeSensor();
}