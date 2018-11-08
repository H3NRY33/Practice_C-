#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/*S: 11/08/18
  E: 11/08/18 */




//Function that creates a vector a specific length
void createAxis(const int length, vector<int> &V){
	for (int i = 0 ; i <=length ; i++){
		V.push_back(i);
	}
}//END createAxis


void createMatrix(const int X, const int Y , vector<vector<bool> > &matrix){
	vector<bool> Row;

	for (int i = 0 ; i <=X ; i++){
		Row.push_back(false);
	}
	for (int j = 0 ; j<= Y ;j++){
		matrix.push_back(Row);
	}
}//END createMatrix



void feedtoVec(const int position,const vector<int> inpV, vector<int> &compareV ){
	compareV.clear();
	compareV.push_back(inpV[position]);
	compareV.push_back(inpV[position + 1]);
}//END feedtoVec



void editMatrix(const vector<int> xAxis,const vector<int> yAxis, const vector<int> plotV, vector<vector<bool> > &matrix){
vector<int> compareVec;

	for (int i = 0 ; i < plotV.size() ; i+=2){
	feedtoVec(i,plotV,compareVec);

		for(int j = 0 ; j < yAxis.size(); j++){
			for(int k = 0; k < xAxis.size(); k++){
				if((compareVec[0] == xAxis[k]) && (compareVec[1] == yAxis[j])){
				matrix[j][k] = true;
				}
			
			}
		}

	}
}//END editMATRIX

void printMatrix(const vector<vector<bool> > Pmatrix){
	int j = 1;
	cout<<"   ";
	for (int l =0; l < Pmatrix.size(); l++){
		if(l < 10){
		cout<<l<<"  ";
		}
		else{
		cout<<l<<" ";
		}
		
	}
	cout<<"\n";
	cout<<"   ";
	for (int k =0; k < Pmatrix.size(); k++){
		cout<<"-  ";
	}
	cout<<"\n";
	for (int i = 0 ; i <Pmatrix.size(); i++){
		if(i<10){
		cout<<i<<" |";
		}
		else{
		cout<<i<<"|";
		}
		


		for (j = 0 ; j<Pmatrix[i].size();j++){
			cout<<Pmatrix[i][j]<<"  ";
		}
		cout<<"\n\n";
	}
} //END print matrix









int main(int argc, char const *argv[])
{
int plotPoint;
vector<int> plotVector; //Will be used to store the user's input
vector<vector<bool> > gridMatrix; //Will be used to display the matrix
vector<int> xAxis;
vector<int> yAxis;
int intervalX;
int intervalY;

cout<<"Insert X interval\n";
cin >> intervalX;
cout<<"Insert Y interval\n";
cin >> intervalY;

createAxis(intervalX,xAxis);
createAxis(intervalY,yAxis);
createMatrix(intervalX,intervalY,gridMatrix);


cout<<"Insert Coordinates in format X Y \n";

while(cin>>plotPoint){
	if(plotPoint >=0){
	plotVector.push_back(plotPoint);
	}
	else{break;}
}
editMatrix(xAxis,yAxis,plotVector,gridMatrix);
printMatrix(gridMatrix);










	
	return 0;
}
