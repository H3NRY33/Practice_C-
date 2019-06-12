#include<iostream>
#include<array>
using namespace std; 

/*Make a function that checks whether or not a value is in an array
NOTE: the array you want to check must be predefined MANUALLY not with a for LOOP
S:10/11/18
*/
//Function that checks whether or not a value is found within an array
bool isIn(int value,int check[]){
	size_t count = 0;
	
	//while the array is not empty
	while(check[count]!= '\0'){
		if(value == check[count]){
			return true;
		}
		count++;
	}
	return false;	
}

int main(){
	
//DEBUG

//advises whether or not the function works
bool TEST = false;	

//declares array to look for
int myArr[]= {1,2,3,4,5,6,7,8,9,10};

//variable to lookfor (DEFINED BY USER)
int lookFor; 


cout<<"Enter the value to look for\n";
cin >> lookFor; 

//Shows boolean value
cout<<"The value of TEST before\n";
cout<<TEST<<"\n";
TEST = isIn(lookFor,myArr);
cout<<"The value of TEST after\n";
cout<<TEST<<"\n";
	
}
