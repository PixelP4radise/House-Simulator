//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_OUTSIDEOF_H
#define HOUSE_SIMULATOR_OUTSIDEOF_H

#include "./rule.h"

class outsideOf : public rule {
private:
    int secondParameter;
public:

    explicit outsideOf(const std::shared_ptr<sensor> &sensorPtr, int parameter1, int parameter2);

    outsideOf(const outsideOf &source) = default;

    [[nodiscard]]
    std::unique_ptr<rule> clone() const override;

    ~outsideOf() override = default;

    [[nodiscard]]
    int getSecondParameter() const;

    void evaluate() override;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_OUTSIDEOF_H
