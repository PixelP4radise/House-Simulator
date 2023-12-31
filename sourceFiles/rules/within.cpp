//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/within.h"

within::within(const std::shared_ptr<sensor> &sensorPtr, int parameter1, int parameter2)
        : rule(sensorPtr, parameter1), secondParameter(parameter2) {}

std::unique_ptr<rule> within::clone() const {
    return std::make_unique<within>(*this);
}

int within::getSecondParameter() const {
    return secondParameter;
}

void within::evaluate() {
    if (getSensorValue() > getFirstParameter() and getSensorValue() < getSecondParameter())
        setState(true);
    else
        setState(false);
}

std::string within::describe() const {
    return "In between " + getId() + ' ' + describeSensor();
}