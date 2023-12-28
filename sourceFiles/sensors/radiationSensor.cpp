//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/radiationSensor.h"

std::string radiationSensor::describe() const {
    return getId() + " Radiation Sensor ";// it needs to return the value of the property;
}