//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_LESSERTHAN_H
#define HOUSE_SIMULATOR_LESSERTHAN_H

#include "./rule.h"

class lesserThan : public rule {
public:
    explicit lesserThan(const std::shared_ptr<sensor> &sensorPtr, int parameter1);

    void evaluate() override;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_LESSERTHAN_H
