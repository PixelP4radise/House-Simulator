//
// Created by guilh on 01/01/2024.
//

#ifndef HOUSE_SIMULATOR_APP_H
#define HOUSE_SIMULATOR_APP_H

#include <cmath>
#include <vector>
#include <memory>
#include <sstream>
#include <fstream>
#include "Terminal.h"
#include "house.h"
#include "../exceptions/commandNotFound.h"
#include "../exceptions/fileNotOpened.h"
#include "../exceptions/houseNotCreated.h"

void launchApp(term::Terminal &t);

void launchCommand(std::string &command, std::unique_ptr<house> &housePtr, term::Window &consoleLog);

void execFicheiro(const std::string &name, std::unique_ptr<house> &housePtr, term::Window &consoleLog);

#endif //HOUSE_SIMULATOR_APP_H
