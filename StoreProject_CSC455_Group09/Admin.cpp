// Group 09: Aveline McEntire, Brendan Lance, Kaedon Pruiett
#define _CRT_SECURE_NO_WARNINGS
#include "Admin.h"
#include "Registration.h"
#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include <fstream>
#include <sstream>
using namespace std;

bool handleProductAddition(string &prodCode, string &productName, const string &productPrice, string &inventory);
int handleProductRemoval(const string &ProudctRemove);
int handleCustomerRemoval(const string &CustomerRemove);
void viewCustomers();
bool addProdPrefix(string& numberString);
bool isNumeric(const string& str);
bool isPositive(int num);
bool isValidDollarFormat(const string& input);
bool handleProductAddition(string &prodCode, string &productName, const string &productPrice, string &inventory);
int readNthLineUp(const string& filename, int n);
int handleCustomerCount(const string& filename);


void handleProductAddition()
{
    string productName;
    string productPrice;
    string productInventory;

    cout << "You have selected product addition." << endl;

    cout << "Enter the product's name: " << endl;
    cin >> productName;
    cout << "Enter the product's price: " << endl;
    cin >> productPrice;
    cout << "Enter the product's inventory: " << endl;
    cin >> productInventory;

    if (handleProductAddition(productName, productPrice, productInventory))
    {
        ofstream productInfoFile; // Set to write
        productInfoFile.open("products.txt", std::ios::app); // Set to append to products.txt
        string productFileName = "products.txt";

        // Gets product count
        int productCount = Registration::getBaseID(productFileName, 5) + 1;
        string prodID = getNewID(productCount);
        // TODO: Check prodID uniqueness because of product removal....

        // Appends to products.txt
        productInfoFile << "Product " << productCount << " ID: " << prodID << endl;
        productInfoFile << "Product " << productCount << " Name: " << productName << endl;
        productInfoFile << "Product " << productCount << " Price: " << productPrice << endl;
        productInfoFile << "Product " << productCount << " Inventory: " << productInventory << endl;
        productInfoFile << endl;
        productInfoFile.close();
        cout << "Product successfully added." << endl;
        return;
    }
    else
    {
        cout << "Product was not added." << endl;
        return;
    }
}

string getNewID(int ID)
{
    char buf[20];
    sprintf(buf, "%05d", ID);
    string prodID = buf;
    return string("Prod" + prodID);
}

// Takes in all parameters for adding products
// Adds product with code, name, price, and inventory count to products.txt
bool handleProductAddition(string &productName, const string &productPrice, string &inventory){
    
    /*
    ofstream productInfoFile; // Set to write
    productInfoFile.open("products.txt", std::ios::app); // Set to append to products.txt
    string productFileName = "products.txt";
    int productCount = 0;
    */
    // Checks if all entered data is valid
    if
        (isValidDollarFormat(productPrice) && isPositive(stoi(inventory)))
    {
        /*
        // Gets product count
        productCount = Registration::getBaseID(productFileName, 5);
        // TODO: Check prodID uniqueness because of product removal....

        // Appends to products.txt
        productInfoFile << "Product "<< productCount << " ID: " << prodCode << endl;
        productInfoFile << "Product "<< productCount << " Name: " << productName << endl;
        productInfoFile << "Product "<< productCount << " Price: " << productPrice << endl;
        productInfoFile << "Product "<< productCount << " Inventory: " << inventory << endl;
        productInfoFile << endl;
        */
        return true;
    }
    else
    {
        /*
        cerr<< "You have entered invalid information" << endl;
        */
        return false;
    }
}

int handleProductRemoval(const string &ProductRemove)
{
    // Implementation of product removal functionality
    // Placeholder text for testing
    //products.txt.remove(ProudctRemove);
    cout << "You have selected product removal." << endl;

    return 0;
}

int handleCustomerRemoval(const string &CustomerRemove)
{
    // Implementation of customer removal functionality
    // Placeholder text for testing
    //customer.txt.remove(CustomerRemove);
    cout << "You have selected customer removal.";
    return 0;
}



void handleProductAddition()
{
    return;
}

void handleProductRemoval()
{
    return;
}

void handleCustomerRemoval()
{
    return;
}

void viewCustomers()
{
    // Implementation of viewing customers functionality
    // Placeholder text for testing
    fstream myFile("customers.txt", ios::in);
    if (myFile.fail())
    {
        cout << "File does not exist." << endl;
        return;
    }
    else
    {
        string Customer;
        cout << "Enter customer ID (starts with \"CustID\"): " << endl;
        cin >> Customer;
        if (Customer.find("CustID") >= 0)
        {
            string str;
            int lines = 0;
            while (getline(myFile, str)) 
            {
                if (str.find(Customer))
                {
                    cout << str << endl;
                }
                else
                {
                    // This line does not belong to the customer..
                }
            }
        }
        else
        {
            cout << "Invalid customer ID. ID should start with \"CustID\"." << endl;
        }
        
        myFile.close();
        return;
    }
    //customer.txt.read(Customer);
    //cout << "You have selected view customers.";
}

// Takes in given 5-digit product number
// Adds "Prod" prefix
bool addProdPrefix(string& numberString) {
    if (numberString.length() == 5 && isNumeric(numberString)) {
        numberString = "Prod" + numberString;  // Update the input string with the modified value.
        return true;
    } else {
        return false; // Return false to indicate failure.
    }
}

// Makes sure given string is only digits
bool isNumeric(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false; // If any character is not a digit, return false.
        }
    }
    return true;
}

//Checks if given int is positive
bool isPositive(int num){
    return num > 0;
}

// Uses regular expression to check if given price
// matches '$' format
bool isValidDollarFormat(const string& input) {
    regex pattern("\\$\\d+(\\.\\d{2})?");
    return regex_match(input, pattern);
}

// Used to read the previously used product number
// Takes in a file and integer and reads n number of lines up
// from the bottom, then captures what is after the first 
/*
int readNthLineUp(const string& filename, int n) {
    ifstream inputFile(filename); // Open the text file for reading
    string line;
    vector<string> lines;
    if (inputFile.is_open()) {
        while (getline(inputFile, line)) { // Read each line of the file and store them in a vector
            lines.push_back(line);
        }
        // Check if the file contains at least n lines
        if (lines.size() >= n) {
            // Split the nth line up from the bottom based on the space character
            istringstream iss(lines[lines.size() - n]);
            string word1, word2;
            if (iss >> word1 >> word2) {
                // Convert the second word to an integer and return it
                try {
                    int result = stoi(word2);
                    return result;
                } catch (const invalid_argument& e) {
                    // Handle the case where the second word cannot be converted to an integer
                    cerr << "Error: The second word is not a valid integer." << endl;
                }
            }
        } else {
            // Handle the case where there are not enough lines in the file
            return 0;
        }
        inputFile.close();
    } else {
        // Handle the case where the file cannot be opened
        cerr << "Error: Failed to open the file for reading." << endl;
    }
    // Return a default value
    return 0;
}

// Reused for product number instead
int handleCustomerCount(const string& filename){
    int customerCount;
    customerCount = readNthLineUp(filename, 3) + 1;
    return customerCount;
}
*/