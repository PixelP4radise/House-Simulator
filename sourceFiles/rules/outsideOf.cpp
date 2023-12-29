//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/outsideOf.h"

outsideOf::outsideOf(const std::shared_ptr<sensor> &sensorPtr, int parameter1, int parameter2)
        : rule(sensorPtr, parameter1), secondParameter(parameter2) {}