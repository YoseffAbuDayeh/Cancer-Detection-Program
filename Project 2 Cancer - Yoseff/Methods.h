#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

struct Node {
    std::string label;
    Node* left;
    Node* right;

    Node(std::string label) : label(label), left(nullptr), right(nullptr) {}
};

Node* buildDecisionTree();
std::string predictDiagnosis(Node* root, int clumpThickness, int uniCellSize, int uniCellShape, int marginalAdhesion, int epiCellSize, int BareNuclei, int blandChromatin, int normalNucleoli, int Mitosis);
int ifFake(std::vector<int>& features);
std::vector<std::vector<int>> readCSV(const std::string& filename);
void exportToCSV(const std::vector<std::vector<int>>& data);