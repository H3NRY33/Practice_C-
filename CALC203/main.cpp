#include <iostream> 
#include "calc203.h"
using namespace std;

int main(){

    calc203<int> hi(5,3);
    // hi.printAll();
    vector<int> test = {1,2,3};
    hi.setVector(0,test);
    hi.setVector(1,test);
    hi.setVector(2,test);
    hi.setVector(3,test);
    hi.setVector(4,test);
    hi.scaleAll(3);
    hi.scaleAll(23);



    hi.printAll();

    return 0;
}