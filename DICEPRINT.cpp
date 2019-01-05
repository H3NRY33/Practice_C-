#include<iostream>
#include<vector>
using namespace std;
/* Function responsible for printing the dice in "DICEGAME*/
//actual function that prints the die
void dicePrint(int die){	
vector<char> top;
vector<char> mid;
vector<char> bot;
//creates the vectors that show the dice
for (int j = 0 ; j<13 ; j++){ //CREATES THE SET OF DICE IN EACH VECTOR
    switch(j){
    case 0 : mid.push_back('*'); top.push_back((char)32);bot.push_back((char)32); break;
    case 1 : mid.push_back('*'); top.push_back((char)32);bot.push_back((char)32); break;
    case 2 : bot.push_back('*'); top.push_back((char)32);mid.push_back((char)32); break;
    case 3 : mid.push_back('*'); top.push_back((char)32);bot.push_back((char)32); break;
    case 4 : top.push_back('*'); mid.push_back((char)32);bot.push_back((char)32); break;
    case 5 : top.push_back('*'); bot.push_back('*'); mid.push_back((char)32); break;
    case 7 : top.push_back('*'); bot.push_back('*'); mid.push_back((char)32); break;
    case 8 : mid.push_back('*'); top.push_back((char)32); bot.push_back((char)32); break;
    case 9 : top.push_back('*'); bot.push_back('*'); mid.push_back((char)32); break;
    case 10 :top.push_back('*'); mid.push_back('*'); bot.push_back('*'); break;
    case 12 :top.push_back('*'); mid.push_back('*'); bot.push_back('*'); break;
    default: top.push_back((char)32); mid.push_back((char)32); bot.push_back((char)32);break;
    }	
}
    switch(die){ //PRINTS OUT THE DIE ACCORDING to the value found. We only print the die where it exists in each level
    case 1: cout<<top[0]<<"\n"<<mid[0]<<"\n"<<bot[0]; break;
    case 2: cout<<top[0]<<top[1]<<"\n"<<mid[0]<<mid[1]<<"\n"<<bot[0]<<bot[1]; break;
    case 3: cout<<top[2]<<top[3]<<top[4]<<"\n"<<mid[2]<<mid[3]<<mid[4]<<"\n"<<bot[2]<<bot[3]<<bot[4]; break;
    case 4: cout<<top[5]<<top[6]<<top[7]<<"\n"<<mid[5]<<mid[6]<<mid[7]<<"\n"<<bot[5]<<bot[6]<<bot[7]; break;
    case 5: cout<<top[7]<<top[8]<<top[9]<<"\n"<<mid[7]<<mid[8]<<mid[9]<<"\n"<<bot[7]<<bot[8]<<bot[9]; break;
    case 6: cout<<top[10]<<top[11]<<top[12]<<"\n"<<mid[10]<<mid[11]<<mid[12]<<"\n"<<bot[10]<<bot[11]<<bot[12]; break;
    default: cout<<"\n"<<"\n"<<"\n"; break; //for 0
    }	
}
int main(){
	int printt; //DEBUGGING
    while( cin >> printt){
        dicePrint(printt);
        cout<<"-------------\n";
    }
}
