#include <iostream> 
#include <cstdlib>
#include<time.h>
#include "polyatomic.h"
using namespace std;


int main(int argx,char* argv[]){

polyatomic testOne;

testOne.setPoly(7);
testOne.setSection(1);
testOne.printAns();
testOne.askPrint();
testOne.checkAns("PO4");



return 0;
}
