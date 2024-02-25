#include <iostream>
#include <vector>
#include <string>

//usese namespace


//Declare function. Defined after main.
std::string check_input(std::string usr_inp, std::string CPU_inp);


//Main function
int main() {
    //Usr choice.
    std::cout << "USR------> Rock, paper or scissors (R/P/S): ";
    std::string usr_choice;
    getline(std::cin, usr_choice);
    

    //CPU choice.
    std::cout << "CPU------> Rock, paper or scissors (R/P/S): ";
    std::string CPU_choice;
    getline(std::cin, CPU_choice);


    //Logic of the game.
    std::string result = check_input(usr_choice, CPU_choice);

    std::cout << result << "\n";

return 0;
}




//MAIN LOGIC:  Checks inputs and returns the winner  
std::string check_input(std::string usr_inp, std::string CPU_inp){
    
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
