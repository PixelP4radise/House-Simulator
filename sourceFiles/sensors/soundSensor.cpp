//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/soundSensor.h"

soundSensor::soundSensor(const std::shared_ptr<property> &sharedPtr) : sensor(sharedPtr) {}

std::string soundSensor::describe() const {
    return getId() + " Sound Sensor " +
           std::to_string(sensor::getValue());// it needs to return the value of the property;
}