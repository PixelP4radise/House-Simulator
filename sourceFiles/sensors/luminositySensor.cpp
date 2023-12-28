//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/luminositySensor.h"

std::string luminositySensor::describe() const {
    return getId() + " Luminosity Sensor ";// it needs to return the value of the property;
}