#include "Key.hpp"

Key::Key(char symbol, Digit digit) { 
  this->symbol = symbol;
  this->digit = digit;
  this->isDigit = true;
}
Key::Key(char symbol, Operation operation) {
  this->symbol = symbol;
  this->operation = operation;
  this->isOperation = true;
}

Key::Key(char symbol, Control control){
  this->symbol = symbol;
  this->control = control;
  this->isControl = true;
}

void Key::press() { 
  if(this->isDigit) this->keyboard->receiveDigit(this->digit);
  if(this->isOperation) this->keyboard->receiveOperation(this->operation);
  if(this->isControl) this->keyboard->receiveControl(this->control);
}

void Key::setKeyboard(KeyboardInterface &keyboard) { 
  this->keyboard = &keyboard; 
}

char Key::getSymbol() { 
  return this->symbol; 
}