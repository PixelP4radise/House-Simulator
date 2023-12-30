//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_RADIATIONSENSOR_H
#define HOUSE_SIMULATOR_RADIATIONSENSOR_H

#include "sensor.h"

class radiationSensor : public sensor {
private:
public:
    explicit radiationSensor(const std::shared_ptr<property> &sharedPtr);

    ~radiationSensor() override = default;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_RADIATIONSENSOR_H
