//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/movementSensor.h"

movementSensor::movementSensor(const std::shared_ptr<property> &sharedPtr) : sensor(sharedPtr) {}

std::string movementSensor::describe() const {
    return getId() + " Movement Sensor " +
           std::to_string(sensor::getValue());// it needs to return the value of the property;
}