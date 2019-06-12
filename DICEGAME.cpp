#include <iostream>
#include <time.h>		   //for srand seed generator
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <thread>         // std::this_thread::sleep_for  --- SLEEP TIMER
#include <chrono>         // std::chrono::seconds    --- SLEEP TIMER
#include <vector>
using namespace std; 
/*
Make a program that simulates a dive game between you and the computer 
S: 10/3/18 --- 95% complete
*/

void dicePrint(int die){	
vector<char> top;
vector<char> mid;
vector<char> bot;
//creates the vectors that show the dice
for (int j = 0 ; j < 13 ; j++){ //CREATES THE SET OF DICE IN EACH VECTOR
    switch(j){
    case 0 : mid.push_back('*'); top.push_back((char)32);bot.push_back((char)32); break;
    case 1 : mid.push_back('*'); top.push_back((char)32);bot.push_back((char)32); break;
    case 2 : bot.push_back('*'); top.push_back((char)32);mid.push_back((char)32); break;
    case 3 : mid.push_back('*'); top.push_back((char)32);bot.push_back((char)32); break;
    case 4 : top.push_back('*'); mid.push_back((char)32);bot.push_back((char)32); break;
    case 5 : top.push_back('*'); bot.push_back('*'); mid.push_back((char)32); break;
    case 7 : top.push_back('*'); bot.push_back('*'); mid.push_back((char)32); break;
    case 8 : mid.push_back('*'); top.push_back((char)32); bot.push_back((char)32); break;
    case 9 : top.push_back('*'); bot.push_back('*'); mid.push_back((char)32); break;
    case 10 :top.push_back('*'); mid.push_back('*'); bot.push_back('*'); break;
    case 12 :top.push_back('*'); mid.push_back('*'); bot.push_back('*'); break;
    default: top.push_back((char)32); mid.push_back((char)32); bot.push_back((char)32);break;
    }	
}
    switch(die){ //PRINTS OUT THE DIE ACCORDING to the value found. We only print the die where it exists in each level
    case 1: cout<<top[0]<<"\n"<<mid[0]<<"\n"<<bot[0]; break;
    case 2: cout<<top[0]<<top[1]<<"\n"<<mid[0]<<mid[1]<<"\n"<<bot[0]<<bot[1]; break;
    case 3: cout<<top[2]<<top[3]<<top[4]<<"\n"<<mid[2]<<mid[3]<<mid[4]<<"\n"<<bot[2]<<bot[3]<<bot[4]; break;
    case 4: cout<<top[5]<<top[6]<<top[7]<<"\n"<<mid[5]<<mid[6]<<mid[7]<<"\n"<<bot[5]<<bot[6]<<bot[7]; break;
    case 5: cout<<top[7]<<top[8]<<top[9]<<"\n"<<mid[7]<<mid[8]<<mid[9]<<"\n"<<bot[7]<<bot[8]<<bot[9]; break;
    case 6: cout<<top[10]<<top[11]<<top[12]<<"\n"<<mid[10]<<mid[11]<<mid[12]<<"\n"<<bot[10]<<bot[11]<<bot[12]; break;
    default: cout<<"\n"<<"\n"<<"\n"; break;
    }	
}
//simple function that acts as a timer
void waitFor(int timeWait){
this_thread::sleep_for(chrono::seconds(timeWait));
}//END "waitFor"

//function that turns every element within a string to uppercase
string to_upper(string &upper){
	for(int i = 0 ; i<=upper.length();i++){
		upper[i] = toupper(upper[i]);
	}
return upper;	
}//END "to_upper"

//function that checks for a valid reply from the user
void checkPlay(string& inp, bool& ans){
bool validReply = false;
//while loop that makes sure that the user is passing the correct input
	while (validReply == false){
	 	cin >> inp;
	 	to_upper(inp);
	 	
		if ((inp == "NO") || (inp == "N")){
		ans = false;
		validReply = true;
		break;
		}
		if ((inp == "YES") || (inp == "Y")) {
		ans = true;
		validReply = true;
		break;
		}
	printf("%s\n","PLEASE ENTER A VALID REPLY");	
	}
}//END "checkPlay;


//function that simulates the dice roll
void rollDice(bool& roller){
//declares dice , the sum of dice, and correct pronoun
size_t d1, d2, dsum = 0;
string entity;
//adjusts to the user's correct pronoun *triggered == off 
	if(roller == false) {
		entity = "MY";
		srand((unsigned)time(NULL));
	}
	if(roller == true){
		entity = "YOUR";
		srand((unsigned)5 + (unsigned)time(NULL));
	} 
	
//stores the random "roll" for each dice 
d1 = (rand()%5)+1;
d2 = (rand()%5+1);
dsum = d1 + d2;
	
//outputs the roll results

cout<<entity<<" ROLL:\n\n\t";
waitFor(2);
cout<<d1<<"\t";
waitFor(2);
cout<<"\t"<<d2<<"\n\n";
waitFor(1);
cout<<entity<<" SCORE: "<<dsum<<"\n";
//adjust for the next roller
roller = !roller;		
} //END "rollDice"


int main(int argc, char const *argv[]){
//keeps track of the player's score
int p1Score, p2Score  = 0;
//records the user's response 
string response;
//boolean that determines if user wants to keep rolling 
bool keepRolling = true;
//boolean that keeps track of who is rolling the dice 
bool userRoll = false;

//program while loop
	while (keepRolling == true){
		system("CLS");

//checks to see if user wants to play 
	printf("%s\n","LET'S ROLL SOME DICE !!! ");
	waitFor(2);	
	system("CLS");
	printf("%s\n","ARE YOU IN? (YES or NO)");
	checkPlay(response,keepRolling);
		if(keepRolling == false){
		break;
		}	
	waitFor(1);	
	system("CLS");

//COMPUTER ROLL
	printf("%s\n","I'LL ROLL FIRST");
	waitFor(1);
	for(int i = 0 ; i<=6 ; i++){
	dicePrint(i);
	waitFor(2);
	system("CLS");
}
	system("CLS");
	printf("%s\n","ROLLING ...");
	rollDice(userRoll);
	waitFor(1);
	printf("\n%s\n","NOW YOU ROLL");

//USER ROLL
	waitFor(1);	
	printf("\n%s","PRESS ENTER TO CONTINUE ...");
/*flushes input stream so that cin does not automatically pass the \n. Therefore it will wait for the 
user's ENTER like it should */
	cin.ignore(256,'\n'); 
	cin.get();
	waitFor(1);
	printf("\n\n%s\n","ROLLING ...");
	rollDice(userRoll);
	waitFor(2);


//WILL INCLUDE FUNCTION THAT KEEPS TRACK HOW MANY TIMES EACH PLAYER WINS

	}//END WHILE PROGRAM

}//END INTMAIN

