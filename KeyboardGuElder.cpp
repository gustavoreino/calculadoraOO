#include "KeyboardGuElder.hpp"

void KeyboardGuElder::receiveDigit(Digit digit) {
  this->cpu->receiveDigit(digit);
}
void KeyboardGuElder::receiveOperation(Operation operation) {
  this->cpu->receiveOperation(operation);  
}
void KeyboardGuElder::receiveControl(Control control) {
  this->cpu->receiveControl(control); 
}

void KeyboardGuElder::addKey(Key& key) {
  this->keys[this->keysCount++] = &key;
  key.setKeyboard(*this);
}

Key& KeyboardGuElder::findKey(char symbol) {
  for(int i = 0; i < this->keysCount; i++){
    if(this->keys[i]->getSymbol() == symbol){
      return *this->keys[i];
    }
  }

  throw "KEY_NOT_FOUND";
}

void KeyboardGuElder::setCpu(Cpu& cpu) {
  this->cpu = &cpu;
}