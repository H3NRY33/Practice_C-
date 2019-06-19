#ifndef __NODEHS_H__
#define __NODEHS_H__
#include <iostream> 
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string> 
using namespace std;

class NodeHS{

public: 
// CONSTRUCTOR.
NodeHS();
NodeHS(string initialHash, string initialValue,NodeHS* previous=NULL, NodeHS* link=NULL);
// COPY CONSTRUCTOR.
NodeHS(const NodeHS& Source);

// MODIFICATION MEMBER FUNCTIONS.
void setLink(NodeHS* nextNode);
void setPrevious(NodeHS* previousNode);

void setHash(const string& newHash);
void setString(const string& newString);

void clearData();

// CONSTANT MEMBER FUNCTIONS.
NodeHS* getLink() const;
NodeHS* getPrevious() const;

void printData() const;
string getHash() const;
string getStrValue() const;
char hashAt(size_t Index)const;
char stringAt(size_t Index) const;

size_t getStrValueLength() const;

bool isEmpty();

private: 
string currentHash;
string stringValue;
NodeHS* link;
NodeHS* previous;
};

#endif


