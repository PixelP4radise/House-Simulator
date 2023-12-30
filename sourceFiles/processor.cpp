//
// Created by guilh on 28/12/2023.
//

#include "../headerFiles/processor.h"

processor::processor(std::string command, std::string roomId) : command(std::move(command)), roomId(roomId) {
    static unsigned int counter{};
    num = counter++;
}

processor::processor(const processor &source) : command(source.command), processorOutput(source.processorOutput),
                                                roomId(source.roomId) {
    vectorRules.reserve(source.vectorRules.size());
    for (const auto &rulePtr: source.vectorRules)
        vectorRules.push_back(rulePtr->clone());
    setNum(source.getNum());
}

std::string processor::getId() const {
    return "p" + std::to_string(getNum());
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
            ptr = std::make_unique<lessThan>(sharedPtr, parameter1);
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

void processor::removeRule(const std::string &idRule) {
    try {
        auto ruleIt = findRuleItById(idRule);
        vectorRules.erase(ruleIt);
    } catch (const ruleNotFound &ex) {
        std::cout << ex.what() << std::endl;
    }
}

void processor::setCommand(const std::string &newCommand) {
    command = newCommand;
}

void processor::showRules() {
    for (const auto &rule: vectorRules) {
        std::cout << rule->describe() << std::endl;
    }
}

void processor::associateDevice(const std::shared_ptr<devices> &toBeAsoc) {
    std::weak_ptr<devices> weakPtr = toBeAsoc;
    processorOutput.push_back(weakPtr);
}

void processor::disassociateDevice(const std::string &idDevice) {
    try {
        auto deviceIt = findDeviceItById(idDevice);
        processorOutput.erase(deviceIt);
    } catch (const deviceNotFound &ex) {
        std::cout << ex.what() << std::endl;
    } catch (const acessError &ex) {
        std::cout << ex.what() << std::endl;
    }
}

std::vector<std::weak_ptr<devices>>::const_iterator processor::findDeviceItById(const std::string &idDevice) const {
    auto deviceIt = std::find_if(processorOutput.begin(), processorOutput.end(), [idDevice](const auto &obj) {
        auto sharedPtr = obj.lock();
        if (sharedPtr)
            return sharedPtr->getId() == idDevice;
        throw acessError();
    });
    if (deviceIt == processorOutput.end())
        throw deviceNotFound();
    return deviceIt;
}

std::vector<std::unique_ptr<rule>>::const_iterator processor::findRuleItById(const std::string &idRule) const {
    auto ruleIt = std::find_if(vectorRules.begin(), vectorRules.end(),
                               [idRule](const auto &obj) { return obj->getId() == idRule; });
    if (ruleIt == vectorRules.end())
        throw ruleNotFound();
    return ruleIt;
}