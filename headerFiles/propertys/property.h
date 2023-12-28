//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_PROPERTY_H
#define HOUSE_SIMULATOR_PROPERTY_H

#include <iostream>

class property {
private:
    int value;
    int max;
    int min;
public:

    property(int min, int max = INT_MAX, int value = 0);

    [[nodiscard]]
    int getValue() const;

    [[nodiscard]]
    int getMax() const;

    [[nodiscard]]
    int getMin() const;
};


#endif //HOUSE_SIMULATOR_PROPERTY_H
