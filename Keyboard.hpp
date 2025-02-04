#pragma once
#include "Calculator.hpp"
#include "Key.hpp"

#define MAX_KEYS 23
class Keyboard: public KeyboardInterface{
  private:
    CpuInterface* cpu;
    KeyInterface* keys[MAX_KEYS];
    unsigned char keysCount = 0;
  public:
    virtual void receiveDigit(Digit);
    virtual void receiveOperation(Operation);
    virtual void receiveControl(Control);
    virtual void addKey(KeyInterface&);
    virtual KeyInterface& findKey(char);
    virtual void setCpu(CpuInterface&);
};