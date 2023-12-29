//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/smokeSensor.h"

smokeSensor::smokeSensor(const std::shared_ptr<property> &sharedPtr) : sensor(sharedPtr) {}

std::string smokeSensor::describe() const {
    return getId() + " Smoke Sensor " +
           std::to_string(sensor::getValue());// it needs to return the value of the property;
}