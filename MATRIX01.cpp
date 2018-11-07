#include<iostream>
#include<vector> 
#include<string> 
using namespace std;

/*Create a list of functions that follow's Zero-on matrices slide from Lecture 11 CSC10400
  S: 11/07/18
  E: ........
*/

void feedtoVec(string uinput,vector<vector<char> > &vecFeed,int &Vmin,int &maX,int &maY){
	vecFeed.clear(); //Clears the vector to remove anything interfering
	int count = 0;	//Keeps track of which digit we're looking at
	vector<char> feed; //Vector to hold subset of size 2
	//Loop that stores every 2 digits into vector<char> feed, then pushes it to 2D vector vecFeed
	for(size_t i = 0; i<=uinput.length(); i++){
		if (count < 2){
			feed.push_back(uinput[i]);
			count++;
		}
		if (count == 0){
			if((int)uinput[i] > maX){
			maX = (int)uinput[i];
			}
		}
		if (count == 1){
			if((int)uinput[i] > maY){
			maY = (int)uinput[i];
			}

		}
		if(count ==2){
			vecFeed.push_back(feed);
			feed.clear();
			count=0;
		}
	}//END for LOOP
	Vmin = vecFeed.size()-1;
}//END feedtoVec


void createV(vector<char> &V, int min, int max){
	V.clear();
	int start = max - min;
	for (int i = 0; i <=max ; i++){
		V.push_back((char)(start+i));
	}
}




void printd(const vector<char> U){
	for (int i = 0 ; i<U.size(); i++){
		cout<<U[i]<<" ";
	}
}
void printV(const vector<vector<char> > printV){
	for (size_t i = 0 ; i<printV.size(); i++){
		for (size_t j = 0 ; j < printV[i].size(); j++){
			cout<<printV[i][j];
		}
		cout<<"\n";
	}
}

int main(int argc, char const *argv[])
{

string uinput; //Stores user's input 

vector<char> xAxis; //Vector that define x axis
vector<char> yAxis; //Vector that define y axis

int min = 0; //Overall minimum
int highX = 0; //Highest interval for x
int highY = 0; //Highest interval for y


vector<vector<char> > vCheck; //Vector to store user's input as sets

cout<<"insert axis\n"; 
cin >> uinput;
feedtoVec(uinput,vCheck,min,highX,highY);
createV(xAxis,min,highX);
createV(yAxis,min,highY);
printd(xAxis);
printd(yAxis);

printV(vCheck);
	return 0;
}
