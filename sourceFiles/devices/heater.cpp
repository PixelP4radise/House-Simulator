//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/heater.h"

heater::heater(std::string command) : devices(std::move(command)) {}

std::string heater::describe() const {
    return getId() + " Heater " + getCommand();
}

void heater::carryOut() {
    auto tempPtr = tempWPtr.lock();
    auto soundPtr = soundWPtr.lock();

    if (tempPtr and soundPtr) {
        if (getCommand() == "on") {
            if (getTicksSinceLastCommand() == 0)
                soundPtr->setValue(soundPtr->getValue() + 5);
            if (getTicksSinceLastCommand() % 3 == 0) {
                auto temperatureValue = tempPtr->getValue();
                temperatureValue++;
                if (temperatureValue > 50)
                    temperatureValue = 50;
                tempPtr->setValue(temperatureValue);
            }
        }
        if (getCommand() == "off") {
            if (getTicksSinceLastCommand() == 0)
                soundPtr->setValue(soundPtr->getValue() - 5);
        }
        incticksSinceLastCommand();
    }
}