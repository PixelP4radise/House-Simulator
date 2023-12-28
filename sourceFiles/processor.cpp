//
// Created by guilh on 28/12/2023.
//

#include "../headerFiles/processor.h"

std::string processor::describe() const {
    return "p" + getId() + std::to_string(vectorRules.size());
}