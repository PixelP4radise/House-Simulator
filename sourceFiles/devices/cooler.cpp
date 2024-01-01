//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/cooler.h"

cooler::cooler(const std::shared_ptr<property> &tempWPtr, const std::shared_ptr<property> &soundWPtr)
        : devices(), tempWPtr(tempWPtr), soundWPtr(soundWPtr) {}

std::string cooler::describe() const {
    return getId() + " Refrigerator" + getCommand();
}

void cooler::carryOut() {
    auto tempPtr = tempWPtr.lock();
    auto soundPtr = soundWPtr.lock();

    if (tempPtr and soundPtr) {
        if (getCommand() == "on") {
            if (getTicksSinceLastCommand() == 0)
                soundPtr->setValue(soundPtr->getValue() + 20);
            if (getTicksSinceLastCommand() % 3 == 0)
                tempPtr->setValue(tempPtr->getValue() + 1);
        } else if (getCommand() == "off") {
            if (getTicksSinceLastCommand() == 0) {
                soundPtr->setValue(soundPtr->getValue() - 20);
            }
        }
        incTicksSinceLastCommand();
    }
}