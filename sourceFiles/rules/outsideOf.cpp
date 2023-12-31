//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/outsideOf.h"

outsideOf::outsideOf(const std::shared_ptr<sensor> &sensorPtr, int parameter1, int parameter2)
        : rule(sensorPtr, parameter1), secondParameter(parameter2) {}


outsideOf::outsideOf(const outsideOf &source) : rule(source), secondParameter(source.secondParameter) {}

std::unique_ptr<rule> outsideOf::clone() const {
    return std::make_unique<outsideOf>(*this);
}

int outsideOf::getSecondParameter() const {
    return secondParameter;
}

void outsideOf::evaluate() {
    if (getSensorValue() < getFirstParameter() or getSensorValue() > getSecondParameter())
        setState(true);
    else
        setState(false);
}

std::string outsideOf::describe() const {
    return "Outside " + getId() + ' ' + describeSensor();
}