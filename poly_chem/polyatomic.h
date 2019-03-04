#include<iostream>
#include<cstdio>
#include<cctype>
#include<string>


using namespace std;

class polyatomic{

public:

// Set all private variables to private.
polyatomic();
polyatomic(const polyatomic& previousGame);
// Get the random poly chosen by the 


void getPoly(const size_t& randPoly);

// Print whether the user was wrong or right
void checkAns(const string& ans) const;

void scoreUpdate(const bool& correct); // Update the player's current score.
void streakUpdate(const bool& change); //Check to see if streak is still valid.
void masteryUpdate();         // Adjust the mastery according to the user's correct answers.

// Get FUNCTIONS
size_t currPoly() const;   //Return the user's current poly
size_t getScore() const;   // Return the user's score.
size_t getStreak() const; // Return the current streak count.
size_t getMxStreak() const; // Return the highest streak so far.
bool get_wRight() const; // Return whether or not the user was completley right.
double getMastery() const; // Compute the mastery based on the player's highest streak

private:
size_t currentPoly; // The corect polyatomic ion

size_t score; // Track of user's score.
size_t streakCount; // What is the streak so far.
size_t maxStreak; // Keeps track of the highest streak the user has had of correct answers.
bool wasRight; // Check if you were right before.
double mastery; // Store's the user's current mastery.

const static size_t polyInfo = 4;
const static size_t totalPoly = 13;
const string polyData[polyInfo][totalPoly] = {
{"NH₄⁺","NO₃⁻","SO₄²⁻","OH⁻","CN⁻","C₂H₃O₂⁻","MnO₄⁻","PO₄³⁻","CO₃²⁻","HCO₃⁻","ClO₃⁻","Cr₂O₇²⁻","CrO₄²⁻"},                                              //0 =     ELEMENT PRINT[],
{"+","-","2-","-","-","-","-","2-","2-","-","-","2-","2-"},                                                                                             //1 =     CHECK CHARGE[], 
{"NH4","NO3","SO4","OH","CN","C2H3O2","MnO4","PO4","CO3","HCO3","ClO3","Cr2O7","CrO4"},                                                                 //2 =     CHECK COMPOUND[],                 
{"AMMONIUM","NITRATE","SULFATE","HYDROXIDE","CYANIDE","ACETATE","PERMANGANATE","PHOSPHATE","CARBONATE","BICARBONATE","CHLORATE","DICHROMATE","CHROMATE"}//3 =     CHECK COMP_NAME[]
};

};