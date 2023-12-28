//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_SMOKESENSOR_H
#define HOUSE_SIMULATOR_SMOKESENSOR_H

#include "sensor.h"

class smokeSensor : public sensor {
private:
public:
    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_SMOKESENSOR_H
