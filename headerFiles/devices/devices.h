//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_DEVICES_H
#define HOUSE_SIMULATOR_DEVICES_H

#include "../houseElements.h"

class devices : public houseElements {
private:
public:
    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_DEVICES_H
