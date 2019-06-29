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
NodeHS::NodeHS(const NodeHS* Source){
    assert((isHash(Source->currentHash)) && (Source->stringValue.size() != 0));
    this->currentHash = Source->currentHash;
    this->stringValue = Source->stringValue;  
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
NodeHS* NodeHS::getValidLink() const{
    if(this->previous != NULL && this->next == NULL){
        return this->previous;
    }
    else if(this->next != NULL && this->previous == NULL){
        return this->next;
    }
    return NULL;
}
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
bool NodeHS::isSingle() const{
    return ((this->previous == NULL) && (this->next == NULL));
} 
bool NodeHS::strongLink()const{
    return ((this->previous != NULL) && (this->next != NULL));
}

// Node Modification
void doubleLink(NodeHS*& Node1, NodeHS*& Node2){
    if((Node1->getNext() == NULL) && (Node2->isSingle())){ // Make sure that "Node1" has nothing in front of it, and that "Node2" has NO links.
        Node1->setNext(Node2);
        Node2->setPrevious(Node1);
    }
}
void copyNode(const NodeHS* NodeSource, NodeHS*& NodeRecieve){
    delete NodeRecieve; // Delete the node that "NodeRecieve was pointing to"
    NodeRecieve= new NodeHS(NodeSource); // Make NodeReceive point to the new node created
}

// List Info
size_t list_length(NodeHS* headPtr){
    if(headPtr != NULL){
        NodeHS* CurrentNode = headPtr;
        size_t numberNodes = 0;
        while(CurrentNode != NULL){
            CurrentNode = CurrentNode->getNext();
            numberNodes++;
        }
        return numberNodes;
    }
    return 0;

}
NodeHS* list_tail(NodeHS* headPtr){
    if(headPtr != NULL){
        NodeHS* CurrentNode = headPtr;
        while(CurrentNode != NULL){
            CurrentNode = CurrentNode->getNext();
        }
        return CurrentNode;
    }
    return NULL;
}

// List manipulations.
void list_push(NodeHS* headPtr, NodeHS* newNode){
    NodeHS* lastNode = list_tail(headPtr);
    if(lastNode != NULL){
        doubleLink(lastNode,newNode);
    }
}
void list_clear(NodeHS*& headPtr){
    NodeHS* lastNode = list_tail(headPtr);
    if(lastNode != NULL){
        NodeHS* backNode = lastNode;
        NodeHS* frontNode = NULL;
        while(backNode != headPtr){
            frontNode = backNode;
            backNode = backNode->getPrevious();
            delete frontNode;
        }
    }
    delete headPtr;
}
void list_copy(NodeHS* SourcePtr, NodeHS*& newListHead){
    NodeHS* lastNode = list_tail(newListHead);
    if(lastNode != NULL){ // If the new list head has a list, then clear it. We are overwriting.
        list_clear(newListHead);
    }

    NodeHS* currentSource = SourcePtr; // Pointer used to iterate the source list.
    NodeHS* sentinel = NULL; // Dummy node used to make a copy of the source.

    newListHead = new NodeHS(); // "newListHead" is pointing to a dummy node.
    NodeHS* currentNew = newListHead; // Pointer used to build the new list along the way

    while(currentSource->getNext() != NULL){
        sentinel = new NodeHS(currentSource);
        doubleLink(currentNew,sentinel);
        currentSource = currentSource->getNext();
        currentNew = currentNew->getNext();
    }
    delete newListHead->getPrevious(); // Delete the dummy node we made in the beginning.
}
void list_head_insert(NodeHS*& headPtr, NodeHS*& newNode){
    if(headPtr != NULL){
        doubleLink(newNode,headPtr);
        headPtr = newNode;
    }
}
void list_head_remove(NodeHS*& headPtr){
    if(headPtr->getNext() != NULL){
        headPtr = headPtr->getNext();
        delete headPtr->getPrevious();
        return;
    }
    delete headPtr;
}
void list_insert(NodeHS*& previousPtr, NodeHS*& newNode){
    if(previousPtr != NULL && newNode != NULL){
        newNode->setNext(previousPtr->getNext());
        newNode->setPrevious(previousPtr);
        if(previousPtr->getNext() != NULL){
            previousPtr->getNext()->setPrevious(newNode);
        }
        previousPtr->setNext(newNode);
    }
}
NodeHS* findNode(NodeHS* headPtr, size_t targetIndex){
    NodeHS* CurrentNode = headPtr;
    size_t listLength = list_length(headPtr);
    size_t NodePosition = 0;

    while(NodePosition < listLength){
        if(NodePosition == targetIndex){
            return CurrentNode;
        }
        CurrentNode = CurrentNode->getNext();
        NodePosition++;
    }
    return NULL;
}
NodeHS* locateString(NodeHS* headPtr, string targetString){
    NodeHS* CurrentNode = headPtr;
    while(CurrentNode->getNext() != NULL){
        if((CurrentNode->getStrValue()) == targetString){
            return CurrentNode;
        }
        CurrentNode = CurrentNode->getNext();
    }
    return NULL;
}
NodeHS* locateHash(NodeHS* headPtr, string targetHash){
    NodeHS* CurrentNode = headPtr;
    while(CurrentNode->getNext() != NULL){
        if((CurrentNode->getHash()) == targetHash){
            return CurrentNode;
        }
        CurrentNode = CurrentNode->getNext();
    }
    return NULL;
}
void print_list(NodeHS* headPtr, bool printInfo){
    NodeHS* CurrentNode = headPtr;
    size_t nodeCount = 0;
    while(CurrentNode != NULL){
        if(printInfo){
            cout<<"NODE: "<<nodeCount<<"\n";
        }
        CurrentNode->printData();
        CurrentNode = CurrentNode->getNext();
        if(printInfo){
            nodeCount++;
        }
    }
    if(printInfo){
        cout<<"\nLIST LENGTH: "<<list_length(headPtr)<<"\n";
    }
}
void list_remove(NodeHS* previousPtr){
    NodeHS* futureNode = previousPtr->getNext()->getNext();
    delete previousPtr->getNext();
    previousPtr->setNext(futureNode);
    if(futureNode != NULL){
        futureNode->setPrevious(previousPtr);
    }
}

#endif