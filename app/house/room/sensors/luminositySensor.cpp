//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/luminositySensor.h"

luminositySensor::luminositySensor(const std::shared_ptr<property> &sharedPtr) : sensor(sharedPtr) {}

std::string luminositySensor::describe() const {
    return getId() + " Luminosity Sensor " +
           std::to_string(sensor::getValue());// it needs to return the value of the property;
}