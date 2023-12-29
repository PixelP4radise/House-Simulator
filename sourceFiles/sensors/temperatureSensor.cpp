//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/temperatureSensor.h"

temperatureSensor::temperatureSensor(const std::shared_ptr<property> &sharedPtr) : sensor(sharedPtr) {}

std::string temperatureSensor::describe() const {
    return getId() + " Temperature Sensor " +
           std::to_string(sensor::getValue());// it needs to return the value of the property;
}