//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/radiationSensor.h"

radiationSensor::radiationSensor(const std::shared_ptr<property> &sharedPtr) : sensor(sharedPtr) {}

std::string radiationSensor::describe() const {
    return getId() + " Radiation Sensor " +
           std::to_string(sensor::getValue());// it needs to return the value of the property;
}