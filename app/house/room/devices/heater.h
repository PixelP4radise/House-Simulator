//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_HEATER_H
#define HOUSE_SIMULATOR_HEATER_H

#include "devices.h"


class heater : public devices {
private:
    std::weak_ptr<property> tempWPtr;
    std::weak_ptr<property> soundWPtr;
public:

    explicit heater(const std::shared_ptr<property> &tempWPtr, const std::shared_ptr<property> &soundWPtr);

    ~heater() override = default;

    void carryOut() override;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_HEATER_H
