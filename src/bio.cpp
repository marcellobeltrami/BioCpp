//Import useful libraries
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>


//Custom functions defined
void test();
std::vector<std::string> splitter(std::string str_name);
std::string DNA_t_RNA(std::string DNA);


//Function, where code is run
int main()
{   
    std::cout << "Type your sequence here: "; 
    std::string DNA_seq;
    getline(std::cin, DNA_seq);
    transform(DNA_seq.begin(), DNA_seq.end(), DNA_seq.begin(), ::toupper);

    // Splits sequences in nucleotides
    std::vector <std::string> DNA_seq_s = splitter(DNA_seq); 
    //Counts nucleotides and returns values. 
    int A = 0;
    int G = 0; 
    int C = 0;
    int T = 0;
    for (const std::string& nuc : DNA_seq_s)
    {
        if (nuc == "A"){
            A+=1;
        }else if (nuc == "G"){
            G+=1;
        }else if (nuc == "C"){
            C+=1;
        }else if (nuc == "T"){
            T+=1;
        }else{
            std::cout << "Foreign nucleotides detected, exiting..." << "\n";
            std::cout << "exited :(" << "\n";
            return EXIT_FAILURE;
        }
    }
    //Adds RNA transcribed from DNA sequence
    std::string RNA = DNA_t_RNA(DNA_seq);

    //Calculates percentages. Integers base-counts are casted to floats.
    int tot_nuc = A + G + C + T;
    float A_pc = (static_cast<float>(A)/tot_nuc) * 100; 
    float G_pc = (static_cast<float>(G)/tot_nuc) * 100;
    float C_pc = (static_cast<float>(C)/tot_nuc) * 100;
    float T_pc = (static_cast<float>(T)/tot_nuc) * 100;

    //Output bases numbers 
    std::cout << "Base counts report:" << "\n";
    std::cout << "  Adenine: " << A_pc << "%" << "\n";
    std::cout << "  Guanine: " <<G_pc<< "%" << "\n";
    std::cout << "  Cytosine: " <<C_pc<< "%" << "\n";
    std::cout << "  Thymine: "<<T_pc<< "%" << "\n";

    //Output RNA
    std::cout << "Your RNA sequence: " << RNA << "\n";
    return 0;
}
//#####################################################
//     Functions are defined properly below          //
//#####################################################

//DNA Splitter function
std::vector<std::string> splitter(std::string str_name){
    std::vector <std::string> sequence{};  
    //Loops over character in sequence and returns sequence vector 
    for (char nuc : str_name ){

        sequence.push_back(std::string(1,nuc));
    }
    return sequence;
}


//Converts DNA to RNA
std::string DNA_t_RNA(std::string DNA){
    std::string RNA;
    for (char nuc : DNA){
        if (nuc == 'C'){
            RNA+= 'G';
        }else if (nuc == 'A'){
            RNA += 'U';
        }else if (nuc == 'G'){
            RNA += 'C';
        }else if (nuc == 'T'){
            RNA+= 'A';
        } else {
            std::cout << "Foreign character detected, exiting....";
            std::cout << "exited :(" << "\n";
            return "Failure_exit_code: RNA";
        }
    } 

return RNA;
}


//Alignment function (to be added)




