#ifndef __LAB9_H__
#define __LAB9_H__
#include <iostream> 
#include <cmath> 
#include <vector> 
#include <string>
#include <stack>
using namespace std;
// NOTE: MUST MAKE PARSER CLASS!! 
class LAB9{
// DEFAULT CONSTRUCTOR
public: 
LAB9();
// MODIFICATION MEMBER FUNCTIONS
// CONSTANT MEMBER FUNCTIONS
private: 
// INSERT PARSE ...
string PRIMARY_LABEL;
vector<string> DATA_LABELS = {"EXCELL_INIT","EXCELL","TEMP_K","KSP"};
vector<float> DATA;
vector<string> ANS_LABELS = {"[Ag]B","Delta_ECELL","MOLANION","TOTAL_VOLUME"};
vector<float> ANS_DATA;
float AgB;
float dECELL;
float molANION;
float totalVolume;
};
#include "LAB9.cpp"
#endif
