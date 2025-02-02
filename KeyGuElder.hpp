#pragma once

#include "Calculator.hpp"

class KeyGuElder: public Key{
    private:
    Keyboard* keyboard;
    char symbol;
    Digit digit;
    Operation operation;
    Control control;
    bool isDigit = false;
    bool isOperation = false;
    bool isControl = false;
    public:
    KeyGuElder(char, Digit);
    KeyGuElder(char, Operation);
    KeyGuElder(char, Control);
    void press();
    void setKeyboard(Keyboard&);
    char getSymbol();
};
