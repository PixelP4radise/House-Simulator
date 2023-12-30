//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_SPRINKLER_H
#define HOUSE_SIMULATOR_SPRINKLER_H

#include "devices.h"

class sprinkler : public devices {
private:
public:
    explicit sprinkler(std::string command = "desliga");

    ~sprinkler() override = default;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_SPRINKLER_H
