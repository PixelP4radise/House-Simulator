//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/propertys/property.h"

property::property(int min, int max, int value) : min(min), max(max), value(value) {}

int property::getValue() const {
    return value;
}

int property::getMax() const {
    return max;
}

int property::getMin() const {
    return min;
}

void property::setValue(int valueToBe) {
    if (valueToBe > getMax() or valueToBe < getMin())
        throw outOfRangeProperty();
    value = valueToBe;
}