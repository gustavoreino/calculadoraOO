#include <iostream>
using namespace std;
#include "DisplayGuElder.hpp"
#include "CPUGuElder.hpp"
#include "KeyGuElder.hpp"
#include "KeyboardGuElder.hpp"

int main(){
  Keyboard * kb = new KeyboardGuElder();
  Cpu * cpu = new CpuGuElder();
  Display * d = new DisplayGuElder();
  Key * key1 = new KeyGuElder('1',ONE);
  Key * key2 = new KeyGuElder('2',TWO);
  Key * key3 = new KeyGuElder('3',THREE);
  Key * key4 = new KeyGuElder('4',FOUR);
  Key * key5 = new KeyGuElder('5',FIVE);
  Key * key6 = new KeyGuElder('6',SIX);
  Key * key7 = new KeyGuElder('7',SEVEN);
  Key * key8 = new KeyGuElder('8',EIGHT);
  Key * key9 = new KeyGuElder('9',NINE);
  Key * key0 = new KeyGuElder('0',ZERO);
  Key * keyplus = new KeyGuElder('+',ADDITION);
  Key * keyminus = new KeyGuElder('-',SUBTRACTION);
  Key * keytimes = new KeyGuElder('*',MULTIPLICATION);
  Key * keydivide = new KeyGuElder('/',DIVISION);
  Key * keyequal = new KeyGuElder('=',EQUAL);
  Key * keydot = new KeyGuElder('.',DECIMAL_SEPARATOR);
  Key * keyclear = new KeyGuElder('A',ON_CLEAR_ERROR);
  Key * keyoff = new KeyGuElder('F',OFF);
  Key * keymem = new KeyGuElder('M',MEMORY_READ_CLEAR);
  Key * keymemplus = new KeyGuElder('N',MEMORY_ADDITION);
  Key * keymemminus = new KeyGuElder('L',MEMORY_SUBTRACTION);
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