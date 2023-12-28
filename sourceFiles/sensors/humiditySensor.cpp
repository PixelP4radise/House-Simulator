//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/humiditySensor.h"

std::string humiditySensor::describe() const {
    return getId() + " Humidity Sensor ";// it needs to return the value of the property;
}