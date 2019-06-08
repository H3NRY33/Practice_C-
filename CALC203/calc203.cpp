#ifndef __CALC203_CPP__
#define __CALC203_CPP__
#include "calc203.h"

// CONSTRUCTORS
template <class Item>
calc203<Item>::calc203(){
    maxSize = DEF_SIZE;
}
template <class Item>
calc203<Item>::calc203(size_t numVectors,size_t vectorDimension = DEF_SIZE){
    maxSize = vectorDimension;
    previousAnswer(vectorDimension);
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
    this->previousAnswer = Source.previousAnswer;
}

// MODIFICATION MEMBER FUNCTIONS.
template <class Item>
void calc203<Item>::setVector(size_t vectorNum,vector<Item> inputVector){
    if(vectorList.size() > vectorNum && inputVector.size() == maxSize){
        vectorList[vectorNum] = inputVector;
    }
    else{
        cout<<"VECTOR INDEX/SIZE IS NOT VALID\n";
    }
}
template<class Item> 
void calc203<Item>::addVector(vector<Item> inputVector){
    if(inputVector.size() == maxSize){
        vectorList.push_back(inputVector);
    }
    else{
        cout<<"INPUT VECTOR DOES NOT MEET THE DIMENSION REQUIREMENTS!\n";
    }
}
template<class Item> 
void calc203<Item>::clearData(){
    vectorList.clear();
    previousAnswer.clear();
    maxSize = DEF_SIZE;
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

template<class Item> 
vector<Item> calc203<Item>::getPrevious() const{
return previousAnswer;
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
    vector<Item> vecSum(maxSize);
    if((vectorList.size() > indexA && vectorList.size() > indexB) && vectorList.size() >= 2){
        if(sameSize(vectorList[indexA],vectorList[indexB])){
            for(size_t i = 0; i < maxSize; i++){
                ansVec[i]+=vectorList[indexA][i] + vectorList[indexB][i];
            }
        }
    }
    if(!vecSum.empty()){
        previousAnswer = vecSum;
    }
    return vecSum;
}
template <class Item>
vector<Item> calc203<Item>::addAll(){
    vector<Item> totalSum(maxSize);
    size_t listSize = vectorList.size();
    if(sameDimension(vectorList)){
        for(size_t i = 0; i < listSize; i++){
            for(size_t j = 0; j < maxSize; j++){
                totalSum[j]+=vectorList[i][j];
            }
        }
    }
    if(!totalSum.empty()){
        previousAnswer = totalSum;
    }
    return totalSum;
}

template <class Item>
vector<Item> calc203<Item>::subVec(size_t indexA=0, size_t indexB=1){
    vector<Item> vecSub(maxSize);
    if(vectorList.size() > indexA && vectorList.size() > indexB){    
        if(sameSize(vectorList[indexA],vectorList[indexB])){
            for(size_t i = 0; i < maxSize; i++){
                vecSub[i] = vectorList[indexA][i] - vectorList[indexB][i];
            }
        }
    }
    if(!vectorSub.empty()){
        previousAnswer = vecSub;
    }
    return vecSub;
}

template <class Item>
vector<Item> calc203<Item>::multVec(size_t indexA=0, size_t indexB=1){
    vector<Item> vectorMult(maxSize);
     if(vectorList.size() > indexA && vectorList.size() > indexB){
         if(sameSize(vectorList[indexA],vectorList[indexB]){

         }

     }
}
// NOTE: NEED A SPECIAL CASE WHEN AN ELEMENT HAS A 0.
template <class Item>
vector<Item> calc203<Item>::multAll(){
    vector<Item> vecMult(maxSize);
    if(vectorList.size() >= 2){
        if(sameDimension(vectorList)){
            size_t listSize = vectorList.size();
            for(size_t i =0; i < listSize; i++){
                for(size_t j = 0; j < maxSize; j++){
                    vecMult[j]*=vectorList[i][j];
                }
            }
        }
    }
    if(!vecMult.empty()){
        previousAnswer = vecMult;
    }
    return vecMult;
}

template <class Item>
vector<Item> calc203<Item>::scaleVec(size_t vectorIndex, int scalar=1){}

template <class Item>
vector<vector<Item> > calc203<Item>::scaleAll(int scalar=1){}

template <class Item> 
vector<Item> calc203<Item>::cross(size_t indexA, size_t indexB){}



#endif