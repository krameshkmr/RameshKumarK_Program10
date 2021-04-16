#include <iostream>
#include <fstream> // to use ifstream
#include <sstream> // to use istringstream
using namespace std;

// Function prototype to open file
bool openFileIn(ifstream &, string);
// populate (initialize the two arrays (days[] and prices[])
void populateData(ifstream &);
// extract words
string extractDay(string line);
double extractPrice(string line);
// overloaded functions to display Array elements
void displayArray(string [], int);
void displayArray(double [], int);

// global variables to hold and process data for analysis
const int SIZE = 7;
string days[SIZE];
double prices[SIZE];

int main()
{
    // declare input file stream to store data from file
    ifstream dataFile;
    if (openFileIn(dataFile, "budget.txt")) // if budget.txt file exists and opens
    {
        // store data from the text file to days and prices
        populateData(dataFile);

        dataFile.close();
    }
    else {
       cout << "File open error!" << endl;
    }

    // Your code starts here

    ofstream outFile;
    outFile.open("total.txt");

    double total = 0;
    for (int i = 0; i < SIZE; i++)
    {
        total += prices[i];
    }

    outFile << "Mr. K planned to spend $" << total << " for the week." << endl;

    outFile.close();

    return 0;
}

/*
 * This function open a file and returns true if good
 */
bool openFileIn(ifstream &file, string fileName)
{
    file.open(fileName);
    if (file.fail())
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*
 * This function takes a stream of string as a reference to the
 * file, process each line of the file by extracting substring,
 * and store data to days[] and prices[]
*/
void populateData(ifstream &file)
{
    string line;
    int index = 0;
    while (!file.eof())
    {
        getline(file, line);
        string day = extractDay(line);
        double price = extractPrice (line);
        days[index] = day;  // store day to the global array days[]
        prices[index] = price;// store price to the global array prices[]
        index++;
    }
}

/*
 * This function takes a string as a parameter with two words
 * The first word is a day of week and the second word is price.
 * It returns the first word (day)
 */
string extractDay(string line)
{
    int positionOfSpace = line.find(" ");
                       // extract substring from a string
                       // we will talk about this later
    string firstWord = line.substr(0, positionOfSpace);
    return firstWord;
}

/*
 * This function takes a string as a parameter with two words
 * The second word is price. It converts the price as string to
 * price as double and returns the price
 */
double extractPrice(string line)
{
    int positionOfSpace = line.find(" ");
    int sizeOfLine = line.length();
                           // extract substring from a string
                           // we will talk about this later
    string priceAsString = line.substr(positionOfSpace+1, sizeOfLine);
    double price;
    istringstream(priceAsString) >> price; // convert string to double
    return price;
}

/*
 * This function displays array (double-price) elements on a separate line
 */
void displayArray(double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout  << "$" << arr[i] << endl;
    }
}

/*
 * This function displays array (string-days) elements on a separate line
 */
void displayArray(string arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
