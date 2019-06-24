#ifndef __NODEHS_CPP__
#define __NODEHS_CPP__
#include "NodeHS.h"

// CONSTRUCTOR.
NodeHS::NodeHS(){
    this->currentHash = "";
    this->stringValue = "";
    this->previous = NULL;
    this->next = NULL;
}
NodeHS::NodeHS(string initialHash, string initialValue, NodeHS* previousLink, NodeHS* nextLink){
    assert((isHash(initialHash)) && (initialValue.size() != 0));
    this->currentHash = initialHash;
    this->stringValue = initialValue;
    this->previous = previousLink;
    this->next = nextLink;
}

// COPY CONSTRUCTOR.
NodeHS::NodeHS(const NodeHS& Source){
    assert((isHash(Source.currentHash)) && (Source.stringValue.size() != 0));
    this->currentHash = Source.currentHash;
    this->stringValue = Source.stringValue;
}

// MODIFICATION MEMBER FUNCTIONS.
void NodeHS::setPrevious(NodeHS* previousNode){
    this->previous = previousNode;
}
void NodeHS::setNext(NodeHS* nextNode){
    this->next = nextNode;
}
void NodeHS::setString(const string& newString){
    this->stringValue = newString;
}
void NodeHS::setHash(const string& newHash){
    assert(isHash(newHash));
    this->currentHash = newHash;
}
void NodeHS::clearData(){
    assert((this->currentHash.size() != 0) && (this->stringValue.size() != 0));
    this->currentHash = "";
    this->stringValue = "";
}

// CONSTANT MEMBER FUNCTIONS.
NodeHS* NodeHS::getPrevious() const{
    return previous;
}
NodeHS* NodeHS::getNext() const{
    return next;
}
string NodeHS::getStrValue() const{
    return stringValue;
}
string NodeHS::getHash() const{
    return currentHash;
}
void NodeHS::printData() const{
    cout<<"CURRENT_HASH:"<<setw(2)<<currentHash<<"\n";
    cout<<"STRING_VALUE:"<<setw(2)<<stringValue<<"\n";
}
char NodeHS::stringAt(size_t Index) const{
    assert((Index >= 0) && (Index < stringValue.size()));
    return stringValue[Index];
}
char NodeHS::hashAt(size_t Index) const{
    assert((Index >= 0) && (Index < 64));
    return currentHash[Index];
}
size_t NodeHS::getStrValueLength() const{
    return stringValue.size();
}
bool NodeHS::isEmpty() const{
    return (stringValue.size() == 0 && currentHash.size() == 0);
}
#endif