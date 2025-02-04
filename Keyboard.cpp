#include "Keyboard.hpp"

void Keyboard::receiveDigit(Digit digit) {
  this->cpu->receiveDigit(digit);
}
void Keyboard::receiveOperation(Operation operation) {
  this->cpu->receiveOperation(operation);  
}
void Keyboard::receiveControl(Control control) {
  this->cpu->receiveControl(control); 
}

void Keyboard::addKey(KeyInterface& key) {
  this->keys[this->keysCount++] = &key;
  key.setKeyboard(*this);
}

KeyInterface& Keyboard::findKey(char symbol) {
  for(int i = 0; i < this->keysCount; i++){
    if(this->keys[i]->getSymbol() == symbol){
      return *this->keys[i];
    }
  }

  throw "KEY_NOT_FOUND";
}

void Keyboard::setCpu(CpuInterface& cpu) {
  this->cpu = &cpu;
}