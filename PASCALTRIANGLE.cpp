#include<iostream>
#include<vector> 
using namespace std;
/*Write a function that computes pascal's triangle. Ask the user for the height of the triangle
and compute the triangle.
    S: 11/12/18
    E: 11/13/18 */
//Function that prints out the 2D vector in int main()
void printVec(const vector<vector<size_t> > Pmatrix){
    //Outer for loop that goes through each vector
	for(size_t i = 0 ; i <Pmatrix.size(); i++){
        //for-loop that adjusts the spacing for the output
	    for(size_t k = 0 ; k < Pmatrix.size()-i ; k++){
			cout<<"    ";
		}
		//for-loop that prints out the contents of each vector
		for(size_t j = 0 ; j < Pmatrix[i].size();j++){
			cout<<Pmatrix[i][j]<<"      ";
		}
		cout<<"\n";
	}
} //END printVec
//Function that creates each floor of the triangle based off of the previous floor vector "oldVec"
vector<size_t> heightGrow(vector<size_t> &oldVec){
    //Vector that stores new floow 
	vector<size_t> newVec;
    //Used to store the sum of every two numbers
	size_t sum = 0;
    //Counter used to check every two numbers
	size_t count = 0;
    //Pushes back the outer 1 for the new Floor 
	newVec.push_back(1);
    //for-loop reponsible for computing the next floor
	for (size_t i = 0 ; i < oldVec.size(); i++){
		sum+=oldVec[i];
        //Once we're on the second number...push_back the sum to the vector
		if(count == 1){
		newVec.push_back(sum);
        //Set the sum to the current number we're on in the Old vector 
		sum = oldVec[i];
        //Reset the counter back to 0;
		count = 0;
		}
		count++;
	}
    //Push_back the outer 1 
	newVec.push_back(1);
    //Return the newVec "new floor of triangle"
	return newVec;
}//END heightGrow
//Function responsible for creating the PASCALTRIANGLE based on a height the user inputs
void updatePascal(vector<vector<size_t> > &pTri, const size_t height){
//Vector that is used to add to the triangle ** this is always reused by being cleared
	vector<size_t> rowVec;
//for-loop that iterates height amount of times ... creates the triangle
	for (size_t i = 0 ; i < height ; i++){
        //Creates the top two floors of the triangle
		if(i <= 1){
			for(size_t j = 0 ; j <= i ; j++){
			rowVec.push_back(1);
			}
			pTri.push_back(rowVec);
			rowVec.clear();
		}
        //Creates the remaining floors
		else{ 
			rowVec = heightGrow(pTri[i-1]);
			pTri.push_back(rowVec);
			rowVec.clear();
	    }
	}
}//END updatePascal

int main(int argc, char const *argv[])
{
//Vector of Vectors used to store the triangle
vector<vector<size_t> > pascalTriangle;
//Store user input 
size_t uinput;
cout<<"Insert height\n";
cin >> uinput;
//Create Triangle ...
updatePascal(pascalTriangle,uinput);
//Print out the triangle
printVec(pascalTriangle);
	return 0;
}
