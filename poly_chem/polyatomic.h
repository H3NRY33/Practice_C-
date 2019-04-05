//UPDATED : 4/5/19
#include<iostream>
#include<cstdio>
#include<cctype>
#include<string>
#include<cassert>

using namespace std;

class polyatomic{

public:

// Set all private variables to private.
polyatomic();
polyatomic(const polyatomic& previousGame);

// Set FUNCTIONS
void setPoly(const size_t& newPoly);
void setSection(const size_t& section);

// Ask FUNCTION ... prints out asking what we want.
void askPrint()const;

// Print whether the user was wrong or right ...WIP
void checkAns(const string& ans) const;
string correctAns() const; // Display the absoulute correct answer
void printAns() const; // Used to print the correct polyatomic ion for printing

void scoreUpdate(const bool& correct); // Update the player's current score.
void streakUpdate(const bool& change); //Check to see if streak is still valid.
void masteryUpdate();         // Adjust the mastery according to the user's correct answers.

// Get FUNCTIONS
string currPoly(const size_t& option) const;   // Checks if we were right or wrong

// Gets the values of the indexes for the array
size_t getSectionVal() const; // returns array value containing charge, compounds, or compound name
size_t getPolyVal() const;    // returns array for specific polyatomic ion


size_t getScore() const;   // Return the user's score.
size_t getStreak() const; // Return the current streak count.
size_t getMxStreak() const; // Return the highest streak so far.
bool get_wRight() const; // Return whether or not the user was completley right.
double getMastery() const; // Compute the mastery based on the player's highest streak

private:
size_t currentPoly; // The corect polyatomic ion
size_t currentSection; // what do we want from user 1- charge. 2 = compount. 3- compound name

size_t score; // Track of user's score.
size_t streakCount; // What is the streak so far.
size_t maxStreak; // Keeps track of the highest streak the user has had of correct answers.
bool wasRight; // Check if you were right before.
double mastery; // Store's the user's current mastery.

const static size_t polyInfo = 4; // number of sections, Array at 0 is used for display purposes only
const static size_t totalPoly = 13; //the current number of polyatomic ions
const string polyData[polyInfo][totalPoly] = {
{"NH₄⁺","NO₃⁻","SO₄²⁻","OH⁻","CN⁻","C₂H₃O₂⁻","MnO₄⁻","PO₄³⁻","CO₃²⁻","HCO₃⁻","ClO₃⁻","Cr₂O₇²⁻","CrO₄²⁻"},                                              //0 =     ELEMENT PRINT[],
{"+","-","2-","-","-","-","-","2-","2-","-","-","2-","2-"},                                                                                             //1 =     CHECK CHARGE[], 
{"NH4","NO3","SO4","OH","CN","C2H3O2","MnO4","PO4","CO3","HCO3","ClO3","Cr2O7","CrO4"},                                                                 //2 =     CHECK COMPOUND[],                 
{"AMMONIUM","NITRATE","SULFATE","HYDROXIDE","CYANIDE","ACETATE","PERMANGANATE","PHOSPHATE","CARBONATE","BICARBONATE","CHLORATE","DICHROMATE","CHROMATE"}//3 =     CHECK COMP_NAME[]
};

};