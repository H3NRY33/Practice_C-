#include<iostream>
#include<vector> 
using namespace std;
/*S: 11/12/18
  E: ???? */

void printVec(const vector<vector<size_t> > Pmatrix){
	
	for (size_t i = 0 ; i <Pmatrix.size(); i++){
	    for(size_t k = 0 ; k < Pmatrix.size()-i ; k++){
			cout<<"    ";
			}
		
		for (size_t j = 0 ; j < Pmatrix[i].size();j++){
		    
			cout<<Pmatrix[i][j]<<"      ";
		}
		cout<<"\n";
	}
} //END print matrix







vector<size_t> heightGrow(vector<size_t> &oldVec){
	vector<size_t> newVec;
	size_t sum = 0;
	size_t count = 0;
	newVec.push_back(1);
	for (size_t i = 0 ; i < oldVec.size(); i++){
		sum+=oldVec[i];

		if(count == 1){
		newVec.push_back(sum);
		sum = oldVec[i];
		count = 0;
		}
		count++;
	
	}
	newVec.push_back(1);
	return newVec;
}

void updatePascal(vector<vector<size_t> > &pTri, const size_t height){
	vector<size_t> rowVec;

	for (size_t i = 0 ; i <= height ; i++){
		if(i <= 1){
			for (size_t j = 0 ; j <=i ; j++){
			rowVec.push_back(1);
			}
			pTri.push_back(rowVec);
			rowVec.clear();
		}
		else{
			rowVec = heightGrow(pTri[i-1]);
			pTri.push_back(rowVec);
			rowVec.clear();
		}
	}
}



int main(int argc, char const *argv[])
{
vector<vector<size_t> > pascalTriangle;
/* FIRST DEBUG
vector<size_t> testV = {1,2,4,5,1};
vector<size_t> result = heightGrow(testV);
for (size_t i = 0 ; i < result.size(); i++){
    cout<<result[i]<<" ";
}

*/
size_t uinput;
cout<<"Insert height\n";
cin >> uinput;

updatePascal(pascalTriangle,uinput);
printVec(pascalTriangle);



	return 0;
}
