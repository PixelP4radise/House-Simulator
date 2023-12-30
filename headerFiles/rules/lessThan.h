//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_LESSTHAN_H
#define HOUSE_SIMULATOR_LESSTHAN_H

#include "./rule.h"

class lessThan : public rule {
public:
    explicit lessThan(const std::shared_ptr<sensor> &sensorPtr, int parameter1);

    lessThan(const lessThan &source);

    std::unique_ptr<rule> clone() const override;

    ~lessThan() override = default;

    void evaluate() override;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_LESSTHAN_H
