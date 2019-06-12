#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include  <cstdio>
using namespace std;
/* Make a program that converts binary to decimal, octal , hex , etc...
Practice Program for CSC 21100
S: 8/30/18 
E: 9/20/18
*/ 

//OCTAL function is now complete ... final output needs some work but right now it is at 99%

//Function that takes input and makes sure it's acceptable 
string isLegit(){
	//checks to see if the user's input is acceptable
	string uinput; 
	bool isLegit = false;	
	while (isLegit == false){
	printf("%s \n","PLEASE ENTER A BINARY NUMBER TO CONVERT");
	cin >> uinput;
		for (int j  = 0 ; j <uinput.length(); j++){
			if ((uinput[j] == '0') || (uinput[j] == '1')){
			isLegit = true;	
			}
			else {
				printf("%s \n","PLEASE ENTER A VALID INPUT");
				isLegit = false;
			}
		}
	}
	return uinput;
}
// END isLegit

//Function that capitalizes a string
string Upper(string &upper){
	
for (int i = 0 ; i < upper.length(); i++){
	upper[i] = toupper(upper[i]);
}
	return upper;
}
//END Upper

//Function that modifies the input by adding ISD to make accurate computations 
void fixSize(vector<char>& fixVec){
	//Temporary vector to hold original values 
	vector<char>temp;
	//Checks to see if input has sets of 3
	int doFix = fixVec.size()%3;
	//Computes # of ISD to add to the left of the binary number
	int ISD = 3 - doFix;
	
	//If the input does not come in perfect sets of 3 then add remaining ISD
	 if (doFix != 0 ){
	 	//COPY vector to a temp vector 
		//NOTE: the order of saving the vector
	 	for (int i = 0 ; i < fixVec.size() ; i++){
	 		temp.push_back(fixVec[i]);
		 }
		 //CLEAR original vector
		 fixVec.clear();
		 
		 //ADD ISD to the original vector
		for(int j = 0 ; j < ISD ;j++){
			fixVec.push_back('0');
		}
		//ADD remaining original digits
		for (int k = 0 ; k < temp.size() ; k++){
			fixVec.push_back(temp[k]);
		} 	
	}	
}
//END fixSize	

//Function that converts BINARY into OCTAL number
void converBIN(vector<char> check){
	//Counter that checkes every 3 digits
	int Count = 0;
	//Sum that gets pushed into octAns
	int Sum = 0;
	//Values stored for 3 digit binary
	int Value[]  = {4,2,1};
	//VECTOR THAT STORES FINAL VALUE OF OCTAL NUMBER
	vector <int> octAns;
	
	//Check where in binary it is weighted
	for (int i  = 0 ;  i < check.size(); i++){
			if ((check[i]=='1') && (Count < 3)){
				Sum+=Value[Count];
			}
		//Counter resets every 3 digits
			if (Count < 3){
				Count++;
			}
			if (Count == 3){
			octAns.push_back(Sum);
			Sum = 0;
			Count = 0;
			}
		}
		
	//Print out final OCTAL value 
	for (int j = 0 ; j<octAns.size();j++){
		cout<<octAns[j]<<endl;
	}	
}
//END converBIN


int main(int argc, char const *argv[])
{
/*Vector used to store the user's binary input */
vector <char> binary_num;
//Records user's binary into a string
string ans; 
//Records the user's answer whether they want to commit or not
string decide = "Yes";
//Boolean that determines if user wants to use program again
bool keepConverting  = true; 


//BEGIN: program loop 
while(keepConverting == true){
	
//Function that checks for valid input	
ans = isLegit();
	
//Takes the user input and stores it in a vector
	for (int i  = 0 ; i <ans.length(); i++){
	binary_num.push_back(ans[i]);
	}

//Shows the new input if any ISD was added
fixSize(binary_num);
printf("%s \n","THIS IS THE NEW VECTOR !!");
	for (int ksi = 0 ; ksi < binary_num.size();ksi++){
	cout<< binary_num[ksi];
	}
	cout<<"\n";
	
	
//Actual conversion into OCTAL!! 
converBIN(binary_num);
 
//Asks to see if the user wants to keep using the program
//If YES, then clear input vector and ask for a new input
//If NO,  the program will terminate itself by switching the bool keep convering to "false"
printf("%s \n","WOULD YOU LIKE TO CONVERT ANOTHER BINARY NUMBER?");
cin >> decide;
Upper(decide);


	if ((decide == "N")||
	 	(decide == "NO")){
		keepConverting = false;
	}
	else {
		binary_num.clear();
		keepConverting = true;
	}
}
printf("%s \n","THANK YOU FOR USING MY PROGRAM :D");

	return 0;
}
