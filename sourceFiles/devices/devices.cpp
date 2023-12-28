//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/devices.h"

std::string devices::getId() const {
    return "d" + getNum();
}