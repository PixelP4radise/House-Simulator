//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/lamp.h"

lamp::lamp(std::string command) : devices(std::move(command)) {}

std::string lamp::describe() const {
    return getId() + " Lamp";
}