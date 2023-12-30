//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/devices.h"

devices::devices(std::string command) : command(std::move(command)), turnedOnFor(0) {}

std::string devices::getId() const {
    return "d" + getNum();
}

void devices::setCommand(const std::string &newCommand) {
    command = newCommand;
}