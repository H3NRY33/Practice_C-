#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std; 


void readFile(const string fname,vector<vector<string> > &big)//Takes a string, and a vector of vectors
{
  big.clear();
  vector<string> small;
  string Rinp;
  ifstream myfile(fname);// creates and object called myfile with the file path
  if(myfile.is_open()){
    while(getline(myfile,Rinp)){//While myfile is being read into string Rinp
       small.push_back(Rinp);
        big.push_back(small);//Takes the vector we inputted and creates an element containing small(a vector of chars)
         if(Rinp.length()==0){
          break;
          }
        small.clear();//clears all elements from small
      }
  myfile.close();
  }
}





void editData(string id, string fname,string lname,string dob, vector<vector<string> > &edit){
	size_t cell;
	size_t cell_Access;
	stringstream conv(id);
	conv >> cell;
	cell_Access = (cell*5)-4;
	vector<string> title{"fname:","lname:","birth:"};
	vector<string> data{fname,lname,dob};
	vector<string> temp1;
	vector<string> temp2;
	vector<string> insertVec;
	
	
	for (size_t i = cell_Access; i<cell_Access+3; i++){
	edit[i].clear();
	temp1.clear();
	temp2.clear();
	insertVec.clear();
	temp1.push_back(title[i-cell_Access]);
	temp2.push_back(data[i-cell_Access]);

	insertVec.reserve( temp1.size() + temp2.size() ); // preallocate memory
	insertVec.insert( insertVec.end(), temp1.begin(), temp1.end() );
	insertVec.insert( insertVec.end(), temp2.begin(), temp2.end() );
	
	edit[i]= insertVec;
	
	}
	
}















void outFile(const string fname,vector<vector<string> > vec){//Takes a string(Most likely file location) and a vector of vectors
    ofstream myfile;//Creates object myfile to be written
    myfile.open(fname);//Opens fname, which would be the file path
    for (size_t i=0; i<vec.size(); i++){
        for (size_t j=0 ; j<vec[i].size(); j++){
            myfile << vec[i][j];//Writes every char in the file chosen into a vector of vectors
            }
            myfile << endl;
        }
        myfile.close();
}



int main(){
	
	vector <vector<string> > mainVec;
	//Asks what file you want to look at
	string fileName ="data$.txt";
	//Asks what up to what id number you want to look at
	string idAccess;
	
	
	

	cout<<"Enter up to what id to access\n";
	cin >> idAccess;
	
	
	
	string inp1="Hugh";
	string inp2="Mungus";
	string inp3="11/09/1987";
	
	
	
	
	
	
	
	readFile(fileName,mainVec);
	editData(idAccess,inp1,inp2,inp3,mainVec);
	outFile(fileName,mainVec);

	 for (size_t i =0; i<mainVec.size(); i++){
        for (size_t j=0 ; j<mainVec[i].size(); j++){
            cout << mainVec[i][j];
            }
            cout << "\n";
        }
        
	
	
	
	return 0; 
}
