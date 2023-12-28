//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/temperatureSensor.h"

std::string temperatureSensor::describe() const {
    return getId() + " Temperature Sensor ";// it needs to return the value of the property;
}