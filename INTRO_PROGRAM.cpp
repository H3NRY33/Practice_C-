#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
using namespace std; 
/** 
The purpose of program is to create a nice swirl based on the user's input length 
The function " printGraphic1" is what does all the work.
**/
//Courtesy of DICEGAME.cpp
void waitFor(double timeWait){
int newTime = timeWait * 1000;
this_thread::sleep_for(chrono::milliseconds(newTime));
}//END "waitFor"

//function to print out swirl graphic 
void printGraphic1(const size_t Slength){
	size_t space = 12;
	double delay = .14;
	for(size_t i = 0 ; i < Slength ; i++){
		for (size_t l = 0 ; l <= 4 ; l++){
			for(size_t m = 0 ; m <= 12 ; m++){
				if(m != 12-space) cout<<" ";
				else cout<<"0";				
			}
			if(space > 0) space -=4;
			cout<<"\n";
			waitFor(delay);
		}
		for (size_t j = 0 ; j <= 3 ; j ++){
			for(size_t k = 0 ; k <= 12 ; k++ ){
				if (k != 12 - space) cout<<" ";
				else cout<<"0";	
			}
			if (space < 12) space+=4;
			cout<<"\n";
			waitFor(delay);
		}
 	}
}//END printGraphic
//beginning of int main 
int main(int argc, char const *argv[])
{
	size_t Slength =0;
	cout<<"Enter the length of the swirl"<<endl;
	cin >> Slength;
	printGraphic1(Slength);
	return 0;
}
