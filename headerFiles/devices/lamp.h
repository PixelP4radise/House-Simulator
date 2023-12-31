//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_LAMP_H
#define HOUSE_SIMULATOR_LAMP_H

#include "devices.h"

class lamp : public devices {
private:
    std::weak_ptr<property> lumWPtr;
public:
    explicit lamp(const std::shared_ptr<property> &lumWPtr);

    ~lamp() override = default;

    void carryOut() override;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_LAMP_H
