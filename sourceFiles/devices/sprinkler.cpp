//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/sprinkler.h"

sprinkler::sprinkler(std::string command) : devices(std::move(command)) {}

std::string sprinkler::describe() const {
    return getId() + " Sprinkler";
}