#ifndef __LAB9_CPP__
#define __LAB9_CPP__
#include "LAB9.h"

LAB9::LAB9(){
    PRIMARY_LABEL = "";
    for(vector<string>::iterator itr = DATA_LABELS.begin(); itr != DATA_LABELS.end(); itr++){
        DATA.push_back(0);
    }
    for(vector<string>::iterator itr2 = ANS_LABELS.begin(); itr2 != ANS_LABELS.end(); itr2++){
        ANS_DATA.push_back(0);
    }
    AgB = 0;
    dECELL = 0;
    molANION = 0;
    totalVolume = 0;
}

#endif