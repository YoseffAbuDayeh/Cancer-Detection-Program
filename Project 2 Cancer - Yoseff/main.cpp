/*
* Name:         main.cpp
* Purpose:      Main program
* By:           Yoseff Abu Dayeh
* Date:         2023-12-01 
*/

#include "Methods.h"


int main() {

    std::string filename = "unformatted_data_v1.0.0.csv";  //Specify the name of the file to read from
    std::vector<std::vector<int>> patients = readCSV(filename);
    for (int i = 0; i < patients.size(); i++)
    {
        int result = ifFake(patients[i]);
        patients[i][10] = result;
    } //Checks which patients have bad information

    Node* root = buildDecisionTree(); //Builds the tree

    int NumberOfPatients = 0;
    int BenignP = 0;
    int MalignantP = 0;
    int invalidP = 0;


    for (int i = 0; i < patients.size(); i++)
    {

        if (patients[i][10] == 11)
        { //If the patient is invalid then it just ignores the rest of the for loop since we can't change anything
            NumberOfPatients++;
            invalidP++;
            continue;
        }
        std::string prediction = predictDiagnosis(root, patients[i][1], patients[i][2], patients[i][3], patients[i][4], patients[i][5], patients[i][6], patients[i][7], patients[i][8], patients[i][9] );
        if (prediction == "Benign")
        {
            patients[i][10] = 2;
            BenignP++;
        }
        else if (prediction == "Malignant")
        {
            patients[i][10] = 4;
            MalignantP++;
        }
        //Depending on the ailment then it adds to the ailment.
        NumberOfPatients++;
    }

    std::cout << "# of patients " << NumberOfPatients << std::endl;
    std::cout << "# of benign patients: " << BenignP << std::endl;
    std::cout << "# of malignant patients: " << MalignantP << std::endl;
    std::cout << "# of invalid patients: " << invalidP << std::endl;
    //Outputs the data needed
    
    exportToCSV(patients);
    //exports the data to a csv
    return 0;
}