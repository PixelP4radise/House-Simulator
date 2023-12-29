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

void processor::addRule(const std::shared_ptr<sensor> &sharedPtr, const std::string &type, int parameter1) {
    try {
        std::unique_ptr<rule> ptr;
        if (type == "equal_to")
            ptr = std::make_unique<equalTo>(sharedPtr, parameter1);
        else if (type == "less_than")
            ptr = std::make_unique<lesserThan>(sharedPtr, parameter1);
        else if (type == "greater_than")
            ptr = std::make_unique<greaterThan>(sharedPtr, parameter1);
        else
            throw unknowRule();
        vectorRules.push_back(std::move(ptr));
    } catch (const unknowRule &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void
processor::addRule(const std::shared_ptr<sensor> &sharedPtr, const std::string &type, int parameter1, int parameter2) {
    try {
        std::unique_ptr<rule> ptr;
        if (type == "in_between")
            ptr = std::make_unique<within>(sharedPtr, parameter1, parameter2);
        else if (type == "outside")
            ptr = std::make_unique<outsideOf>(sharedPtr, parameter1, parameter2);
        else
            throw unknowRule();
        vectorRules.push_back(std::move(ptr));
    } catch (const unknowRule &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void processor::setCommand(const std::string &newCommand) {
    command = newCommand;
}