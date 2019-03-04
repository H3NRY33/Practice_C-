#include "polyatomic.h"

// Constructor
polyatomic::polyatomic(){
    score = 0;
    currentPoly = 0;
    maxStreak = 0;
    streakCount = 0;
    wasRight = false;
}

// Updates the current polyatomic ion.
void polyatomic::getPoly(const size_t& randPoly){
    currentPoly =  randPoly;
}


// OMIT PRINT FOR NOW .. WOP
 void polyatomic::checkAns(const string& ans) const{
//convert to upperCase 
string capsAns ="";
for (size_t i = 0 ; i < ans.size(); i++){
    capsAns+=toupper(ans[i]);
}
cout<<"capsAns: "<<capsAns<<endl;

string rightString = polyData[3][currentPoly];
string rightCompound = polyData[2][currentPoly];
string rightCharge = polyData[1][currentPoly];
cout<<"rightAns: "<<rightString<<endl;



 }


// Only increment the score if the user has been correct.
void polyatomic::scoreUpdate(const bool& correct){
    if(correct){score+=1;}
}
// Update the streak after the user has been right or not.
void polyatomic::streakUpdate(const bool& change){
    if(change){
        streakCount+=1;
        wasRight = true;
        if(streakCount > maxStreak){maxStreak = streakCount;}
    }
    if(!change){
        wasRight = false;
        if(streakCount > maxStreak){maxStreak = streakCount;}
        streakCount = 0;
    }
}
// Update the mastery value based on the highest amount of correct numbers.
void polyatomic::masteryUpdate(){
    mastery = maxStreak/totalPoly;
}


// Get FUNCTIONS
size_t polyatomic::currPoly() const{ return currentPoly;}
size_t polyatomic::getStreak() const{ return streakCount;}
size_t polyatomic::getMxStreak() const{ return maxStreak;}
size_t polyatomic::getScore() const{ return score;}
bool polyatomic::get_wRight() const{ return wasRight;}
double polyatomic::getMastery() const{ return mastery;}


