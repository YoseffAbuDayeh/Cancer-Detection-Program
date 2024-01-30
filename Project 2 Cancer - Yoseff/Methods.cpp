/*
* Name:         Methods.cpp
* Purpose:      Store data for the main
* By:           Yoseff Abu Dayeh
* Date:         2023-12-01
*/

#include <vector>
#include <fstream>
#include <sstream>
#include "Methods.h"


std::string predictDiagnosis(Node* root, int clumpThickness, int uniCellSize, int uniCellShape, int marginalAdhesion, int epiCellSize, int BareNuclei, int blandChromatin, int normalNucleoli, int Mitosis ) {
    while (true) {
        if (root->label == "Uniformity of Cell Size <= 2") {
            if (uniCellSize <= 2) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        else if (root->label == "Bare Nuclei <= 3") {
            if (BareNuclei <= 3) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        else if (root->label == "Clump Thickness <= 3") {
            if (clumpThickness <= 3) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        else if (root->label == "Bland Chronation <= 2") {
            if (blandChromatin <= 2) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        else if (root->label == "Marginal Adhesion <= 3") {
            if (marginalAdhesion <= 3) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        else if (root->label == "Uniformity of Cell Shape <= 2") {
            if (uniCellShape <= 2) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        else if (root->label == "Clump Thickness <= 5") {
            if (clumpThickness <= 5) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        else if (root->label == "Uniformity of Cell Size <= 4") {
            if (uniCellSize <= 4) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        else if (root->label == "Bare Nuclei <= 2") {
            if (BareNuclei <= 2) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        else if (root->label == "Marginal Adhesion <= 3") {
            if (marginalAdhesion <= 3) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }

        else if (root->label == "Clump Thickness <= 6") {
            if (clumpThickness <= 6) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }

        else if (root->label == "Uniformity of Cell Size <= 3") {
            if (uniCellSize <= 3) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }

        else if (root->label == "Marginal Adhesion <= 5") {
            if (marginalAdhesion <= 5) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        // Logic that tells the binary selection tree whether to go left or right from where they are.





        // If it reaches the end of the tree (the leaf) then just returns the value it ended with.
        if (root->left == nullptr && root->right == nullptr) {
            return root->label;
        }
    }
}



Node* buildDecisionTree() {
    Node* root = new Node("Uniformity of Cell Size <= 2");

    root->left = new Node("Bare Nuclei <= 3");
    root->left->right = new Node("Benign");
    root->left->left = new Node("Clump Thickness <= 3");
    root->left->left->left = new Node("Bland Chronation <= 2");
    root->left->left->right = new Node("Benign");
    root->left->left->left->right = new Node("Marginal Adhesion <= 3");
    root->left->left->left->left= new Node("Malignant");
    root->left->left->left->right->right = new Node("Malignant");
    root->left->left->left->right->left= new Node("Benign");
    //Builds the binary tree from the data given 
    root->right = new Node("Uniformity of Cell Shape <= 2");
    root->right->right = new Node("Clump Thickness <= 5");
    root->right->right->right = new Node("Benign");
    root->right->right->left = new Node("Malignant");
    root->right->left = new Node("Uniformity of Cell Size <= 4");
    root->right->left->left = new Node("Malignant");
    root->right->left->right = new Node("Bare Nuclei <= 2");
    root->right->left->right->left = new Node("Clump Thickness <= 6");
    root->right->left->right->right = new Node("Marginal Adhesion <= 3");
    root->right->left->right->right->right = new Node("Benign");
    root->right->left->right->right->left = new Node("Malignant");
    root->right->left->right->left->right = new Node("Uniformity of Cell Size <= 3");
    root->right->left->right->left->left = new Node("Malignant");
    root->right->left->right->left->right->right = new Node("Malignant");
    root->right->left->right->left->right->left = new Node("Marginal Adhesion <= 5");
    root->right->left->right->left->right->left->right = new Node("Benign");
    root->right->left->right->left->right->left->left = new Node("Malignant");
    //Returns the root of the tree
    return root;
}

std::vector<std::vector<int>> readCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<int>> data; 
    std::string line;
    //Declares data that will be used

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<int> patientAttributes; 
        std::string val;
        //Declares variables that are going to be used later on
        while (std::getline(iss, val, ',')) {
            if (!val.empty()) {
                try { //If the value is a number then it adds it
                    int value = std::stoi(val);
                    patientAttributes.push_back(value);
                } // If value isn't a number then it adds 11 which later will be used to know whether it's fake data or not
                catch (const std::invalid_argument& e) {
                    patientAttributes.push_back(11);
                }
            }
        }
        // Add attributes of the current patient to the data vector
        if (!patientAttributes.empty()) {
            data.push_back(patientAttributes);
        }
    }
    return data;
}


void exportToCSV(const std::vector<std::vector<int>>& data) {
    std::ofstream file("results.csv");
    // Chooses the name of results.csv
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    } // Checks if it can be opened and is available as a "valid" file name

    for (const auto& row : data) {
        int pass = 0; //makes a temp variable
        for (auto column = row.begin(); column != row.end(); ++column) {
            pass++;
            if (pass == 1)
            { // Ignores the ID as it isn't needed in the instructions
                continue;
            }
            if (pass == 11)
            { // Checks if its the last column.
                if (*column == 2)
                {
                    file << "Benign";
                }
                else if (*column == 4)
                {
                    file << "Malignant";
                }
                else if (*column == 11)
                {
                    file << "Invalid";
                } // Adds Malignant, Benign or Invalid to the last column
                else
                {
                    file << *column;
                } // Just as error prevention, It shouldn't go here but as error handling.
                if (std::next(column) != row.end()) {
                    file << ",";
                } // Adds the comma for csv
                continue;
            }
            file << *column;
            if (std::next(column) != row.end()) {
                file << ",";
            }
        }
        file << "\n";
        //Adds a next line character
    }
    //Closes the file
    file.close();
    std::cout << "File has been created successfully." << std::endl;
}

int ifFake(std::vector<int>& features)
{
    for (int i = 0; i < features.size(); i++)
    {
        if (features[i] == 11)
        {//Checks if there is an 11 anywhere in the code, which should indicate if there is fake data
            return 11;
        }
    }
    return 0; // Returns 0 if the data isn't a fake
}