/*
Program 25
Programmer: Krishna Ramesh Kumar
Course: CSC119 Introduction to Programming C++ Spring 2021
Submission Date: 4/15/2021
This program will open a file, read the names, and display the students at the front and end of the line.
*/

// Importing input/output library
#include <iostream>
#include <fstream>

// Standard namespace
using namespace std;

// Declaring function
void loop(ifstream &file);

// Main function
int main() {
    // Open input file "LineUp.txt"
    ifstream inFile;
    inFile.open("LineUp.txt");
    
    // Calling function
    loop(inFile);
    
    // Close input file "LineUp.txt"
    inFile.close();
}

// Defining function
void loop(ifstream &file) {
    // Defining variables
    string student, frontOfLine, endOfLine;
    
    file >> student;
    // Setting variables frontOfLine and endOfLine as student
    frontOfLine = endOfLine = student;
    
    // Loop that calculates which students are at the front and end of the line
    while (!file.eof()) {
        if (student < frontOfLine) {
            frontOfLine = student;
        }
        if (student > endOfLine) {
            endOfLine = student;
        }
        file >> student;
    }
    
    // Display students at the front and end of the line
    cout << frontOfLine << " is the student at the front of the line." << endl;
    cout << endOfLine << " is the student at the end of the line." << endl;
}
