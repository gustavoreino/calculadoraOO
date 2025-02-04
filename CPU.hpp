#pragma once

#include <iostream>
#include "Calculator.hpp"
#include "Display.hpp"

#define Max_digits 8

class Cpu: public CpuInterface{
    private:
    DisplayInterface* display;
    Operation Operator = NOOP;
    
    Digit Memory1[Max_digits];
    int memory1count = 0;
    int memory1Dot = -1;
    double memory1double = 0.0;
    bool memory1negative = false;
    
    Digit Memory2[Max_digits];
    int memory2count = 0;
    int memory2Dot = -1;
    double memory2double = 0.0;
    bool memory2negative = false;

    Digit MemoryX[Max_digits];
    int memoryXcount = 0;
    int memoryXDot = -1;
    double memoryXdouble = 0.0;
    bool memoryXnegative = false;

    double resultdouble = 0.0;
    Digit Result[Max_digits];
    int resultcount = 0;
    int resultDot = -1;
    bool resultnegative = false;

    public:
    virtual void receiveDigit(Digit);
    virtual void receiveOperation(Operation);
    virtual void receiveControl(Control);
    virtual void setDisplay(DisplayInterface&);
    virtual void calculate();
    virtual double convert_Digit_to_double(Digit*, int, int, bool);
    virtual void Calculate_Extra_Memory();
    virtual void reset_memory1_memory2();
};