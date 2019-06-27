#ifndef __CALC203_CPP__
#define __CALC203_CPP__
#include "calc203.h"

// CONSTRUCTORS
template <class Item>
calc203<Item>::calc203(){
    maxSize = DEF_SIZE;
}
template <class Item>
calc203<Item>::calc203(size_t numVectors,size_t vectorDimension){
    maxSize = vectorDimension;
    for(size_t i = 0; i < numVectors; i++){
        vector<Item> myVector(vectorDimension);
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
void calc203<Item>::setVector(size_t vectorNum, vector<Item> inputVector){ // Set a new vector at a specific index within the vector of vectors.
    if(vectorList.size() > vectorNum && inputVector.size() == maxSize){ // Make sure vectorNum is an index within the range, make sure the input vector has the same dimensions as the other vectors.
        vectorList[vectorNum] = inputVector;
    }
    else{
        cout<<"VECTOR INDEX/SIZE IS NOT VALID\n";
    }
}
template<class Item> 
void calc203<Item>::addVector(vector<Item> inputVector){ // Make sure the vector has the correct dimensions and add it to the back of the vector of vectors.
    if(inputVector.size() == maxSize){
        vectorList.push_back(inputVector);
    }
    else{
        cout<<"INPUT VECTOR DOES NOT MEET THE DIMENSION REQUIREMENTS!\n";
    }
}
template<class Item> 
void calc203<Item>::clearData(){ // Clear all the data variables.
    vectorList.clear();
    previousAnswer.clear();
    maxSize = DEF_SIZE;
}

// CONSTANT MEMBER FUNCTIONS.
template <class Item>
vector<Item> calc203<Item>::getVector(size_t vectorNum) const{ // Get the contents of a vector at a specific index.
    if(vectorList.size() > vectorNum){
        return vectorList[vectorNum];
    }
    else{
        cout<<"VECTOR INDEX IS NOT VALID\n";
        return vector<Item>();
    }
}
template <class Item>
size_t calc203<Item>::vecCount() const{ // Return the number of vectors.
    return vectorList.size();
}

template<class Item> 
vector<Item> calc203<Item>::getPrevious() const{ // Get the vector that you previously accessed.
return previousAnswer;
}

template <class Item>
void calc203<Item>::printVector(size_t vectorNum) const{ // Print a vector at a specific index.
    if(vectorList.size() > vectorNum){
    printVec(vectorList[vectorNum],vectorNum);
    }
    else{
        cout<<"VECTOR INDEX IS NOT VALID\n";
    }
}
template <class Item> 
void calc203<Item>::printAll() const{ // Print the entire vector of vectors.
    size_t vecSize = vectorList.size();
    for(size_t i = 0; i < vecSize; i++){
        cout<<"<";
        for(size_t j = 0 ; j < maxSize; j++){
            cout<<vectorList[i][j];
            if(j != maxSize - 1){
                cout<<","<<setw(2);
            }
        }
        cout<<">\n";
    }
}

// CALC FUNCTIONS.
template <class Item>
vector<Item> calc203<Item>::addVec(size_t indexA, size_t indexB){ // Add two vectors and return the output vector.
    vector<Item> vecSum(maxSize);
    if((vectorList.size() > indexA && vectorList.size() > indexB) && vectorList.size() >= 2){
        if(sameSize(vectorList[indexA],vectorList[indexB])){
            for(size_t i = 0; i < maxSize; i++){
                vecSum[i]+=vectorList[indexA][i] + vectorList[indexB][i];
            }
        }
    }
    if(!vecSum.empty()){ // Store the answer as the previous vector accesed... Make sure it's not empty.
        previousAnswer = vecSum;
    }
    return vecSum;
}
template <class Item>
vector<Item> calc203<Item>::addAll(){ // Add all the components of the vector, all the X Y Z 
    vector<Item> totalSum(maxSize);
    size_t listSize = vectorList.size();
    if(sameDimension(vectorList)){ // Make sure that all the vectors are the same dimension.
        for(size_t i = 0; i < listSize; i++){
            for(size_t j = 0; j < maxSize; j++){
                totalSum[j]+=vectorList[i][j];
            }
        }
    }
    if(!totalSum.empty()){ // Store the answer in the previous vector.
        previousAnswer = totalSum;
    }
    return totalSum;
}

template <class Item>
vector<Item> calc203<Item>::subVec(size_t indexA, size_t indexB){ // Subtract the index of two vectors within the specified indexes.
    vector<Item> vecSub(maxSize);
    if(vectorList.size() > indexA && vectorList.size() > indexB){    
        if(sameSize(vectorList[indexA],vectorList[indexB])){
            for(size_t i = 0; i < maxSize; i++){
                vecSub[i] = vectorList[indexA][i] - vectorList[indexB][i];
            }
        }
    }
    if(!vecSub.empty()){
        previousAnswer = vecSub;
    }
    return vecSub;
}

template <class Item>
vector<Item> calc203<Item>::multVec(size_t indexA, size_t indexB){ // Multiply two vectors that are in the vector list.
    vector<Item> vecMult(maxSize);
     if(vectorList.size() > indexA && vectorList.size() > indexB){
         if(sameSize(vectorList[indexA],vectorList[indexB])){
             for(size_t i = 0; i < maxSize; i++){
                 vecMult*=vectorList[indexA][i] * vectorList[indexB][i];
             }
         }
     }
     if(!vecMult.empty()){
         previousAnswer = vecMult;
     }
     return vecMult;
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
vector<Item> calc203<Item>::scaleVec(size_t vectorIndex, int scalar){ // Multiply a vector at a specific element by a scalar.
    if(sameDimension(vectorList)){
        if(vectorList.size() > vectorIndex){
            for(size_t i = 0; i < maxSize; i++){
                vectorList[vectorIndex][i]*=scalar;
            }
        }
    }
    if(!vectorList[vectorIndex].empty()){
        previousAnswer = vectorList[vectorIndex];
    }
    return vectorList[vectorIndex];
}

template <class Item>
vector<vector<Item> > calc203<Item>::scaleAll(int scalar){ // Multiply all the vectors by a scalar.
    if(sameDimension(vectorList)){
        size_t listSize = vectorList.size();
        for(size_t i = 0; i < listSize; i++){
            for(size_t j = 0; j < maxSize; j++){
                vectorList[i][j]*=scalar;
            }
        }
    }
    return vectorList;
}
// NEEDS TESTING    == APPLY THE CROSS PRODUCT RULE  23 31 12 
template <class Item> 
vector<Item> calc203<Item>::cross(size_t indexA, size_t indexB){
    vector<Item> crossProduct;
    if(vectorList.size() > indexA && vectorList.size() > indexB){
        if(sameSize(vectorList[indexA],vectorList[indexB]) && maxSize == 3){ // CROSS PRODUCT RULE        
            crossProduct.push_back(vectorList[indexA][1]*vectorList[indexB][2]) -(vectorList[indexA][2]*vectorList[indexB][1]);        
            crossProduct.push_back(vectorList[indexA][2]*vectorList[indexB][0]) -(vectorList[indexA][0]*vectorList[indexB][2]); 
            crossProduct.push_back(vectorList[indexA][0]*vectorList[indexB][1]) -(vectorList[indexA][1]*vectorList[indexB][0]);                                   
        }
    }
    if(!crossProduct.empty()){
        previousAnswer = crossProduct;
    }
    return crossProduct;
}

#endif