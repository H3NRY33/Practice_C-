#ifndef __NODEHS_CPP__
#define __NODEHS_CPP__
#include "NodeHS.h"

// CONSTRUCTOR.
NodeHS::NodeHS(){
    currentHash = "";
    stringValue = "";
    link = NULL;
    previous = NULL;
}
NodeHS::NodeHS(string initialHash, string initialValue,NodeHS* previous, NodeHS* link){
    this->stringValue = initialValue;
    this->previous = previous;
    this->link = link;
    if(isHash(initialHash)){
    this->currentHash = initialHash;
    }else{
    cout<<"NOT A VALID HASH!\n";
    }
}

// COPY CONSTRUCTOR.
NodeHS::NodeHS(const NodeHS& Source){
    this->currentHash = Source.currentHash;
    this->stringValue = Source.stringValue;
}

// MODIFICATION MEMBER FUNCTIONS.
void NodeHS::setLink(NodeHS* nextNode){
    this->link = nextNode;
}
void NodeHS::setPrevious(NodeHS* previousNode){
    this->previous = previousNode;
}

void NodeHS::setHash(const string& newHash){
    this->currentHash = newHash;
}
void NodeHS::setString(const string& newString){
    this->stringValue = newString;
}

void NodeHS::clearData(){
    this->currentHash = "";
    this->stringValue = "";
}

// CONSTANT MEMBER FUNCTIONS.
NodeHS* NodeHS::getLink() const{
    return link;
}
NodeHS* NodeHS::getPrevious() const{
    return previous;
}

void NodeHS::printData() const{
    cout<<"CURRENT_HASH:"<<setw(2)<<currentHash<<"\n";
    cout<<"STRING_VALUE:"<<setw(2)<<stringValue<<"\n";
}
string NodeHS::getHash() const{
    return currentHash;
}
string NodeHS::getStrValue() const{
    return stringValue;
}
char NodeHS::hashAt(size_t Index)const{
    return currentHash[Index];
}
char NodeHS::stringAt(size_t Index)const {
    return stringValue[Index];
}

size_t NodeHS::getStrValueLength() const{
    return stringValue.size();
}

bool NodeHS::isEmpty(){
    return (stringValue.size() == 0 && currentHash.size() == 0);
}

#endif