/*
Name: Lab6_Sorensen.cpp
Author: Christina Sorensen
Date Created: 10/18/2023
Lab: #6
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std; 
typedef int Type;

vector<vector<Type>> add(const vector<vector<Type>>& matrix1, const vector<vector<Type>>& matrix2) {
    //Adds two matrices

    //Defines the rows and columns of the matrices
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    //Creates the matrix for the added matrices
    vector<vector<Type>> added(rows, vector<Type>(cols, 0));

    //Adds and appends in the values to the multiplied matrix
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            added[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return added;
}

vector<vector<Type>> multiply(const vector<vector<Type>>& matrix1, const vector<vector<Type>>& matrix2) { 
    //Multiplies two matrices

    //Defines the parts of the matrices being looked at
    int a = matrix1.size();
    int b = matrix1[0].size();
    int c = matrix2[0].size();

    //Creates the matrix for the multiplied matrices
    vector<vector<Type>> multiplied(a, vector<Type>(c, 0));

    //Multiplies and appends in the values to the multiplied matrix
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < b; k++) {
                multiplied[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return multiplied;
}

vector<vector<Type>> subtract(const vector<vector<Type>>& matrix1, const vector<vector<Type>>& matrix2) {
    //Subtracts two matrices

    //Defines the rows and columns
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    //Creates the matrix for the subracted matrices
    vector<vector<Type>> subtracted(rows, vector<Type>(cols, 0));

    //Subtracts and appends in the values to the subtracted matrix
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            subtracted[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return subtracted;
}

int main() {
    ifstream inMatrix("matrix_input.txt"); //Opens the file
    
    cout << "Christina Sorensen\nLab #6: Matrix manipulation\n\n"; //Prints out title of program
    
    //This block of code generates the size of the code.
    string line1;
    int size;
    if (getline(inMatrix, line1)) {
        size = stoi(line1);
    }

    //This block of code defines Matrix A
    cout << "Matrix A:\n";
    vector<vector<Type>> matrixA(size, vector<Type>(size, 0));
    for (int i = 0; i < size; ++i) {
        string line;
        if (getline(inMatrix, line)) {
            istringstream iss(line);
            for (int j = 0; j < size; ++j) {
                iss >> matrixA[i][j];
            }
        }
        for (int j = 0; j < size; ++j) {
            cout << matrixA[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n";

    //This block of code defines Matrix B
    cout << "Matrix B:\n";
    vector<vector<Type>> matrixB(size, vector<Type>(size, 0));
    for (int i = 0; i < size; ++i) {
        string line;
        if (getline(inMatrix, line)) {
            istringstream iss(line);
            for (int j = 0; j < size; ++j) {
                iss >> matrixB[i][j];
            }
        }
        for (int j = 0; j < size; ++j) {
            cout << matrixB[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n";
    
    //This block of code prints out the added Matrix A and Matrix B
    cout << "Matrix Sum (A + B):\n";
    vector<vector<Type>> added = add(matrixA, matrixB);
    for (int i = 0; i < added.size(); i++) {
        for(int j = 0; j < added[i].size(); j++){
            cout << added[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
    
    //This block of code prints out the multiplied Matrix A and Matrix B
    cout << "Matrix Product (A * B):\n";
    vector<vector<Type>> multiplied = multiply(matrixA, matrixB);
    for (int i = 0; i < multiplied.size(); i++) {
        for(int j = 0; j < multiplied[i].size(); j++){
            cout << multiplied[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";

    //This block of code prints out the subtracted Matrix A and Matrix B
    cout << "Matrix Difference (A - B):\n";
    vector<vector<Type>> subtracted = subtract(matrixA, matrixB);
    for (int i = 0; i < subtracted.size(); i++) {
        for(int j = 0; j < subtracted[i].size(); j++){
            cout << subtracted[i][j] << " ";
        }
        cout << endl;
    }
    
    inMatrix.close(); //This closes the file
    
    return 0; //This finishes up the main function
}