//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_WITHIN_H
#define HOUSE_SIMULATOR_WITHIN_H

#include "./rule.h"

class within : public rule {
private:
    int secondParameter;
public:
    explicit within(const std::shared_ptr<sensor> &sensorPtr, int parameter1, int parameter2);

    within(const within &source);

    std::unique_ptr<rule> clone() const override;

    ~within() override = default;

    [[nodiscard]]
    int getSecondParameter() const;

    void evaluate() override;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_WITHIN_H
