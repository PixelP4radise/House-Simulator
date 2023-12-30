//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_GREATERTHAN_H
#define HOUSE_SIMULATOR_GREATERTHAN_H

#include "./rule.h"

class greaterThan : public rule {
public:
    explicit greaterThan(const std::shared_ptr<sensor> &sensorPtr, int parameter1);

    ~greaterThan() override = default;

    void evaluate() override;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_GREATERTHAN_H
