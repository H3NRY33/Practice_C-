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
void setLink(NodeHS* nextNode); // Set link to the next node.
void setPrevious(NodeHS* previousNode); // Set link to the previous node.
void setHash(const string& newHash); // Set the SHA256 value.
void setString(const string& newString); // Set the plain string value.
void clearData(); // Clear the contents of the hash and the plain string value.

// CONSTANT MEMBER FUNCTIONS.
NodeHS* getLink() const; // Get a pointer to the next node.
NodeHS* getPrevious() const; // Get a pointer of the node that is pointing to this node.
void printData() const; // Print the Hash and String value.
string getHash() const; // Return a string containing a hash value.
string getStrValue() const;// Return a string containing the plain string value.
char hashAt(size_t Index)const;// Get the hash value at a specific index.
char stringAt(size_t Index) const;// Get the plain string at a specific index.
size_t getStrValueLength() const; // Get the length of the string value.
bool isEmpty(); // Check if there is data in the node.

private: 
string currentHash; // Stores the SHA256 Value of the String.
string stringValue; // Stores the word value of the Hash.
NodeHS* link; // Pointer to the next node.
NodeHS* previous; // Pointer to the previous node.

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
        if(capsOccurance == maxOccurance && capsOccurance != lowerOccurance){
            modifyLower = 65;
            modifyUpper = 90;
            return;
        }
        else if(lowerOccurance == maxOccurance && lowerOccurance !=capsOccurance){
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
#include "NodeHS.cpp"
#endif


