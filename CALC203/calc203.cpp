#ifndef __CALC203_CPP__
#define __CALC203_CPP__
#include "calc203.h"

// CONSTRUCTORS
template <class Item>
calc203<Item>::calc203(){
    maxSize = DEF_SIZE;
}
template <class Item>
calc203<Item>::calc203(size_t numVectors,size_t dimenVector=DEF_SIZE){
    maxSize = dimenVector;
    for(size_t i = 0; i < numVectors; i++){
        vector<Item> myVector(dimenVector);
        vectorList.push_back(myVector);
    }
}

// COPY CONSTRUCTOR
template <class Item>
calc203<Item>::calc203(const calc203<Item>& Source){
    this->vectorList = Source.vectorList;
    this->maxSize = Source.maxSize;
}

// MODIFICATION MEMBER FUNCTIONS.
template <class Item>
void calc203<Item>::setVector(size_t vectorNum,vector<Item> inputVector){
    if(vectorList.size() > vectorNum){
        vectorList[vectorNum] = inputVector;
    }
    else{
        cout<<"VECTOR INDEX IS NOT VALID\n";
    }
}

// CONSTANT MEMBER FUNCTIONS.
template <class Item>
vector<Item> calc203<Item>::getVector(size_t vectorNum) const{
    if(vectorList.size() > vectorNum){
        return vectorList[vectorNum];
    }
    else{
        cout<<"VECTOR INDEX IS NOT VALID\n";
        return vector<Item>();
    }
}
template <class Item>
size_t calc203<Item>::vecCount() const{
    return vectorList.size();
}

template <class Item>
void calc203<Item>::printVector(size_t vectorNum) const{
    if(vectorList.size() > vectorNum){
    printVec(vectorList[vectorNum],vectorNum);
    }
    else{
        cout<<"VECTOR INDEX IS NOT VALID\n";
    }
}


// CALC FUNCTIONS.
template <class Item>
vector<Item> calc203<Item>::addVec(size_t indexA=0, size_t indexB=1){
    vector<Item> ansVec(maxSize);
    if(indexA >=0 && indexB < vectorList.size()){
        if(vectorList[indexA].size() == vectorList[indexB].size()){
            for(size_t i = 0; i < maxSize; i++){
                ansVec[i]+=vectorList[indexA][i] + vectorList[indexB][i];
            }
        }
    }
    return ansVec;
}
template <class Item>
vector<Item> calc203<Item>::addAll(){
    vector<Item> totalSum(maxSize);
    size_t listSize = vectorList.size();
    if(!vectorList.empty()){
        for(size_t i = 0; i < listSize; i++){
            for(size_t j = 0; j < maxSize; j++){
                totalSum[j]+=vectorList[i][j];
            }
        }
    }
    return totalSum;
}

template <class Item>
vector<Item> calc203<Item>::subVec(size_t indexA=0, size_t indexB=1){
    
}

template <class Item>
vector<Item> calc203<Item>::multVec(size_t indexA=0, size_t indexB=1){}

template <class Item>
vector<Item> calc203<Item>::multAll(size_t indexA=0, size_t indexB=1){}

template <class Item>
vector<Item> calc203<Item>::scaleVec(size_t vectorIndex, int scalar=1){}

template <class Item>
vector<vector<Item> > calc203<Item>::scaleAll(int scalar=1){}



#endif