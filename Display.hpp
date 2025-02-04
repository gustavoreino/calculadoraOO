#pragma once

#include <iostream>
#include <string>
#include "Calculator.hpp"
#include "Console.hpp"

class Display : public DisplayInterface{
    private:
    Console console;
    int digitCount = 0;
    int digitLimit = 8;
    int Dotpos = -1;
    Digit digitArray[8];
    Signal signal;
    std::string full = "█████  ";
    std::string left = "█      ";
    std::string right = "    █  ";
    std::string corners = "█   █  ";
    std::string empty = "       ";
    std::string fulldot = "█████- ";
    std::string rightdot = "    █- ";
    public:
    virtual void addDigit(Digit, bool withDot = false);
    virtual void setSignal(Signal);
    virtual void print();
    virtual void signalShow(Signal, int);
    virtual void digitShow(Digit, int, bool);
    virtual void clear();
};