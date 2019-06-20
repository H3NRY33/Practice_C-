#ifndef __CALC203_H__
#define __CALC203_H__
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;
// NOTE: THIS IS MEANT TO WORK WITH SIGNED TYPES!
template<class Item>
class calc203{
    static const size_t DEF_SIZE = 3;
    public:
    // CONSTRUCTOR
    calc203();
    calc203(size_t numVectors,size_t vectorDimension = DEF_SIZE);

    // COPY CONSTRUCTOR
    calc203(const calc203<Item>& Source);


    // MODIFICATION MEMBER FUNCTIONS.
    void setVector(size_t vectorNum,vector<Item> inputVector);
    void addVector(vector<Item> inputVector);
    void clearData();

    // CONSTANT MEMBER FUNCTIONS.
    vector<Item> getVector(size_t vectorNum) const;
    vector<Item> getPrevious() const;
    void printVector(size_t vectorNum) const;
    void printAll() const;
    size_t vecCount() const;

    // CALC FUNCTIONS.
    vector<Item> addVec(size_t indexA=0, size_t indexB=1);
    vector<Item> addAll();

    vector<Item> subVec(size_t indexA=0, size_t indexB=1);

    vector<Item> multVec(size_t indexA=0, size_t indexB=1);
    vector<Item> multAll();

    vector<Item> scaleVec(size_t vectorIndex, int scalar=1);
    vector<vector<Item> > scaleAll(int scalar=1);
    vector<Item> cross(size_t indexA, size_t indexB);

    private:
    vector<vector<Item> > vectorList;
    vector<Item> previousAnswer;
    size_t maxSize;

    void printVec(vector<Item> vectorAns, int vectorNum = -1) const{
        if(vectorNum != -1){
            cout<<"\n"<<vectorNum<<": ";
        }
        cout<<"{";
        for(size_t i = 0; i < vectorAns.size(); i++){
            cout<<vectorAns[i];
            if(i != vectorList[vectorNum].size() - 1){
                cout<<","<<setw(2);
            }
        }
        cout<<"}\n";
    }

    bool sameSize(vector<Item> vector1, vector<Item> vector2){
        return((vector1.size() == maxSize) && (vector2.size() == maxSize));
    }

    bool sameDimension(vector<vector<Item> > vectorCheck){
        if(!vectorCheck.empty()){
            size_t vectorSize = vectorCheck.size();
            for(size_t i = 0; i < vectorSize; i++){
                if(vectorCheck[i].size() != maxSize){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};
#include "calc203.cpp"
#endif