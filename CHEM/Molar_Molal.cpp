#include <iostream>
#include <cmath> 
#include <vector>
using namespace std;


float calculateMolality(float compoundAmount = 0, float molarMass = 0, float amountSolvent = 0, float density = 0){
float compoundMoles = compoundAmount/molarMass;
float solventKg = (amountSolvent*density)/1000;
return compoundMoles/solventKg;
}

float calculateMolarity(float compoundAmount = 0, float molarMass = 0, float amountSolvent = 0, float density = 0){
float compoundMoles = compoundAmount/molarMass;
float solventL = amountSolvent/1000;
return compoundMoles/solventL;
}


int main(){
    bool chemCalc = true;
    while(chemCalc == true){
        float compoundAmount = 0;
        float molarMass = 0;
        float amountSolvent = 0;
        float density = 0;
        bool choice = false;
        cout<<"Inset Values In this order:\n";
        cout<<"\tCOMPOUND AMOUNT\n";
        cout<<"\tMOLAR MASS\n";
        cout<<"\tSOLVENT AMOUNT\n";
        cout<<"\tDENSITY\n";
        cin.ignore();
        cin >> compoundAmount>>molarMass>>amountSolvent>>density;
        
        cout << "0 - MOLARITY : 1 - MOLALITY\n";
        cin.ignore();
        cin >> choice;
        if(!choice){
            cout<<calculateMolarity(compoundAmount,molarMass, amountSolvent, density)<<"\n";
        }else{
            cout<<calculateMolality(compoundAmount,molarMass, amountSolvent, density)<<"\n";
        }
        string ans = "";
        cout<<"More Calc?";
        cin >> ans;
        if(ans == "n"){
            chemCalc = 0;
        }
    }

    return 0;
}