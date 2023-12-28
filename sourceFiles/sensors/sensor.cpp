//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/sensors/sensor.h"

std::string sensor::getId() const {
    return "s" + getNum();
}