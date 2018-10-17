/*
 * CSc103 Project 3: Game of Life
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 http://www.cplusplus.com/doc/tutorial/files/
 https://www-cs.ccny.cuny.edu/~wes/CSC103/gdb.html
 https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
 https://www.geeksforgeeks.org/ways-copy-vector-c/
 https://syntaxdb.com/ref/cpp/vectors
 http://www.cplusplus.com/forum/beginner/231421/
 https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/IO#fstream
 Classmates from csc103
 My family and friends
 God
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:~35 hrs
 */

#include <vector>
#include <iostream>
#include <string>
#include <fstream> // to take in file path
#include <cstdio>
#include <stdlib.h> // for exit();
#include <getopt.h> // to parse long arguments.
#include <unistd.h> // sleep
using namespace std;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Text-based version of Conway's game of life.\n\n"
"   --seed,-s     FILE     read start state from FILE.\n"
"   --world,-w    FILE     store current world in FILE.\n"
"   --fast-fw,-f  NUM      evolve system for NUM generations and quit.\n"
"   --help,-h              show this message and exit.\n";

string inFile = "/file/path/to/be/read";
string ofile = "/file/path/to/be/written";
size_t max_gen = 0;
vector<vector<bool> > mainVec;//Main vector of vectors to be read and used to write to

void addtoSmall(string inp,vector<bool>& small2){//takes a string and a vector to change said vector such that every char in the string is now an element of the vector UPDATE: Should now CONVERT files with '.' and '0' INTO BOOLEAN when pushing back.
    for (size_t i=0; i<=inp.length(); i++){
    if(inp[i] == '.'){
      small2.push_back(false); /* dead x_x */
            }
    if(inp[i] == 'O'){
      small2.push_back(true); /* alive 8D */
            }
        }
}

void readFile(const string readFile,vector<vector<bool> > &big)//Takes a string, and a vector of vectors
{
  big.clear();
  vector<bool> small;
  string Rinp;
  ifstream myfile(readFile);// creates and object called myfile with the file path
  if(myfile.is_open()){
    while(getline(myfile,Rinp)){//While myfile is being read into string Rinp
        if(Rinp.length()==0){
          break;
          }
        addtoSmall(Rinp,small);//Takes string Rinp and vector small, and then makes small contain every char of Rinp as a element of small
        big.push_back(small);//Takes the vector we inputted and creates an element containing small(a vector of chars)
        small.clear();//clears all elements from small
      }
  myfile.close();
  }
}

size_t nbrCount(int row, int col, const vector<vector<bool> > g)
/*Takes a row and a column(which is specified by the two 'for' loops in int main, and a vector of vectors*/
{
  size_t count = 0;
  const size_t rowTotal = g.size();
  const size_t colTotal = g[0].size();
  for(int i = row-1; i <= (row+1); i++){
    for (int j = col-1; j<= col+1; j++){
            //Starts counting at top left of cell in question
            if(i == row && j == col){
                continue;//Skips cell in question;A cell can't be it's own neighbor.
            }
            count += g[(i+rowTotal)%rowTotal][(j+colTotal)%colTotal];
            /*Since every element of the vector of vector is BOOLEAN, we can just add the values of the live neighboring cells(1) to count.*/
    }
  }
    return count;
}

void lifeLogic(vector<vector<bool> > &world)//Applies logic
{
    vector<vector<bool> > worldIntial = world;
    for(size_t i = 0; i < world.size(); i++){
        for (size_t j = 0; j < world[0].size(); j++){
            if(nbrCount(i,j,worldIntial) < 2){
                world[i][j] = false;/*Dies to underpopulation*/
                }
                else if(nbrCount(i,j,worldIntial) > 3){
                    world[i][j] = false;/*Dies to overpopulation*/
                    }
                    else if(nbrCount(i,j,worldIntial) == 3){
                        world[i][j] = true;/*Birth*/
            }
        }
    }
}

void boltoChar(vector<vector<bool> > mainVc,vector<vector<char> > &mainVc2){
vector<char> vSmall;
mainVc2.clear();
  for (size_t i = 0 ; i<mainVc.size(); i++){
    for (size_t j = 0; j < mainVc[0].size();j++){
      if (mainVc[i][j] == true){
        vSmall.push_back('O');
        }
      if(mainVc[i][j] == false){
        vSmall.push_back('.');
        }
      }
    mainVc2.push_back(vSmall);
    vSmall.clear();
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

int main(int argc, char *argv[])
{
    vector<vector<bool> > mainVec;
    vector<vector<char> > mainVec2;
    static struct option long_opts[] = {
        {"seed",    required_argument, 0, 's'},
        {"world",   required_argument, 0, 'w'},
        {"fast-fw", required_argument, 0, 'f'},
        {"help",    no_argument,       0, 'h'},
        {0,0,0,0}
    };
        char c;
    int opt_index = 0;
    while ((c = getopt_long(argc, argv, "hs:w:f:", long_opts, &opt_index)) != -1) {
        switch (c) {
            case 'h':
                printf(usage,argv[0]);
                return 0;
            case 's':
                inFile = optarg;
                break;
            case 'w':
                ofile = optarg;
                break;
            case 'f':
                max_gen = atoi(optarg);
                break;
            case '?':
                printf(usage,argv[0]);
                return 1;
                        }
                    }
if (inFile != "/file/path/to/be/read"){
    readFile(inFile, mainVec);

if ((ofile != "/file/path/to/be/written") && (ofile != "-")&&(max_gen == 0)){
    while (true){
        lifeLogic(mainVec);
        boltoChar(mainVec,mainVec2);
        sleep(1);
        outFile(ofile,mainVec2);

            }
}
if ((ofile == "/file/path/to/be/written") && (ofile != "-")){
    cout<<"PLEASE INSERT A VALID OUTPUT FILE"<<endl;
    cout << "lol";
}

if (ofile == "-"){
    for(size_t i = 0 ; i < max_gen ; i++){
        lifeLogic(mainVec);
        boltoChar(mainVec,mainVec2);
                }
    for(size_t j = 0 ; j < mainVec2.size(); j++){
        for(size_t k = 0 ; k < mainVec2[j].size() ; k++){
            cout << mainVec2[j][k];
                    }
        cout<<"\n";
        }
    }
}

if(inFile == "/file/path/to/be/read"){
    cin >> inFile;
    readFile(inFile, mainVec);
if ((ofile != "/file/path/to/be/written") && (ofile != "-")){

    for(size_t i = 0 ; i < max_gen ; i++){

        lifeLogic(mainVec);
        boltoChar(mainVec,mainVec2);
                }
    outFile(ofile,mainVec2);
}
if ((ofile == "/file/path/to/be/written") && (ofile != "-")){

    for(size_t i = 0 ; i < max_gen ; i++){
        mainVec2.clear();
        lifeLogic(mainVec);
        boltoChar(mainVec,mainVec2);
        }
     for(size_t j = 0 ; j < mainVec2.size(); j++){
        for(size_t k = 0 ; k < mainVec2[j].size() ; k++){
            cout << mainVec2[j][k];
                    }
        cout<<"\n";
    }

}

if (ofile == "-"){
    for(size_t i = 0 ; i < max_gen ; i++){
        lifeLogic(mainVec);
        boltoChar(mainVec,mainVec2);
        }
     for(size_t j = 0 ; j < mainVec2.size(); j++){
        for(size_t k = 0 ; k < mainVec2[j].size() ; k++){
            cout << mainVec2[j][k];
                    }
        cout<<"\n";
    }
}


}

if (inFile == "-"){
cin >> inFile;
readFile(inFile, mainVec);

if ((ofile != "/file/path/to/be/written") && (ofile != "-")){
    for(size_t i = 0 ; i < max_gen ; i++){
        lifeLogic(mainVec);
        boltoChar(mainVec,mainVec2);
        }
    outFile(ofile,mainVec2);
}
if ((ofile == "/file/path/to/be/written") && (ofile != "-")){
for(size_t i = 0 ; i < max_gen ; i++){
        lifeLogic(mainVec);
        boltoChar(mainVec,mainVec2);
        }
     for(size_t j = 0 ; j < mainVec2.size(); j++){
        for(size_t k = 0 ; k < mainVec2[j].size() ; k++){
            cout << mainVec2[j][k];
                    }
        cout<<"\n";
    }
}

if (ofile == "-"){
for(size_t i = 0 ; i < max_gen ; i++){
        lifeLogic(mainVec);
        boltoChar(mainVec,mainVec2);
        }
     for(size_t j = 0 ; j < mainVec2.size(); j++){
        for(size_t k = 0 ; k < mainVec2[j].size() ; k++){
            cout << mainVec2[j][k];
                    }
        cout<<"\n";
    }//DOUBLE FOR LOOP TO PRINT
}

//hey
}

}
