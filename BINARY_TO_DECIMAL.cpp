#include <iostream> 
using namespace std; 

//convert binary to integer
//function returns the integer value of the binary string 
int convBIN(string bin){
  int result;
//iterates through entire string
  for(int i = 0; i <bin.size(); i++){
  result*=2;
  switch(bin[i]){
    case '0':{break;}
    case '1':{result+=1; break;}
    default:{break;}
    }
  }
return result;
}


int main(){
  //used for debugging purposes 
string tString = "01010101001";
int value = 0;
cout<<value<<"\n";
value = convBIN(tString);
cout<<value<<"\n";

}
