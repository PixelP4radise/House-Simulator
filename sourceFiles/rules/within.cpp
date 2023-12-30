//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/within.h"

within::within(const std::shared_ptr<sensor> &sensorPtr, int parameter1, int parameter2)
        : rule(sensorPtr, parameter1), secondParameter(parameter2) {}

within::within(const within &source) : rule(source), secondParameter(source.secondParameter) {}

std::unique_ptr<rule> within::clone() const {
    return std::make_unique<within>(*this);
}

void within::evaluate() {}

std::string within::describe() const {
    return "In between " + getId() + ' ' + describeSensor();
}