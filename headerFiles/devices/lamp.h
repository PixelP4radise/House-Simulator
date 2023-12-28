//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_LAMP_H
#define HOUSE_SIMULATOR_LAMP_H

#include "devices.h"

class lamp : public devices {
    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_LAMP_H
