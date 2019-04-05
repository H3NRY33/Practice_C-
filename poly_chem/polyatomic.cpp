//UPDATED : 4/5/19
#include "polyatomic.h"
#ifndef POLYATOMIC_CPP
#define POLYATOMIC_CPP
// Constructor
polyatomic::polyatomic(){
    score = 0;
    currentPoly = 0; // deailt NH4
    currentSection = 0; //default to NH4+ display
    maxStreak = 0;
    streakCount = 0;
    wasRight = false;
}

// Updates the current polyatomic ion.
void polyatomic::setPoly(const size_t& newPoly){
    currentPoly =  newPoly;
}
// Updates what we want from the user 
void polyatomic::setSection(const size_t& section){
    currentSection = section;
}


// OMIT PRINT FOR NOW .. W_P
void polyatomic::askPrint()const{
    string need;
    switch((int)getSectionVal()){
        case 1: need = "charge";            break;
        case 2: need = "molecular formula"; break;
        case 3: need = "compound name";     break;
        default: need = "NULL";              break;
    }
    cout<<"\nMay we please get the "<<need<<"?\n";
}

// Checks for the correct answer
void polyatomic::checkAns(const string& ans) const{
//convert to upperCase 
    string answer_caps ="";
    for (size_t i = 0 ; i < ans.size(); i++){
        answer_caps+=toupper(ans[i]);
    }

    string rightAnswer = polyData[getSectionVal()][getPolyVal()];
    if (rightAnswer == answer_caps){
    cout<<"CORRECT!\n";
    }
    else{
        cout<<"INCORRECT\n";
    }
}

// Displaying Answers
string polyatomic::correctAns() const{
    return (polyData[getSectionVal()][getPolyVal()]);
}
// For Printing nicely .. DOESNT PRINT SO NICE ACTUALLY ....
void polyatomic::printAns() const{
    string printMe = polyData[(size_t)0][getPolyVal()];
    cout<<printMe<<endl;
}

// Only increment the score if the user has been correct.
void polyatomic::scoreUpdate(const bool& correct){
    if(correct){
        score+=1;
    }
    else{
        if(score != 0){
            score-=1;
        }
    }
}

// Update the streak after the user has been right or not.
void polyatomic::streakUpdate(const bool& change){
    if(change){
        streakCount+=1;
        wasRight = true;
        if(streakCount > maxStreak){
            maxStreak = streakCount;
        }
    }
    if(!change){
        wasRight = false;
        if(streakCount < maxStreak){
            maxStreak = streakCount;
        }
        streakCount = 0;
    }
}

// Update the mastery value based on the highest amount of correct numbers.
void polyatomic::masteryUpdate(){
    if(!get_wRight()){
        mastery = 0;
    }
    else{
        mastery = maxStreak/totalPoly;
    }
}

// Get FUNCTIONS ... maybe you have something specific in mind?
//what do we want from user 1 = charge. 2 = compount. 3- compound name
string polyatomic::currPoly(const size_t& option) const{
    assert(option != 0);
    string polyInfo;
    switch(option){
        case 1: polyInfo = polyData[option][getPolyVal()];   break;
        case 2: polyInfo = polyData[option][getPolyVal()];    break;
        case 3: polyInfo = polyData[option][getPolyVal()];    break;
        default: cout<<"NOT A VALID OPTION\n"; polyInfo = "0";   break;
    }
     return polyInfo;
}

// Get FUNCTIONS for data indexes
size_t polyatomic::getSectionVal() const{
    return currentSection;
}
size_t polyatomic::getPolyVal() const{
    return currentPoly;
}

// other Get FUNCTIONS
size_t polyatomic::getStreak() const{ return streakCount;}
size_t polyatomic::getMxStreak() const{ return maxStreak;}
size_t polyatomic::getScore() const{ return score;}
bool polyatomic::get_wRight() const{ return wasRight;}
double polyatomic::getMastery() const{ return mastery;}

#endif

