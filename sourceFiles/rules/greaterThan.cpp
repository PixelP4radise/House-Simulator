//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/greaterThan.h"

greaterThan::greaterThan(const std::shared_ptr<sensor> &sensorPtr, int parameter1) : rule(sensorPtr, parameter1) {}


greaterThan::greaterThan(const greaterThan &source) : rule(source) {}

std::unique_ptr<rule> greaterThan::clone() const {
    return std::make_unique<greaterThan>(*this);
}

void greaterThan::evaluate() {
    if (getFirstParameter() < getSensorValue())
        setState(true);
    else
        setState(false);
}

std::string greaterThan::describe() const {
    return "Greater than " + getId() + ' ' + describeSensor();
}