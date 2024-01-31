//Import useful libraries
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>


//usese namespace
using namespace std;

//Custom functions defined
void test();
vector<string> splitter(string str_name);
string DNA_t_RNA(string DNA);


//Function, where code is run
int main()
{   
    cout << "Type your sequence here: "; 
    string DNA_seq;
    getline(cin, DNA_seq);
    transform(DNA_seq.begin(), DNA_seq.end(), DNA_seq.begin(), ::toupper);

    // Splits sequences in nucleotides
    vector <string> DNA_seq_s = splitter(DNA_seq); 
    //Counts nucleotides and returns values. 
    int A = 0;
    int G = 0; 
    int C = 0;
    int T = 0;
    for (const string& nuc : DNA_seq_s)
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
            cout << "Foreign nucleotides detected, exiting..." << endl;
            cout << "exited :(" << endl;
            return EXIT_FAILURE;
        }
    }
    //Adds RNA transcribed from DNA sequence
    string RNA = DNA_t_RNA(DNA_seq);

    //Calculates percentages. Integers base-counts are casted to floats.
    int tot_nuc = A + G + C + T;
    float A_pc = (static_cast<float>(A)/tot_nuc) * 100; 
    float G_pc = (static_cast<float>(G)/tot_nuc) * 100;
    float C_pc = (static_cast<float>(C)/tot_nuc) * 100;
    float T_pc = (static_cast<float>(T)/tot_nuc) * 100;

    //Output bases numbers 
    cout << "Base counts report:" << endl;
    cout << "Adenine: " << A_pc << "%" <<endl;
    cout << "Guanine: " <<G_pc<< "%" <<endl;
    cout << "Cytosine: " <<C_pc<< "%" <<endl;
    cout << "Thymine: "<<T_pc<< "%" <<endl;

    //Output RNA
    cout << "Your RNA sequence: " << RNA << endl;
    return 0;
}
//#####################################################
//     Functions are defined properly below          //
//#####################################################

//DNA Splitter function
vector<string> splitter(string str_name){
    vector <string> sequence{};  
    //Loops over character in sequence and returns sequence vector 
    for (char nuc : str_name ){

        sequence.push_back(string(1,nuc));
    }
    return sequence;
}


//Converts DNA to RNA
string DNA_t_RNA(string DNA){
    string RNA;
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
            cout << "Foreign character detected, exiting....";
            cout << "exited :(" << endl;
            return "Failure_exit_code: RNA";
        }
    } 

return RNA;
}



//Alignment function (to be added)




