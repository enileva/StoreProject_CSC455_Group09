// Group 09: Aveline McEntire, Brendan Lance, Kaedon Pruiett
#include "Admin.h"
#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include <fstream>
#include <sstream>

bool handleProductAddition(std::string &prodCode, std::string &productName, const std::string &productPrice, std::string &inventory);
int handleProductRemoval(const std::string &ProudctRemove);
int handleCustomerRemoval(const std::string &CustomerRemove);
int viewCustomers(const std::string &Customer);
bool addProdPrefix(std::string& numberString);
bool isNumeric(const std::string& str);
bool isPositive(int num);
bool isValidDollarFormat(const std::string& input);
bool handleProductAddition(std::string &prodCode, std::string &productName, const std::string &productPrice, std::string &inventory);
int readNthLineUp(const std::string& filename, int n);
int handleCustomerCount(const std::string& filename);


// Takes in all parameters for adding products
// Adds product with code, name, price, and inventory count to products.txt
bool handleProductAddition(std::string &prodCode, std::string &productName, const std::string &productPrice, std::string &inventory){
    
    std::ofstream productInfoFile; // Set to write
    productInfoFile.open("products.txt", std::ios::app); // Set to append to products.txt
    std::string productFileName = "products.txt";
    int productCount = 0;
    
    // Checks if all entered data is valid
    if
        (addProdPrefix(prodCode) && isValidDollarFormat(productPrice) && isPositive(stoi(inventory)))
    {
        // Increments product count
        productCount = handleCustomerCount(productFileName);

        // Appends to products.txt
        productInfoFile << "Product "<< productCount << " " << prodCode << std::endl;
        productInfoFile << "Product "<< productCount << " " << productName << std::endl;
        productInfoFile << "Product "<< productCount << " " << productPrice << std::endl;
        productInfoFile << "Product "<< productCount << " " << inventory << std::endl;
        productInfoFile << std::endl;
        return true;
    }
    else
    {
        std::cerr<< "You have entered invalid information" << std::endl;
        return false;
    }
}

int handleProductRemoval(const std::string &ProudctRemove)
{
    // Implementation of product removal functionality
    // Placeholder text for testing
    products.txt.remove(ProudctRemove);
    std::cout << "You have selected product removal.";
}

int handleCustomerRemoval(const std::string &CustomerRemove)
{
    // Implementation of customer removal functionality
    // Placeholder text for testing
    customer.txt.remove(CustomerRemove);
    std::cout << "You have selected customer removal.";
}

int viewCustomers(const std::string &Customer)
{
    // Implementation of viewing customers functionality
    // Placeholder text for testing
    customer.txt.read(Customer);
    std::cout << "You have selected view customers.";
}

// Takes in given 5-digit product number
// Adds "Prod" prefix
bool addProdPrefix(std::string& numberString) {
    if (numberString.length() == 5 && isNumeric(numberString)) {
        numberString = "Prod" + numberString;  // Update the input string with the modified value.
        return true;
    } else {
        return false; // Return false to indicate failure.
    }
}

// Makes sure given string is only digits
bool isNumeric(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
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
bool isValidDollarFormat(const std::string& input) {
    std::regex pattern("\\$\\d+(\\.\\d{2})?");
    return std::regex_match(input, pattern);
}

// Used to read the previously used product number
// Takes in a file and integer and reads n number of lines up
// from the bottom, then captures what is after the first space
int readNthLineUp(const std::string& filename, int n) {
    std::ifstream inputFile(filename); // Open the text file for reading
    std::string line;
    std::vector<std::string> lines;
    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) { // Read each line of the file and store them in a vector
            lines.push_back(line);
        }
        // Check if the file contains at least n lines
        if (lines.size() >= n) {
            // Split the nth line up from the bottom based on the space character
            std::istringstream iss(lines[lines.size() - n]);
            std::string word1, word2;
            if (iss >> word1 >> word2) {
                // Convert the second word to an integer and return it
                try {
                    int result = std::stoi(word2);
                    return result;
                } catch (const std::invalid_argument& e) {
                    // Handle the case where the second word cannot be converted to an integer
                    std::cerr << "Error: The second word is not a valid integer." << std::endl;
                }
            }
        } else {
            // Handle the case where there are not enough lines in the file
            return 0;
        }
        inputFile.close();
    } else {
        // Handle the case where the file cannot be opened
        std::cerr << "Error: Failed to open the file for reading." << std::endl;
    }
    // Return a default value
    return 0;
}

// Reused for product number instead
int handleCustomerCount(const std::string& filename){
    int customerCount;
    customerCount = readNthLineUp(filename, 3) + 1;
    return customerCount;
}