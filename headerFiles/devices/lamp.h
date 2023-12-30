//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_LAMP_H
#define HOUSE_SIMULATOR_LAMP_H

#include "devices.h"

class lamp : public devices {
private:
public:
    explicit lamp(std::string command = "desliga");

    ~lamp() override = default;


    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_LAMP_H
