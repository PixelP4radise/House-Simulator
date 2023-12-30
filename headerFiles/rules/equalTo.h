//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_EQUALTO_H
#define HOUSE_SIMULATOR_EQUALTO_H

#include "./rule.h"

class equalTo : public rule {
public:
    explicit equalTo(const std::shared_ptr<sensor> &sensorPtr, int parameter1);

    ~equalTo() override = default;

    void evaluate() override;

    [[nodiscard]]
    std::string describe() const override;
};


#endif //HOUSE_SIMULATOR_EQUALTO_H
