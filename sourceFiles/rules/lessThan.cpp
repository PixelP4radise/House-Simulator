//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/lessThan.h"

lessThan::lessThan(const std::shared_ptr<sensor> &sensorPtr, int parameter1) : rule(sensorPtr, parameter1) {}


lessThan::lessThan(const lessThan &source) : rule(source) {}

std::unique_ptr<rule> lessThan::clone() const {
    return std::make_unique<lessThan>(*this);
}

void lessThan::evaluate() {
    if (getFirstParameter() > getSensorValue())
        setState(true);
    else
        setState(false);
}

std::string lessThan::describe() const {
    return "Less than " + getId() + ' ' + describeSensor();
}