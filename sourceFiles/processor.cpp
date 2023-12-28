//
// Created by guilh on 28/12/2023.
//

#include "../headerFiles/processor.h"

processor::processor(std::string command) : command(std::move(command)) {}

std::string processor::getId() const {
    return "p" + getNum();
}

std::string processor::describe() const {
    return getId() + " processor " + std::to_string(vectorRules.size());
}