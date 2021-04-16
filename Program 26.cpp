/*
Program 26
Programmer: Krishna Ramesh Kumar
Course: CSC119 Introduction to Programming C++ Spring 2021
Submission Date: 4/15/2021
This program will take input from the user and create an HTML file containing the input.
*/

// Importing input/output library
#include <iostream>
#include <fstream>

// Standard namespace
using namespace std;

// Declaring function
void htmlContent(string name, string description, ofstream &file);

// Main function
int main() {
    // Defining variables
    string name;
    char description[100];
    
    // Open output file "index.html"
    ofstream outFile;
    outFile.open("index.html");
    
    // Asking user for name and description and saving it
    cout << "Enter your name: ";
    cin >> name;
    cin.ignore();
    cout << "Describe yourself:" << endl;
    cin.getline(description, 100);
    
    // Calling function
    htmlContent(name, description, outFile);
    
    // Close output file "index.html"
    outFile.close();
}

// Defining function
void htmlContent(string name, string description, ofstream &file) {
    // Display name and description in html formatting
    file << "<html>" << endl;
    file << "<head>" << endl;
    file << "</head>" << endl;
    file << "<body>" << endl;
    file << "\t<center>" << endl;
    file << "\t\t<h1>" << name << "</h1>" << endl;
    file << "\t<center>" << endl;
    file << "\t<hr />" << endl;
    file << "\t" << description << endl;
    file << "\t<hr />" << endl;
    file << "</body>" << endl;
    file << "</html>" << endl;
}
