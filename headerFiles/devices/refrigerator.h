//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_REFRIGERATOR_H
#define HOUSE_SIMULATOR_REFRIGERATOR_H

#include "devices.h"

class refrigerator : public devices {
private:
public:
    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_REFRIGERATOR_H
