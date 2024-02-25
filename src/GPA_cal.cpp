//Import useful libraries
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <numeric>

float GPA_calc(float grade, float percentage, float tot_weight);


int main(){
    
    std::cout << "###############################" <<"\n";
    std::cout << "# My beautiful GPA calculator #" <<"\n";
    std::cout << "###############################" <<"\n";
    std::cout <<"\n";
    std::cout <<"\n";
    //Takes in total weighting   
    std::cout << "Your total weight: ";
    std::string weigth_tot; 
    getline(std::cin, weigth_tot);
    
    float wg_fl_tot = std::stof(weigth_tot);

    std::string stopper= "";
    std::vector <float> weight_grades={}; 

    while (stopper != "x"){
        //Takes in the mark out of 100
        std::cout << "Your mark out of 100: ";
        std::string grade; 
        getline(std::cin, grade);
        
        float gr_fl = std::stof(grade);
        //Takes in the weigteing out of 100
        std::cout << "Your weight out of 100: ";
        std::string weigth; 
        getline(std::cin, weigth);
        
        float wg_fl = std::stof(weigth);

        //Calculates grades and appends them to the vector
        float result = GPA_calc(gr_fl, wg_fl, wg_fl_tot);
        weight_grades.push_back(result);
        //More grades to enter? 
        //Takes in the weigteing out of 100
        std::cout << "press <x> to exit: " ;
        getline(std::cin, stopper);
        
    }

    //Outputs weighted grade
    float calculated_grade = std::accumulate(weight_grades.rbegin(), weight_grades.rend(), 0);
    std::cout << "Your calculated grade is : " << calculated_grade ;

}

float GPA_calc (float grade, float percentage, float tot_weight){


    float weighted_score = grade * (percentage/tot_weight);

    return weighted_score ;

}
