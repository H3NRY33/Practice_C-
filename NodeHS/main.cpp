#include <iostream> 
#include "src/NodeHS.h"
using namespace std;

int main(){
    //Create Double Linked list. 

    
    NodeHS* testNode = new NodeHS("a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e","testString",NULL,NULL);
    NodeHS* testNode1 = new NodeHS("a591a6d40bf420404a011733cfb7c190d62c65bf0bcda32b57b277d9ad9f146e","testString",NULL,NULL);
    NodeHS* testNode2 = new NodeHS("a391a6d40bf420404a011733cfb7c120d62c65bf0bcda32b57b247d9ad9f146e","testString",NULL,NULL);
    NodeHS* testNode3 = new NodeHS("a391a6d40bf420404a011733cfb7c120d62c63bf0bcda32b57b247d9ad9f146e","testString",NULL,NULL);

    NodeHS* headPtr = testNode; // Set the head pointer
    

    testNode->setNext(testNode1);
    testNode1->setNext(testNode2);
    testNode2->setNext(testNode3);

    testNode->setPrevious(NULL);
    testNode1->setPrevious(testNode);
    testNode2->setPrevious(testNode2);







    cout<<"SUCESS!\n";
    return 0;
}