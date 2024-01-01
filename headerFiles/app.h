//
// Created by guilh on 01/01/2024.
//

#ifndef HOUSE_SIMULATOR_APP_H
#define HOUSE_SIMULATOR_APP_H

#include <cmath>
#include <vector>
#include <memory>
#include <sstream>
#include "Terminal.h"
#include "house.h"
#include "../exceptions/commandNotFound.h"

void launchApp(term::Terminal &t);

std::string launchCommand(std::string &command, std::unique_ptr<house> &housePtr);

#endif //HOUSE_SIMULATOR_APP_H
