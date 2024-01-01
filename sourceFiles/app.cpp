//
// Created by guilh on 01/01/2024.
//
#include <iostream>
#include "../headerFiles/app.h"

using namespace term;

void launchApp(term::Terminal &t) {
    int colsTerminal = t.getNumCols();
    int linesTerminal = t.getNumRows();
    std::unique_ptr<house> housePtr;

    int leftCollumn = static_cast<int>(std::round(static_cast<double>(colsTerminal) / 100 * 15));

    Window console = t.create_window(leftCollumn, 0, colsTerminal - leftCollumn - 1, 3,
                                     true); // the commands will be input here

    Window consoleLog = t.create_window(0, 0, leftCollumn - 2, linesTerminal, true);

    Window zonaHabitaculos = t.create_window(leftCollumn, 4, colsTerminal - leftCollumn, linesTerminal - 4, true);

    std::string command{};

    do {
        console.clear();
        console >> command;
        try {
            consoleLog << (launchCommand(command, housePtr));
        } catch (const commandNotFound &ex) {
            consoleLog << ex.what() << '\n';
        }
    } while (command != "exit");
}

std::string launchCommand(std::string &command, std::unique_ptr<house> &housePtr) {
    std::istringstream iss(command);
    std::vector<std::string> argumentsVector;

    std::string argument;

    unsigned int nArgumentos{};

    while (iss >> argument) {
        argumentsVector.push_back(argument);
        nArgumentos++;
    }
    if (argumentsVector.at(0) == "hnew" and nArgumentos == 3) {
        housePtr = std::make_unique<house>(std::stoi(argumentsVector.at(1)), std::stoi(argumentsVector.at(2)));
        return "A simulation has been started\n";
    } else if (argumentsVector.at(0) == "hrem" and nArgumentos == 1) {
        housePtr.reset();
        return "The simulation has been erased\n";
    } else if (argumentsVector.at(0) == "next" and nArgumentos == 1) {
        housePtr->carryOut();
        return "Forwarded an instant\n";
    } else if (argumentsVector.at(0) == "advance" and nArgumentos == 2) {
        int nIterations = std::stoi(argumentsVector.at(1));
        for (int i = 0; i < nIterations; ++i)
            housePtr->carryOut();
        return "Forwarded " + std::to_string(nIterations) + " instants.\n";
    } else if (argumentsVector.at(0) == "znew" and nArgumentos == 3) {
        housePtr->newRoom(std::stoi(argumentsVector.at(1)), std::stoi(argumentsVector.at(2)));
        return "A room has been created\n";
    } else if (argumentsVector.at(0) == "zrem" and nArgumentos == 2) {
        housePtr->deleteRoom(argumentsVector.at(1));
        return "Room with id: " + argumentsVector.at(1) + " was deleted.\n";
    } else if (argumentsVector.at(0) == "zlist" and nArgumentos == 1) {
        return housePtr->describeHouse();
    } else if (argumentsVector.at(0) == "zcomp" and nArgumentos == 2) {
        return housePtr->describeRoom(argumentsVector.at(1));
    } else if (argumentsVector.at(0) == "zprops" and nArgumentos == 2) {
        return housePtr->showPropertysOfRoom(argumentsVector.at(1));
    } else if (argumentsVector.at(0) == "pmod" and nArgumentos == 4) {
        housePtr->changePropertyOfRoom(argumentsVector.at(1), argumentsVector.at(2), std::stoi(argumentsVector.at(3)));
        return "Room " + argumentsVector.at(1) + " Property " + argumentsVector.at(2) + " was changed to " +
               argumentsVector.at(3);
    } else if (argumentsVector.at(0) == "cnew" and nArgumentos == 4) {
        housePtr->newComponent(argumentsVector.at(1), argumentsVector.at(2)[0], argumentsVector.at(3));
    } else if (argumentsVector.at(0) == "crem" and nArgumentos == 4) {
        housePtr->removeComponent(argumentsVector.at(1), argumentsVector.at(2)[0], argumentsVector.at(3));
    } else if (argumentsVector.at(0) == "rnew" and nArgumentos == 6) {
        housePtr->addRule(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3), argumentsVector.at(4),
                          std::stoi(argumentsVector.at(5)));
    } else if (argumentsVector.at(0) == "rnew" and nArgumentos == 7) {
        housePtr->addRule(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3), argumentsVector.at(4),
                          std::stoi(argumentsVector.at(5)), std::stoi(argumentsVector.at(6)));
    } else if (argumentsVector.at(0) == "pchange" and nArgumentos == 4) {
        housePtr->changeCommandFromProcessor(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3));
    } else if (argumentsVector.at(0) == "rlist" and nArgumentos == 3) {
        housePtr->showRulesFrom(argumentsVector.at(1), argumentsVector.at(2));
    } else if (argumentsVector.at(0) == "rrem" and nArgumentos == 4) {
        housePtr->removeRuleFrom(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3));
    } else if (argumentsVector.at(0) == "asoc" and nArgumentos == 4) {
        housePtr->associateDeviceToProcessor(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3));
    } else if (argumentsVector.at(0) == "disa" and nArgumentos == 4) {
        housePtr->disaDeviceFromProcessor(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3));
    } else if (argumentsVector.at(0) == "dcom" and nArgumentos == 4) {
        housePtr->sendCommandToDevice(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3));
    } else if (argumentsVector.at(0) == "psave" and nArgumentos == 4) {
        housePtr->saveProcessor(argumentsVector.at(1), argumentsVector.at(2), argumentsVector.at(3));
    } else if (argumentsVector.at(0) == "prestore" and nArgumentos == 2) {
        housePtr->restoreProcessor(argumentsVector.at(1));
    } else if (argumentsVector.at(0) == "prem" and nArgumentos == 2) {
        housePtr->removeProcessorFromMemory(argumentsVector.at(1));
    } else if (argumentsVector.at(0) == "plist" and nArgumentos == 1) {
        housePtr->showProcessorsFromMemory();
    } else if (argumentsVector.at(0) == "exec" and nArgumentos == 2) {
        // tem que fazer a execucao do ficheiro e mais nao sei que
    } else {
        throw commandNotFound();
    }
    return "Major Error.\n";
}