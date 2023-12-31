//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/lamp.h"

lamp::lamp(const std::shared_ptr<property> &lumWPtr)
        : devices(), lumWPtr(lumWPtr) {}

std::string lamp::describe() const {
    return getId() + " Lamp " + getCommand();
}

void lamp::carryOut() {
    auto lumPtr = lumWPtr.lock();
    if (lumPtr) {
        if (getCommand() == "on") {
            if (getTicksSinceLastCommand() == 0)
                lumPtr->setValue(lumPtr->getValue() + 900);
        }
        if (getCommand() == "off") {
            if (getTicksSinceLastCommand() == 0) {
                lumPtr->setValue(lumPtr->getValue() - 900);
            }
        }
        incticksSinceLastCommand();
    }
}