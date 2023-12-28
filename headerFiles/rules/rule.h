//
// Created by guilh on 28/12/2023.
//

#ifndef HOUSE_SIMULATOR_RULE_H
#define HOUSE_SIMULATOR_RULE_H

#include "../houseElements.h"

class rule : public houseElements {
private:
    bool state;  // a rule is either true or false
    unsigned int firstParameter;
public:
};


#endif //HOUSE_SIMULATOR_RULE_H
