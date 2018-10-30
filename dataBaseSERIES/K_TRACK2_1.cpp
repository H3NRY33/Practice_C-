#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
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
	size_t i2 =0;
	if (dSize%2 == 0){
		
		for(size_t i = 1 ; i<= dSize/2 ; i++){
			
			editVec.push_back("IDENTIFICATION: " + to_string(i+i2));
			editVec.push_back(title[0]);
			editVec.push_back(title[1]);
			editVec.push_back(title[2]);
			editVec.push_back("----------------------------------");
			editVec.push_back("IDENTIFICATION: " + to_string((i+i2)+1));
			editVec.push_back(title[0]);
			editVec.push_back(title[1]);
			editVec.push_back(title[2]);
			editVec.push_back("----------------------------------");
			i2++;
			
		}	
	}	
	if(dSize%3 == 0){
			for (size_t j = 1 ; j <=dSize/3;j++){
			editVec.push_back("IDENTIFICATION: " + to_string(j+i2));
			editVec.push_back(title[0]);
			editVec.push_back(title[1]);
			editVec.push_back(title[2]);
			editVec.push_back("----------------------------------");
			editVec.push_back("IDENTIFICATION: " + to_string((j+i2)+1));
			editVec.push_back(title[0]);
			editVec.push_back(title[1]);
			editVec.push_back(title[2]);
			editVec.push_back("----------------------------------");
			editVec.push_back("IDENTIFICATION: " + to_string((j+i2)+2));
			editVec.push_back(title[0]);
			editVec.push_back(title[1]);
			editVec.push_back(title[2]);
			editVec.push_back("----------------------------------");
			i2+=2;	
			}
			
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
void outFile(const string fname,vector<string> vec){
   std::ofstream f(fname);
for(vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
    f << *i << '\n';
	}
}
int main(){
	
	vector<string> descr{"FIRST NAME: ","LAST NAME: ","DOB: "};
	vector<string> mainVec;
	string inp1="0000000000000000000";
	string inp2="0000000000000000000";
	string inp3="0000000000000000000";
	string fileName ="data2_1$.docx";
	size_t cDatabase = 1000000;
	size_t idAccess;
		
	cout<<"How many spots to make....2_1\n";

	createData(cDatabase,mainVec,descr);
	outFile(fileName,mainVec);
	
	
	
	
/*	cout<<"Wher would you like to edit?\n";
	cin >> idAccess;
	
	
	
	for (size_t i =0; i<mainVec.size(); i++){
            cout << mainVec[i]<<"\n";
        }
	
	
	
	
	
	
	readFile(fileName,mainVec);
	editData(idAccess,inp1,inp2,inp3,mainVec,descr);
	outFile(fileName,mainVec);	
	*/	
/*	readFile(fileName,mainVec);
	cout<<"Before\n";
	
	editData(idAccess,inp1,inp2,inp3,mainVec,descr);
    outFile(fileName,mainVec);
    
    cout<<"After\n"; 
        for (size_t j =0; j<mainVec.size(); j++){
            cout << mainVec[j]<<"\n";
        }*/	
	return 0; 
}
