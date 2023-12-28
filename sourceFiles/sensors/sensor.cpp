//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/sensor.h"

std::string sensor::getId() const {
    return "s" + getNum();
}

std::string sensor::describe() const {
    return getId() + " sensor ";// it needs to return the value of the property;
}