//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/humiditySensor.h"

humiditySensor::humiditySensor(const std::shared_ptr<property> &sharedPtr) : sensor(sharedPtr) {}

std::string humiditySensor::describe() const {
    return getId() + " Humidity Sensor " +
           std::to_string(sensor::getValue());// it needs to return the value of the property;
}
