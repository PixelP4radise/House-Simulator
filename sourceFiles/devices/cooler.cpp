//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/cooler.h"

cooler::cooler(std::string command) : devices(std::move(command)) {}

std::string cooler::describe() const {
    return getId() + " Refrigerator" + getCommand();
}