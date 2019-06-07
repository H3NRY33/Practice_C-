#ifndef __CALC203_H__
#define __CALC203_H__
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;
// NOTE: THIS IS MEANT TO WORK WITH SIGNED NUMBERS!
template<class Item>
class calc203{
    static const size_t DEF_SIZE = 3;
    public:
    // CONSTRUCTOR
    calc203();
    calc203(size_t numVectors,size_t dimenVector=DEF_SIZE);

    // COPY CONSTRUCTOR
    calc203(const calc203<Item>& Source);


    // MODIFICATION MEMBER FUNCTIONS.
    void setVector(size_t vectorNum,vector<Item> inputVector);

    // CONSTANT MEMBER FUNCTIONS.
    vector<Item> getVector(size_t vectorNum) const;

    size_t vecCount() const;

    void printVector(size_t vectorNum) const;

    // CALC FUNCTIONS.
    vector<Item> addVec(size_t indexA=0, size_t indexB=1);
    vector<Item> addAll();

    vector<Item> subVec(size_t indexA=0, size_t indexB=1);
    vector<Item> subAll(size_t indexA=0, size_t indexB=1);

    vector<Item> multVec(size_t indexA=0, size_t indexB=1);
    vector<Item> multAll(size_t indexA=0, size_t indexB=1);

    vector<Item> scaleVec(size_t vectorIndex, int scalar=1);
    vector<vector<Item> > scaleAll(int scalar=1);


    private:
    vector<vector<Item> > vectorList;
    size_t maxSize;

    template <class Item>
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
};
#endif