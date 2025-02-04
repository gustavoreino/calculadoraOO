#pragma once

enum Digit{ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, NO_DIGIT};

enum Signal{POSITIVE, NEGATIVE};

enum Operation{ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION, EQUAL, NOOP};

enum Control{OFF, ON_CLEAR_ERROR, MEMORY_READ_CLEAR, MEMORY_SUBTRACTION, MEMORY_ADDITION, DECIMAL_SEPARATOR};

class DisplayInterface{
  public:
    virtual void addDigit(Digit, bool withDot = false ) = 0;
    virtual void setSignal(Signal) = 0;
    virtual void clear() = 0;
};

class CpuInterface{
  public:
    virtual void receiveDigit(Digit) = 0;
    virtual void receiveOperation(Operation) = 0;
    virtual void receiveControl(Control) = 0;
    virtual void setDisplay(DisplayInterface&) = 0;
};

class KeyInterface;
class KeyboardInterface{
  public:
    virtual void receiveDigit(Digit) = 0;
    virtual void receiveOperation(Operation) = 0;
    virtual void receiveControl(Control) = 0;
    virtual void addKey(KeyInterface& key) = 0;
    virtual KeyInterface& findKey(char) = 0;
    virtual void setCpu(CpuInterface&) = 0;
};

class KeyInterface{
  public:
    virtual void press() = 0;
    virtual void setKeyboard(KeyboardInterface&) = 0;
    virtual char getSymbol() = 0;
};
