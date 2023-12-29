//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_SOUNDSENSOR_H
#define HOUSE_SIMULATOR_SOUNDSENSOR_H

#include "sensor.h"

class soundSensor : public sensor {
private:
public:
    explicit soundSensor(const std::shared_ptr<property> &sharedPtr);

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_SOUNDSENSOR_H
