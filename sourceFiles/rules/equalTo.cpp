//
// Created by guilh on 28/12/2023.
//

#include "../../headerFiles/rules/equalTo.h"

equalTo::equalTo(const std::shared_ptr<sensor> &sensorPtr, int parameter1) : rule(sensorPtr, parameter1) {}