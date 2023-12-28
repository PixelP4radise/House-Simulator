//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/movementSensor.h"

std::string movementSensor::describe() const {
    return getId() + " Movement Sensor ";// it needs to return the value of the property;
}