//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_SENSOR_H
#define HOUSE_SIMULATOR_SENSOR_H

#include "../houseElements.h"

class sensor : public houseElements {
private:
public:

    [[nodiscard]]
    std::string getId() const override;

    [[nodiscard]]
    std::string describe() const override;

};


#endif //HOUSE_SIMULATOR_SENSOR_H
