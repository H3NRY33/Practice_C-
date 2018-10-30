#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include<bits/stdc++.h>
using namespace std; 

/*Function that reads the current database that is stored in a file*/
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

/*Regardless if file is empty or filled, the function adds dSize amount of empty cells*/
void createData(size_t dSize,vector<string> &editVec, vector<string> title){
	editVec.clear();
	string id;
	for(size_t i = 1 ; i <=dSize;i++){
	id = to_string(i);
	editVec.push_back("IDENTIFICATION: " + id);
		for(size_t j = 0 ; j<title.size() ; j++){
		editVec.push_back(title[j]);
		}
	editVec.push_back("------------------------------");
	}
}
/*Function that adds a cell either with information or without*/
void addData(vector<string> &editVec,vector<string> title){
	size_t nextID = (editVec.size()/(title.size()+2))+1;
	vector<string> data;
	string insData;
	string ans;
	
	cout<<"WILL IT BE PREDEFINED?\n";
	cin >> ans;
	transform(ans.begin(),ans.end(),ans.begin(),::toupper);
	
	editVec.push_back("IDENTIFICATION: " + to_string(nextID));
	if(ans == "YES"){
	cout <<"Please provide :\n";
	cin.ignore(256,'\n');
		for (size_t j = 0 ; j <title.size(); j++){
		cout<<title[j]<<endl;	
		getline(cin,insData);
		data.push_back(insData);
		}
		for(size_t k = 0 ; k<title.size() ; k++){
		editVec.push_back(title[k]+data[k]);
		}
	}
	if(ans == "NO"){
		for(size_t j = 0 ; j<title.size() ; j++){
		editVec.push_back(title[j]);
		}
	}
	editVec.push_back("------------------------------");
}
	/*Function that edits a cell based on the identification provided by the user*/
void editData(size_t cell,vector<string> &editVec,vector<string> title){
	vector<string> data;
	string insData;
	
	cout <<"Please provide :\n";
	cin.ignore(256,'\n');
	for (size_t j = 0 ; j <title.size(); j++){
		cout<<title[j]<<endl;	
		getline(cin,insData);
		data.push_back(insData);
	}
		
	size_t cell_Access = (cell*title.size())+1;

	for (size_t i = cell_Access; i<cell_Access+data.size(); i++){
		editVec[i].clear();
		editVec[i] = title[i-cell_Access] + data[i-cell_Access];
	}
	
}
/*Function that prints out the updated dataBase*/
void outFile(const string fname,vector<string> allData){
    ofstream myfile;
    myfile.open(fname);
    for (size_t i=0; i<allData.size(); i++){
        myfile << allData[i]<<"\n";
        }
        myfile.close();
}

int main(){
	
	vector<string> descr{"FIRST NAME: ","LAST NAME: ","DOB: ","GeNdER: "};
	vector<string> mainVec;
	string fileName ="data$.docx";
	size_t cDatabase;
	cout<<"How many spots to make....OG\n";
	cin >> cDatabase;
	createData(cDatabase,mainVec, descr);
	addData(mainVec,descr);
	
	outFile(fileName,mainVec);
	
	return 0; 
}
