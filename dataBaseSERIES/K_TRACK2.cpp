#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std; 

void readFile(const string fname,vector<string> &editVec){
  editVec.clear();
  string Rinp;
  ifstream myfile(fname);
  if(myfile.is_open()){
    while(getline(myfile,Rinp)){
	
       	editVec.push_back(Rinp);
         if(Rinp.length()==0){
          break;
          }
      }
  myfile.close();
  }
}
void createData(size_t dSize,vector<string> &editVec, vector<string> title){
	editVec.clear();
	string id;
	for(size_t i = 1 ; i <=dSize;i++){
	id = to_string(i);
	editVec.push_back("IDENTIFICATION: " + id);
		for(size_t j = 0 ; j<3 ; j++){
		editVec.push_back(title[j]);
		}
	editVec.push_back("------------------------------");
	}
}
void editData(size_t cell, string fname,string lname,string dob,vector<string> &editVec,vector<string> title){
	
	size_t cell_Access = (cell*5)-4;
	vector<string> data{fname,lname,dob};

	for (size_t i = cell_Access; i<cell_Access+3; i++){
		editVec[i].clear();
		editVec[i] = title[i-cell_Access] + data[i-cell_Access];
	}
	
}
void outFile(const string fname,vector<string> big){//Takes a string(Most likely file location) and a vector of vectors
    ofstream myfile;//Creates object myfile to be written
    myfile.open(fname);//Opens fname, which would be the file path
    for (size_t i=0; i<big.size(); i++){
        myfile << big[i]<<"\n";
        }
        myfile.close();
}

int main(){
	
	vector<string> descr{"FIRST NAME: ","LAST NAME: ","DOB: "};
	vector<string> mainVec;
	string inp1="0000000000000000000";
	string inp2="0000000000000000000";
	string inp3="0000000000000000000";
	string fileName ="data$.txt";
	size_t cDatabase;
	size_t idAccess;
		
	cout<<"How many spots to make....\n";
	cin >> cDatabase;	
	createData(cDatabase,mainVec,descr);
	outFile(fileName,mainVec);
	cout<<"Wher would you like to edit?\n";
	cin >> idAccess;
	
	readFile(fileName,mainVec);
	editData(idAccess,inp1,inp2,inp3,mainVec,descr);
	outFile(fileName,mainVec);	
		
/*	readFile(fileName,mainVec);
	cout<<"Before\n";
	 for (size_t i =0; i<mainVec.size(); i++){
            cout << mainVec[i]<<"\n";
        }
	editData(idAccess,inp1,inp2,inp3,mainVec,descr);
    outFile(fileName,mainVec);
    
    cout<<"After\n"; 
        for (size_t j =0; j<mainVec.size(); j++){
            cout << mainVec[j]<<"\n";
        }*/	
	return 0; 
}
