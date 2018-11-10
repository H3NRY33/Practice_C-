#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/*S: 11/08/18
  E: 11/08/18 */




//Function that creates a vector of ints with contents of i value.
void createAxis(const int length, vector<int> &V){
	for (int i = 0 ; i <=length ; i++){
		V.push_back(i);
	}
}//END createAxis

//Creates an empty 2D matrix of type bool. There are Y amount of vectors of size X.
void createMatrix(const int X, const int Y , vector<vector<bool> > &matrix){
	//Creates a Row of bools of length X.
	vector<bool> Row;
	for (int i = 0 ; i <= X ; i++){
		Row.push_back(false);
	}
	//Pushes the Row Vectos Y amount of times.
	for (int j = 0 ; j <= Y ;j++){
		matrix.push_back(Row);
	}
}//END createMatrix

//Vector used to store x and y coordinates for comparison to actual point given by the user.
void feedtoVec(const int position,const vector<int> inpV, vector<int> &compareV ){
	compareV.clear();
	compareV.push_back(inpV[position]);
	compareV.push_back(inpV[position + 1]);
}//END feedtoVec.

//Takes a 2D Vector along with user coordinates. It checks to see if it exists within the X and Y axis points.
void editMatrix(const vector<int> xAxis,const vector<int> yAxis, const vector<int> plotV, vector<vector<bool> > &matrix){
//Vector that store's a single coordinate from the user.
vector<int> compareVec;
	//Iterates through the list of user's coordinates.
	for (int i = 0 ; i < plotV.size() ; i+=2){
	feedtoVec(i,plotV,compareVec);
		//Iterates through Y axis points.
		for(int j = 0 ; j < yAxis.size(); j++){
			//Iterates through X axis points.
			for(int k = 0; k < xAxis.size(); k++){
				//Logic for coordinate comparison.
				if((compareVec[0] == xAxis[k]) && (compareVec[1] == yAxis[j])){
				matrix[j][k] = true;
				}
			}
		}
	}
}//END editMATRIX

void printMatrix(const vector<vector<bool> > Pmatrix){
	int j = 1;
	//Prints out X axis of Matrix.
	cout<<"    ";
	for (int l =0; l < Pmatrix[0].size(); l++){
		if(l < 10){
		cout<<l<<"  ";
		}
		else{
		cout<<l<<" ";
		}
	}
	cout<<"\n";
	cout<<"    ";
	//Used for X axis Aesthetics.
	for (int k =0; k < Pmatrix[0].size(); k++){
		if(k < 10){
		cout<<"-  ";
		}
		else{
		cout<<"-  ";
		}
		
	}
	//Prints out Y axis.
	cout<<"\n";
	for (int i = 0 ; i <Pmatrix.size(); i++){
		if(i<10){
		cout<<i<<" | ";
		}
		else{
		cout<<i<<"| ";
		}
		//Prints out the actual values of the Matrix
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
