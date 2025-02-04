#include <iostream>
using namespace std;
#include "Display.hpp"
#include "CPU.hpp"
#include "Key.hpp"
#include "Keyboard.hpp"

int main(){
  KeyboardInterface * kb = new Keyboard();
  CpuInterface * cpu = new Cpu();
  DisplayInterface * d = new Display();
  KeyInterface * key1 = new Key('1',ONE);
  KeyInterface * key2 = new Key('2',TWO);
  KeyInterface * key3 = new Key('3',THREE);
  KeyInterface * key4 = new Key('4',FOUR);
  KeyInterface * key5 = new Key('5',FIVE);
  KeyInterface * key6 = new Key('6',SIX);
  KeyInterface * key7 = new Key('7',SEVEN);
  KeyInterface * key8 = new Key('8',EIGHT);
  KeyInterface * key9 = new Key('9',NINE);
  KeyInterface * key0 = new Key('0',ZERO);
  KeyInterface * keyplus = new Key('+',ADDITION);
  KeyInterface * keyminus = new Key('-',SUBTRACTION);
  KeyInterface * keytimes = new Key('*',MULTIPLICATION);
  KeyInterface * keydivide = new Key('/',DIVISION);
  KeyInterface * keyequal = new Key('=',EQUAL);
  KeyInterface * keydot = new Key('.',DECIMAL_SEPARATOR);
  KeyInterface * keyclear = new Key('A',ON_CLEAR_ERROR);
  KeyInterface * keyoff = new Key('F',OFF);
  KeyInterface * keymem = new Key('M',MEMORY_READ_CLEAR);
  KeyInterface * keymemplus = new Key('N',MEMORY_ADDITION);
  KeyInterface * keymemminus = new Key('L',MEMORY_SUBTRACTION);
  kb->addKey(*key1);
  kb->addKey(*key2);
  kb->addKey(*key3);
  kb->addKey(*key4);
  kb->addKey(*key5);
  kb->addKey(*key6);
  kb->addKey(*key7);
  kb->addKey(*key8);
  kb->addKey(*key9);
  kb->addKey(*key0);
  kb->addKey(*keyplus);
  kb->addKey(*keyminus);
  kb->addKey(*keytimes);
  kb->addKey(*keydivide);
  kb->addKey(*keyequal);
  kb->addKey(*keydot);
  kb->addKey(*keymem);
  kb->addKey(*keymemplus);
  kb->addKey(*keymemminus);
  kb->addKey(*keyclear);
  kb->addKey(*keyoff);
  kb->setCpu(*cpu);
  // kb->findKey('A').press();
  // kb->findKey('1').press();
  // kb->findKey('*').press();
  // kb->findKey('1').press();
  // kb->findKey('=').press();
  char x;
  while (true) {
    cin >> x;
    kb->findKey(x).press();
  }
}