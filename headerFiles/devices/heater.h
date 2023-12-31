//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_HEATER_H
#define HOUSE_SIMULATOR_HEATER_H

#include "devices.h"


class heater : public devices {
private:
    std::weak_ptr<temperature> tempWPtr;
    std::weak_ptr<sound> soundWPtr;
public:

    explicit heater(std::string command = "desliga");

    ~heater() override = default;

    void carryOut() override;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_HEATER_H
