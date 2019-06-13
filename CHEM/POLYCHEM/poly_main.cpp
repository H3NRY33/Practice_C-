#include <iostream> 
#include <cstdlib>
#include "src/polyatomic.h"
using namespace std;


int main(){
polyatomic testOne;

testOne.setPoly(7);
testOne.setSection(1);
testOne.printAns();
testOne.askPrint();
testOne.checkAns("PO4");
return 0;
}
