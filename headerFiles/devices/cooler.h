//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_COOLER_H
#define HOUSE_SIMULATOR_COOLER_H

#include "devices.h"

class cooler : public devices {
private:
    std::weak_ptr<temperature> tempWPtr;
    std::weak_ptr<sound> soundWPtr;
public:
    explicit cooler(std::string command = "desliga");

    ~cooler() override = default;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_COOLER_H
