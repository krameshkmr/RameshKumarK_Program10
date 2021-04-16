/*
Program 24
Programmer: Krishna Ramesh Kumar
Course: CSC119 Introduction to Programming C++ Spring 2021
Submission Date: 4/15/2021
This program will open a file, read the numbers, and calculate the number, sum, and average of those numbers.
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
    // Open input file "Random.txt"
    ifstream inFile;
    inFile.open("Random.txt");
    
    // Calling function
    loop(inFile);
    
    // Close input file "Random.txt"
    inFile.close();
}

// Defining function
void loop(ifstream &file) {
    // Defining variables
    int number;
    double sum = 0, numOfNumbers = 0, average;
    
    // Loop that calculates the sum and number of numbers
    while (file >> number) {
        sum += number;
        numOfNumbers++;
    }
    
    // Process data
    average = sum / numOfNumbers;
    
    // Display number, sum, and average
    cout << "Number of numbers: " << numOfNumbers << endl;
    cout << "Sum of the numbers: " << sum << endl;
    cout << "Average of the numbers: " << average << endl;
}
