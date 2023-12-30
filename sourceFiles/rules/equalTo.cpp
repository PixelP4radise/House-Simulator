//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/equalTo.h"

equalTo::equalTo(const std::shared_ptr<sensor> &sensorPtr, int parameter1) : rule(sensorPtr, parameter1) {}

equalTo::equalTo(const equalTo &source) : rule(source) {}

std::unique_ptr<rule> equalTo::clone() const {
    return std::make_unique<equalTo>(*this);
}

void equalTo::evaluate() {
    if (getFirstParameter() == getSensorValue())
        setState(true);
    setState(false);
}

std::string equalTo::describe() const {
    return "equal to " + getId() + ' ' + describeSensor();
}