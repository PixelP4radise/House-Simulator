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
#include "./rules/lesserThan.h"
#include "./rules/outsideOf.h"
#include "./rules/within.h"
#include "../exceptions/unknowRule.h"
#include "../exceptions/ruleNotFound.h"

class processor : public houseElements {
private:
    std::vector<std::unique_ptr<rule>> vectorRules;
    std::string command; //comando para os portugues
    std::vector<std::weak_ptr<devices>> devicesOutput;
public:
    explicit processor(std::string command);

    ~processor() override = default;

    [[nodiscard]]
    std::string getId() const override;

    [[nodiscard]]
    std::string describe() const override;

    void addRule(const std::shared_ptr<sensor> &sharedPtr, const std::string &type, int parameter1);

    void addRule(const std::shared_ptr<sensor> &sharedPtr, const std::string &type, int parameter1, int parameter2);

    void removeRule(const std::string &id);

    void setCommand(const std::string &newCommand);

    void showRules();
};


#endif //HOUSE_SIMULATOR_PROCESSOR_H
