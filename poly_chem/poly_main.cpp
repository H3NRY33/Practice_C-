#include <iostream> 
#include <cstdlib>
#include<time.h>
#include "polyatomic.h"
using namespace std;


int main(int argx,char* argv[]){
srand(time(NULL));
size_t randNum = rand() % 12;
polyatomic testOne;

testOne.getPoly(randNum);
testOne.checkAns("ammonia");



return 0;
}
