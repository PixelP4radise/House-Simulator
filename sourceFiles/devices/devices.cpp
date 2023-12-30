//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/devices.h"

devices::devices(std::string command) : command(std::move(command)), turnedOnFor(0) {
    static unsigned int counter{};
    num = counter++;
}

std::string devices::getId() const {
    return "d" + std::to_string(getNum());
}

std::string devices::getCommand() const {
    return command;
}

void devices::setCommand(const std::string &newCommand) {
    command = newCommand;
}