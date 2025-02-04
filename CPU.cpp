#include "CPU.hpp"

void Cpu::receiveDigit(Digit number){
    if(number != NO_DIGIT){
        if(this->Operator == NOOP){
            this->Memory1[memory1count] = number; memory1count++;
        }else{
            this->Memory2[memory2count] = number; memory2count++;
        }
        this->display->addDigit(number);
    }
}

void Cpu::reset_memory1_memory2(){
    this->memory1count = 0;
    this->memory2count = 0;
    this->memory1Dot = -1;
    this->memory2Dot = -1;
    this->memory1negative == 0;
    this->memory2negative == 0;
    this->Operator = NOOP;
}

void Cpu::receiveOperation(Operation operation){
    if(memory1count == 0 && resultcount > 0){
        for(int i = 0; i < resultcount; i++){
            Memory1[i] = Result[i];
        }
        memory1count = resultcount;
        memory1Dot = resultDot;
        memory1negative = resultnegative;
    }
    switch(operation){
        case ADDITION:
        this->Operator = operation;
        this->display->clear();
        break;
        case SUBTRACTION:
        if( memory1count == 0 && Operator == NOOP ){
            this->memory1negative = true;
            this->display->setSignal(NEGATIVE);
        } else if ( memory2count == 0 && Operator != NOOP ){
            this->memory2negative = true;
            this->display->setSignal(NEGATIVE);
        } else {
            this->Operator = operation;
            this->display->clear();
        }
        break;
        case MULTIPLICATION:
        this->Operator = operation;
        this->display->clear();
        break;
        case DIVISION:
        this->Operator = operation;
        this->display->clear();
        break;
        case EQUAL:
        this->display->clear();
        calculate();
        break;
        case NOOP:
        break;
        default:
        break;
    }
}

void Cpu::receiveControl(Control control){
    switch(control){
        case ON_CLEAR_ERROR:
            if(this->display == NULL){
                this->display = new Display();
            }
            reset_memory1_memory2();
            this->display->clear();
            break;
        case OFF:
            reset_memory1_memory2();
            delete this->display;
            break;
        case MEMORY_READ_CLEAR:
            Calculate_Extra_Memory();
            break;
        case MEMORY_SUBTRACTION:
            if(Operator == NOOP){
                memoryXdouble -= (convert_Digit_to_double(Memory1,memory1count,memory1Dot,memory1negative));
            } else {
                memoryXdouble -= (convert_Digit_to_double(Memory2,memory2count,memory2Dot,memory2negative));
            }
            break;
        case MEMORY_ADDITION:
            if(Operator == NOOP){
                memoryXdouble += (convert_Digit_to_double(Memory1,memory1count,memory1Dot,memory1negative));
            } else {
                memoryXdouble += (convert_Digit_to_double(Memory2,memory2count,memory2Dot,memory2negative));
            }
            printf("%.7f\n", memoryXdouble);
            break;
        case DECIMAL_SEPARATOR:
            if(this->Operator == NOOP){
                this->memory1Dot = memory1count - 1;
            }else{
                this->memory2Dot = memory2count - 1;
            }
            this->display->addDigit(NO_DIGIT);
            break;
        default:
            break;
    }
}

void Cpu::setDisplay(DisplayInterface& newDisplay){
    this->display = &newDisplay;
}

void Cpu::calculate(){

    memory1double = convert_Digit_to_double(Memory1,memory1count,memory1Dot,memory1negative);
    memory2double = convert_Digit_to_double(Memory2,memory2count,memory2Dot,memory2negative);

    switch(Operator){
        case ADDITION:
        resultdouble = memory1double + memory2double;
        break;
        case SUBTRACTION:
        resultdouble = memory1double - memory2double;
        break;
        case MULTIPLICATION:
        resultdouble = memory1double * memory2double;
        break;
        case DIVISION:
        resultdouble = memory1double / memory2double;
        break;
        case EQUAL:
        break;
        case NOOP:
        break;
        default:
        break;
    }
    reset_memory1_memory2();
    int dotpos = 0;
    if(resultdouble < 0){this->display->setSignal(NEGATIVE); resultdouble *= -1.0; resultnegative = true;}
    int convertInt = (int)resultdouble;
    int n = convertInt;
    float ten = 1.0;
    while(n != 0){
        dotpos++;
        n /= 10;
        ten /= 10.0;
    }
    float floatingPointResult = resultdouble * ten;
    for(int i = 0; i < Max_digits; i++){
        floatingPointResult *= 10.0;
        int floatingPointInt = (int)floatingPointResult;
        if((floatingPointInt % 10) == 0){
            Result[i] = ZERO;
            this->display->addDigit(ZERO);
        } else if((floatingPointInt % 10) == 1){
            Result[i] = ONE;
            this->display->addDigit(ONE);
        } else if((floatingPointInt % 10) == 2){
            Result[i] = TWO;
            this->display->addDigit(TWO);
        } else if((floatingPointInt % 10) == 3){
            Result[i] = THREE;
            this->display->addDigit(THREE);
        } else if((floatingPointInt % 10) == 4){
            Result[i] = FOUR;
            this->display->addDigit(FOUR);
        } else if((floatingPointInt % 10) == 5){
            Result[i] = FIVE;
            this->display->addDigit(FIVE);
        } else if((floatingPointInt % 10) == 6){
            Result[i] = SIX;
            this->display->addDigit(SIX);
        } else if((floatingPointInt % 10) == 7){
            Result[i] = SEVEN;
            this->display->addDigit(SEVEN);
        } else if((floatingPointInt % 10) == 8){
            Result[i] = EIGHT;
            this->display->addDigit(EIGHT);
        } else if((floatingPointInt % 10) == 9){
            Result[i] = NINE;
            this->display->addDigit(NINE);
        }
        if(i == dotpos - 1){
            this->display->addDigit(NO_DIGIT);
            resultDot = dotpos - 1;
        }
    }
    int i = Max_digits - 1;
    while(i >= 0){
        if( Result[i] != ZERO || i == 0 ){
            resultcount == i + 1;
            break;
        }
        i--;
    }
}

double Cpu::convert_Digit_to_double(Digit* Memory, int count, int memoryDot, bool negative){
    double memorydouble = 0.0;
    double aux = 1.0;
    if(memoryDot != -1){
        for(int i = memoryDot; i > 0; i--){
            aux *= 10.0;
        }
    } else {
        for(int i = 1; i < count; i++){
            aux *= 10.0;
        }
    }
    for(int i = 0; i < count; i++){
        memorydouble += ((double)Memory[i] * aux);
        aux /= 10.0;
    }
    if(negative == true){ 
        memorydouble *= -1;
    }
    return memorydouble;
}

void Cpu::Calculate_Extra_Memory(){
    int dotpos = 0;
    if(memoryXdouble < 0){this->display->setSignal(NEGATIVE); resultdouble *= -1.0; memoryXnegative = true;}
    int convertInt = (int)memoryXdouble;
    int n = convertInt;
    float ten = 1.0;
    while(n != 0){
        dotpos++;
        n /= 10;
        ten /= 10.0;
        }
    float floatingPointMemoryX = memoryXdouble * ten;
    for(int i = 0; i < Max_digits; i++){
        floatingPointMemoryX *= 10.0;
        int floatingPointInt = (int)floatingPointMemoryX;
        if((floatingPointInt % 10) == 0){
            MemoryX[i] = ZERO;
            this->display->addDigit(ZERO);
        } else if((floatingPointInt % 10) == 1){
            MemoryX[i] = ONE;
            this->display->addDigit(ONE);
        } else if((floatingPointInt % 10) == 2){
            MemoryX[i] = TWO;
            this->display->addDigit(TWO);
        } else if((floatingPointInt % 10) == 3){
            MemoryX[i] = THREE;
            this->display->addDigit(THREE);
        } else if((floatingPointInt % 10) == 4){
            MemoryX[i] = FOUR;
            this->display->addDigit(FOUR);
        } else if((floatingPointInt % 10) == 5){
            MemoryX[i] = FIVE;
            this->display->addDigit(FIVE);
        } else if((floatingPointInt % 10) == 6){
            MemoryX[i] = SIX;
            this->display->addDigit(SIX);
        } else if((floatingPointInt % 10) == 7){
            MemoryX[i] = SEVEN;
            this->display->addDigit(SEVEN);
        } else if((floatingPointInt % 10) == 8){
            MemoryX[i] = EIGHT;
            this->display->addDigit(EIGHT);
        } else if((floatingPointInt % 10) == 9){
            MemoryX[i] = NINE;
            this->display->addDigit(NINE);
        }
        if(i == dotpos - 2){
            this->display->addDigit(NO_DIGIT);
            memoryXDot = dotpos - 2;
        }
    }
    int i = Max_digits - 1;
    while(i >= 0){
        if( MemoryX[i] != ZERO || i == 0 ){
            memoryXcount == i + 1;
            break;
        }
        i--;
    }
    if(Operator == NOOP){
        for(int i = 0; i < resultcount; i++){
            Memory1[i] = MemoryX[i];
        }
        memory1count = memoryXcount;
        memory1Dot = memoryXDot;
        memory1negative = memoryXnegative;
    } else {
        for(int i = 0; i < resultcount; i++){
            Memory2[i] = MemoryX[i];
        }
        memory2count = memoryXcount;
        memory2Dot = memoryXDot;
        memory2negative = memoryXnegative;
    }
    memoryXcount = 0;
    memoryXDot = -1;
    memoryXnegative = false;
}