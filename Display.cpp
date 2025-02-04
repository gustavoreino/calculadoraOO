#include "Display.hpp"

void Display::digitShow(Digit digit, int line, bool Dot){
    switch (digit){
    case ZERO:
        if(line == 1){std::cout << full;}
        if(line == 2){std::cout << corners;}
        if(line == 3){std::cout << corners;}
        if(line == 4){std::cout << corners;}
        if(line == 5){ if(Dot == true){std::cout << fulldot;}else{std::cout << full;}}
        break;
    case ONE:
        if(line < 5){std::cout << right;}else{ if(Dot == true){std::cout << rightdot;}else{std::cout << right;}}
        break;
    case TWO:
        if(line == 1){std::cout << full; }
        if(line == 2){std::cout << right; }
        if(line == 3){std::cout << full; }
        if(line == 4){std::cout << left; }
        if(line == 5){ if(Dot == true){std::cout << fulldot;}else{std::cout << full;}}
        break;
    case THREE:
        if(line == 1){std::cout << full; }
        if(line == 2){std::cout << right; }
        if(line == 3){std::cout << full; }
        if(line == 4){std::cout << right; }
        if(line == 5){if(Dot == true){std::cout << fulldot;}else{std::cout << full;}}
        break;
    case FOUR:
        if(line == 1){std::cout << corners; }
        if(line == 2){std::cout << corners; }
        if(line == 3){std::cout << full; }
        if(line == 4){std::cout << right; }
        if(line == 5){if(Dot == true){std::cout << rightdot;}else{std::cout << right;}}
        break;
    case FIVE:
        if(line == 1){std::cout << full; }
        if(line == 2){std::cout << left; }
        if(line == 3){std::cout << full; }
        if(line == 4){std::cout << right; }
        if(line == 5){if(Dot == true){std::cout << fulldot;}else{std::cout << full;}}
        break;
    case SIX:
        if(line == 1){std::cout << full; }
        if(line == 2){std::cout << left; }
        if(line == 3){std::cout << full; }
        if(line == 4){std::cout << corners; }
        if(line == 5){if(Dot == true){std::cout << fulldot;}else{std::cout << full;}}
        break;
    case SEVEN:
        if(line == 1){std::cout << full; }
        if(line > 1 && line < 5){std::cout << right;}
        if(line == 5){if(Dot == true){std::cout << rightdot;}else{std::cout << right;}}
        break;
    case EIGHT:
        if(line == 1){std::cout << full; }
        if(line == 2){std::cout << corners; }
        if(line == 3){std::cout << full; }
        if(line == 4){std::cout << corners; }
        if(line == 5){if(Dot == true){std::cout << fulldot;}else{std::cout << full;}}
        break;
    case NINE:
        if(line == 1){std::cout << full; }
        if(line == 2){std::cout << corners; }
        if(line == 3){std::cout << full; }
        if(line == 4){std::cout << right; }
        if(line == 5){if(Dot == true){std::cout << rightdot;}else{std::cout << right;}}
        break;
    case NO_DIGIT:
        break;
    default:
        break;
    }
}

void Display::signalShow(Signal sign, int line){
    if(sign == NEGATIVE){
        if( line != 3 ){std::cout << empty; }else{std::cout << full; }
    } else {
        std::cout << empty;
    }
}

void Display::print(){
    this->console.set_cursor(0,0);
    this->console.clear_screen();
    int diff = digitLimit - digitCount;
    if(digitCount == 0){
        for(int i = 1; i <= 5; i++){
            signalShow(signal, i);
            std::cout << std::endl;
        }
    }else{
        for(int i = 1; i <= 5; i++){
            signalShow(signal, i);
            for(int j = 1; j <= digitLimit; j++){
                if(j <= diff){
                    std::cout << empty;
                } else if(j > diff){
                    if(j == Dotpos + diff){
                        digitShow(digitArray[j - diff - 1],i,true);
                    } else{
                        digitShow(digitArray[j - diff - 1],i,false);
                    }
                }
            }
            std::cout << std::endl;
        }
    }
}

void Display::addDigit(Digit digit, bool withDot){
    if(digit == NO_DIGIT){
        this->Dotpos = digitCount; 
        this->print();
    } else {
        if(digitCount < digitLimit){
            digitArray[digitCount] = digit;
            digitCount++;
            this->print();
        }
    }
}

void Display::setSignal(Signal sign){
    this->signal = sign;
    this->print();
}

void Display::clear(){
    digitCount = 0;
    signal = POSITIVE;
    Dotpos = -1;
    this->print();
}