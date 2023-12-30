//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/heater.h"

heater::heater(std::string command) : devices(std::move(command)) {}

std::string heater::describe() const {
    return getId() + " Heater " + getCommand();
}