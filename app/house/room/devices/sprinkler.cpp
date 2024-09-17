//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/devices/sprinkler.h"

sprinkler::sprinkler(const std::shared_ptr<property> &humidWPtr, const std::shared_ptr<property> &vibWPtrm,
                     const std::shared_ptr<property> &smokeWPtr)
        : devices(), humidWPtr(humidWPtr), vibWPtr(vibWPtrm), smokeWPtr(smokeWPtr) {}

std::string sprinkler::describe() const {
    return getId() + " Sprinkler" + getCommand();
}

void sprinkler::carryOut() {
    auto humidityPtr = humidWPtr.lock();
    auto vibrationPtr = vibWPtr.lock();
    auto smokePtr = smokeWPtr.lock();

    if (humidityPtr and vibrationPtr and smokePtr) {
        if (getCommand() == "on") {
            if (getTicksSinceLastCommand() == 0) {
                auto humidityValue = humidityPtr->getValue();
                humidityValue += 50;
                if (humidityValue > 75)
                    humidityValue = 75;
                humidityPtr->setValue(humidityValue);
                vibrationPtr->setValue(vibrationPtr->getValue() + 100);
            }
            if (getTicksSinceLastCommand() == 1) {
                smokePtr->setValue(0);
            }
        }
        if (getCommand() == "off" and getTicksSinceLastCommand() == 5) {
            vibrationPtr->setValue(vibrationPtr->getValue() - 100);
        }
        incTicksSinceLastCommand();
    }
}