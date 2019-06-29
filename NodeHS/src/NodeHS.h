#ifndef __NODEHS_H__
#define __NODEHS_H__
#include <iostream> 
#include <iomanip>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <string> 
using namespace std;

class NodeHS{

public: 
// CONSTRUCTOR.
NodeHS();
NodeHS(string initialHash, string initialValue, NodeHS* previousLink=NULL, NodeHS* nextLink=NULL);

// COPY CONSTRUCTOR.
NodeHS(const NodeHS& Source);
NodeHS(const NodeHS* Source);

// MODIFICATION MEMBER FUNCTIONS.
void setPrevious(NodeHS* previousNode); // Set link to the previous node.
void setNext(NodeHS* nextNode); // Set link to the next node.
void setString(const string& newString); // Set the plain string value.
void setHash(const string& newHash); // Set the SHA256 value.
void clearData(); // Clear the contents of the hash and the plain string value.

// CONSTANT MEMBER FUNCTIONS.
NodeHS* getValidLink() const;
NodeHS* getPrevious() const; // Get a pointer of the node that is pointing to this node.
NodeHS* getNext() const; // Get a pointer to the next node.
string getStrValue() const;// Return a string containing the plain string value.
string getHash() const; // Return a string containing a hash value.
void printData() const; // Print the Hash and String value.
char stringAt(size_t Index) const;// Get the plain string at a specific index.
char hashAt(size_t Index) const;// Get the hash value at a specific index.
size_t getStrValueLength() const; // Get the length of the string value.
bool isEmpty() const; // Check if there is data in the node.
bool isSingle() const; // Return whether or not the Node has NO LINKS
bool strongLink() const; // Returns whether or not the Node has a previous AND next node.

private: 
string currentHash; // Stores the SHA256 Value of the String.
string stringValue; // Stores the word value of the Hash.'NodeHS* previous; // Pointer to the previous node.
NodeHS* previous; // Pointer to the previous node.
NodeHS* next; // Pointer to the next node.

// Function used to set the bounds on whether the Hash "HashCheck" should have all lower case letters or upper case letters.
void setBounds(string HashCheck,int& modifyLower, int& modifyUpper){
int capsOccurance = 0, lowerOccurance = 0; // Variables used to keep track of lower and UPPER case letters.
int maxOccurance = 8; // The the amount of occurances that must be reached to set the bounds.
 for(string::iterator i = HashCheck.begin(); i != HashCheck.end(); i++){
        if(((int)(*i) >= 65) && ((int)(*i) <= 90)){ // Checks for UPPERCASE LETTERS.
        capsOccurance++;
        }
        if(((int)(*i) >= 97) && ((int)(*i) <= 122)){ // Checks for lowercase letters.
        lowerOccurance++;
        }
        // Once the count of lower case or uppercase letter reach maxOccurance, then set the bounds.
        if(capsOccurance == maxOccurance && capsOccurance > lowerOccurance){ // Once caps threshhold has been reached.
            modifyLower = 65;
            modifyUpper = 90;
            return;
        }
        else if(lowerOccurance == maxOccurance && lowerOccurance > capsOccurance){// Once lower threshold has been reached.
            modifyLower = 97;
            modifyUpper = 122;
            return;
        }
    }
}
// Function that checks whether the given input string is an acceptable Hash.
bool isHash(string HashCheck){
    if(HashCheck.size() != 64){ // Checks for the correct ascii size.
        return false;
    }
    int lowerBound = 0, upperBound = 0; // Bounds to check for lower case or upper case.
    setBounds(HashCheck,lowerBound,upperBound); // Set the bounds for the case sensitivity.
    for(string::iterator i = HashCheck.begin(); i != HashCheck.end(); i++){
        if(((int)(*i) < lowerBound || (int)(*i) > upperBound)){ // Check if value is not a letter.
                if((int)(*i) < 48 || (int)(*i) > 57){ // Check if value is not a NUMBER.
                    return false;
                }
        }
    }
    return true;
}
};
// Node Modification
void doubleLink(NodeHS*& Node1, NodeHS*& Node2); // Set nodes next to node2, set Node2 previous to node1
void copyNode(const NodeHS* NodeSource, NodeHS*& NodeRecieve); // Copies all the contents from NodeSource and makes NodeRecieve point to it.

// List Info
size_t list_length(NodeHS* headPtr);


NodeHS* list_tail(NodeHS* headPtr);

// List Modification.
void list_push(NodeHS* headPtr, NodeHS* newNode); 
void list_clear(NodeHS*& headPtr);
void list_copy(NodeHS* SourcePtr, NodeHS*& newListHead);
void list_head_insert(NodeHS*& headPtr, NodeHS* newEntry);
void list_head_remove(NodeHS*& headPtr);


void list_insert(NodeHS* previousPtr, NodeHS* newNode);
size_t list_length(const NodeHS* headPtr);

NodeHS* list_copy(NodeHS* SourcePtr); 
NodeHS* findNode(NodeHS* headPtr, size_t Index);
NodeHS* locateString(NodeHS* headPtr);
NodeHS* locateHash(NodeHS* headPtr);

void print_list(const NodeHS* headPtr, bool printLength=false);
void list_remove(NodeHS* previousPtr);

#include "NodeHS.cpp"
#endif


