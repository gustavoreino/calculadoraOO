#pragma once

#include "Calculator.hpp"

class Key: public KeyInterface{
    private:
    KeyboardInterface* keyboard;
    char symbol;
    Digit digit;
    Operation operation;
    Control control;
    bool isDigit = false;
    bool isOperation = false;
    bool isControl = false;
    public:
    Key(char, Digit);
    Key(char, Operation);
    Key(char, Control);
    void press();
    void setKeyboard(KeyboardInterface&);
    char getSymbol();
};
