//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_PROCESSOR_H
#define HOUSE_SIMULATOR_PROCESSOR_H

#include <vector>
#include <memory>
#include <algorithm>
#include "./houseElements.h"
#include "./devices/devices.h"
#include "./rules/equalTo.h"
#include "./rules/greaterThan.h"
#include "./rules/lessThan.h"
#include "./rules/outsideOf.h"
#include "./rules/within.h"
#include "../exceptions/unknowRule.h"
#include "../exceptions/ruleNotFound.h"
#include "../exceptions/deviceNotFound.h"

class processor : public houseElements {
private:
    std::string roomId;
    std::vector<std::unique_ptr<rule>> vectorRules;
    std::string command;
    std::vector<std::weak_ptr<devices>> processorOutput;
public:
    explicit processor(std::string command, std::string roomId);

    processor(const processor &source);

    ~processor() override = default;

    [[nodiscard]]
    std::string getRoomId() const;

    [[nodiscard]]
    std::string getId() const override;

    [[nodiscard]]
    std::string describe() const override;

    void addRule(const std::shared_ptr<sensor> &sharedPtr, const std::string &type, int parameter1);

    void addRule(const std::shared_ptr<sensor> &sharedPtr, const std::string &type, int parameter1, int parameter2);

    void removeRule(const std::string &idRule);

    void setCommand(const std::string &newCommand);

    void showRules();

    void associateDevice(const std::shared_ptr<devices> &toBeAsoc);

    void disassociateDevice(const std::string &idDevice);

    [[nodiscard]]
    std::vector<std::weak_ptr<devices>>::const_iterator findDeviceItById(const std::string &idDevice) const;

    [[nodiscard]]
    std::vector<std::unique_ptr<rule>>::const_iterator findRuleItById(const std::string &idRule) const;

    [[nodiscard]]
    std::string getProcessorCommand() const;

    void sendCommandToDevices() const;

    void carryOut() const;
};


#endif //HOUSE_SIMULATOR_PROCESSOR_H
