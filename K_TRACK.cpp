#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std; 
/* Few functions that reads text files and adds new information to them... WOP 
B: 10/25/18 */

void addtoSmall(string inp,vector<char>& small2){//takes a string and a vector to change said vector such that every char in the string is now an element of the vector UPDATE: Should now CONVERT files with '.' and '0' INTO BOOLEAN when pushing back.
    for (size_t i=0; i<=inp.length(); i++){
    small2.push_back(inp[i]);
	}
}


void readFile(const string fname,const string identification,vector<vector<char> > &big)//Takes a string, and a vector of vectors
{
  big.clear();
  vector<char> small;
  string Rinp;
  ifstream myfile(fname);// creates and object called myfile with the file path
  if(myfile.is_open()){
    while(getline(myfile,Rinp)){//While myfile is being read into string Rinp
        if(Rinp=="--idend"+identification){
          break;
          }
        
        addtoSmall(Rinp,small);//Takes string Rinp and vector small, and then makes small contain every char of Rinp as a element of small
        big.push_back(small);//Takes the vector we inputted and creates an element containing small(a vector of chars)
        small.clear();//clears all elements from small
      }
  myfile.close();
  }
}


void editData(const string id, string fname , string lname , string dob,vector<vector<char> > &edit){
	string checkLine;
	bool dataFound = false;
	size_t lEdit = 0;
	size_t i;
	
	
	for ( i=0; i<edit.size(); i++){
		checkLine.clear();

			if (dataFound == true){
		
		}
		if (dataFound == false){
			for (size_t j=0 ; j<edit[i].size(); j++){
            checkLine+=edit[i][j];
            }
        if(checkLine =="ident:"+id) dataFound = true;	
		}
      
	
	}
	
}



void outFile(const string fname,vector<vector<char> > vec){//Takes a string(Most likely file location) and a vector of vectors
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
	
	vector <vector<char> > mainVec;
	//Asks what file you want to look at
	string fileName;
	//Asks what up to what id number you want to look at
	string idAccess;
	
	
	cout<<"Enter name of file desired to read\n";
	cin >> fileName;
	fileName+=".txt";
	cout<<"Enter up to what id to access\n";
	cin >> idAccess;
	
	readFile(fileName,idAccess,mainVec);
	editData(idAccess,"hugh" ,"mungus","11/16/1973",mainVec);
	
	 for (size_t i =0; i<mainVec.size(); i++){
        for (size_t j=0 ; j<mainVec[i].size(); j++){
            cout << mainVec[i][j];
            }
            cout << "\n";
        }
	
	
	
	return 0; 
}
