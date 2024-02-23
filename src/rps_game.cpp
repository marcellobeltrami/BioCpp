#include <iostream>
#include <vector>
#include <string>

//usese namespace
using namespace std;


string check_input(string usr_inp, string CPU_inp){
    
    // Tests in case of tie
    if (usr_inp == CPU_inp){
        return "tie heheheh";

    } 

    // Tests for usr scissor
    else if (usr_inp == "S"){
        if (CPU_inp == "P"){
            return "usr wins";
        }
        if (CPU_inp == "R"){
            return "usr looses :(";
        }
        else {
            return "CPU invalid input";
        }  
    }

    // Tests for usr paper
    else if (usr_inp == "P"){
        if (CPU_inp == "R"){
            return "usr wins";
        }
        if (CPU_inp == "S"){
            return "usr looses :(";
        }
        else {
            return "CPU invalid input";
        }

    }


    // Tests for usr rock
    else if (usr_inp == "R"){
        if (CPU_inp == "S"){
            return "usr wins";
        }
        if (CPU_inp == "P"){
            return "usr looses :(";
        }
        else {
            return "CPU invalid input";
        }
    }
    
    else {
            return "USR invalid input ";
        
    }
}


int main() {
    //Usr choice.
    cout << "USR------> Rock, paper or scissors (R/P/S): ";
    string usr_choice;
    getline(cin, usr_choice);
    

    //CPU choice.
    cout << "CPU------> Rock, paper or scissors (R/P/S): ";
    string CPU_choice;
    getline(cin, CPU_choice);


    //Logic of the game.
    string result = check_input(usr_choice, CPU_choice);

    cout << result << endl;;

return 0;
}
