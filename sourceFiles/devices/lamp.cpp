//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/lamp.h"

lamp::lamp(std::string command) : devices(std::move(command)) {}

std::string lamp::describe() const {
    return getId() + " Lamp " + getCommand();
}

void lamp::carryOut() {
    auto lumPtr = lumWPtr.lock();
    if (lumPtr) {
        if (getCommand() == "on") {
            lumPtr->setValue(lumPtr->getValue() + 900);
        }
        if (getCommand() == "off") {
            if (getTicksSinceLastCommand() == 0) {
                lumPtr->setValue(lumPtr->getValue() + 900);
            }
        }
        incticksSinceLastCommand();
    }
}