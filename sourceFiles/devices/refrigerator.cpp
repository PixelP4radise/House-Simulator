//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/refrigerator.h"

refrigerator::refrigerator(std::string command) : devices(std::move(command)) {}

std::string refrigerator::describe() const {
    return getId() + " Refrigerator";
}