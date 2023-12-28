//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_PROCESSOR_H
#define HOUSE_SIMULATOR_PROCESSOR_H

#include <vector>
#include <memory>
#include "./houseElements.h"
#include "./devices/devices.h"
#include "./rules/rule.h"

class processor : public houseElements {
private:
    std::vector<std::unique_ptr<rule>> vectorRules;
    std::string command; //comando para os portugues
    std::vector<std::weak_ptr<devices>> devicesOutput;
public:
    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_PROCESSOR_H
