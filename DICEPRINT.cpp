#include<iostream>
#include<vector>
using namespace std;

/* Function responsible for printing the dice in "DICEGAME*/
S:10/11/18

//function that checks if a value is within an array 
bool isIn(int value,int check[]){
	bool isfound = false;
	size_t count = 0;
	
	//while the array is not empty
	while(check[count]!= '\0'){
		if(value == check[count]){
			isfound = true;	
		}
		count++;
	}
	return isfound;	
}


//actual function that prints the die
void dicePrint(){
	
vector<char> top;
vector<char> mid;
vector<char> bot;
bool topB = false;
bool midB = false;
bool botB = false;
int t[] = {4,5,7,9,10,12};
int m[] = {0,1,3,8,10,12};
int b[] = {2,5,7,9,10,12};
//creates the vectors that show the dice
for (int j = 0 ; j<13 ; j++){

	if ((j == 4) || (j == 5) ||(j == 7) ||(j == 9) ||(j == 10)||(j == 12)){
	top.push_back('*');
	}
	else{
	top.push_back((char)32);
	}
	
	if ((j == 0) || (j == 1) ||(j == 3) ||(j == 8) ||(j == 10)||(j == 12)){
	mid.push_back('*');
	}
	else{
	mid.push_back((char)32);
	}
	
	if ((j == 2) || (j == 5) ||(j == 7) ||(j == 9) ||(j == 10)||(j == 12)){
	bot.push_back('*');
	}
	else{
	bot.push_back((char)32);
	}
}



cout<<"LETS PRINT THE DICE\n";
for (int k = 0 ; k<13 ; k++){
cout<<top[k];
}
cout<<"\n";
for (int l = 0 ; l<13 ; l++){
cout<<mid[l];
}
cout<<"\n";
for (int m = 0 ; m<13 ; m++){
cout<<bot[m];
}
		
}



int main(){
	dicePrint();
	
}
