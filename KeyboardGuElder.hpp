#pragma once
#include "Calculator.hpp"
#include "KeyGuElder.hpp"

#define MAX_KEYS 23
class KeyboardGuElder: public Keyboard{
  private:
    Cpu* cpu;
    Key* keys[MAX_KEYS];
    unsigned char keysCount = 0;
  public:
    virtual void receiveDigit(Digit);
    virtual void receiveOperation(Operation);
    virtual void receiveControl(Control);
    virtual void addKey(Key&);
    virtual Key& findKey(char);
    virtual void setCpu(Cpu&);
};