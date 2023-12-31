//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_PROPERTY_H
#define HOUSE_SIMULATOR_PROPERTY_H

#include <iostream>
#include <climits>
#include "../../exceptions/outOfRangeProperty.h"

class property {
private:
    int value;
    int max;
    int min;
public:
    explicit property(int min, int max = INT_MAX, int value = 0);

    ~property() = default;

    [[nodiscard]]
    int getValue() const;

    [[nodiscard]]
    int getMax() const;

    [[nodiscard]]
    int getMin() const;

    void setValue(int valueToBe);
};


#endif //HOUSE_SIMULATOR_PROPERTY_H
