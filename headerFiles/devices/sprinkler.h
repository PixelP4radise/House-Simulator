//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_SPRINKLER_H
#define HOUSE_SIMULATOR_SPRINKLER_H

#include "devices.h"

class sprinkler : public devices {
private:
    std::weak_ptr<humidity> humidWPtr;
    std::weak_ptr<vibration> vibWPtr;
    std::weak_ptr<smoke> smokeWPtr;
public:
    explicit sprinkler(std::string command = "desliga");

    ~sprinkler() override = default;

    void carryOut() override;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_SPRINKLER_H
