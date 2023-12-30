//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_TEMPERATURESENSOR_H
#define HOUSE_SIMULATOR_TEMPERATURESENSOR_H

#include "sensor.h"

class temperatureSensor : public sensor {
private:
public:

    explicit temperatureSensor(const std::shared_ptr<property> &sharedPtr);

    ~temperatureSensor() override = default;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_TEMPERATURESENSOR_H
