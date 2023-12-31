//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_COOLER_H
#define HOUSE_SIMULATOR_COOLER_H

#include "devices.h"

class cooler : public devices {
private:
    std::weak_ptr<property> tempWPtr;
    std::weak_ptr<property> soundWPtr;
public:
    explicit cooler(const std::shared_ptr<property> &tempWPtr, const std::shared_ptr<property> &soundWPtr);

    ~cooler() override = default;

    void carryOut() override;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_COOLER_H
