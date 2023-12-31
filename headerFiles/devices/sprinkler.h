//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_SPRINKLER_H
#define HOUSE_SIMULATOR_SPRINKLER_H

#include "devices.h"

class sprinkler : public devices {
private:
    std::weak_ptr<property> humidWPtr;
    std::weak_ptr<property> vibWPtr;
    std::weak_ptr<property> smokeWPtr;
public:
    explicit sprinkler(const std::shared_ptr<property> &humidWPtr, const std::shared_ptr<property> &vibWPtrm,
                       const std::shared_ptr<property> &smokeWPtr);

    ~sprinkler() override = default;

    void carryOut() override;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_SPRINKLER_H
