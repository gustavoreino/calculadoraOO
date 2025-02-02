#include "KeyGuElder.hpp"

KeyGuElder::KeyGuElder(char symbol, Digit digit) { 
  this->symbol = symbol;
  this->digit = digit;
  this->isDigit = true;
}
KeyGuElder::KeyGuElder(char symbol, Operation operation) {
  this->symbol = symbol;
  this->operation = operation;
  this->isOperation = true;
}

KeyGuElder::KeyGuElder(char symbol, Control control){
  this->symbol = symbol;
  this->control = control;
  this->isControl = true;
}

void KeyGuElder::press() { 
  if(this->isDigit) this->keyboard->receiveDigit(this->digit);
  if(this->isOperation) this->keyboard->receiveOperation(this->operation);
  if(this->isControl) this->keyboard->receiveControl(this->control);
}

void KeyGuElder::setKeyboard(Keyboard &keyboard) { 
  this->keyboard = &keyboard; 
}

char KeyGuElder::getSymbol() { 
  return this->symbol; 
}