// Group 09: Aveline McEntire, Brendan Lance, Kaedon Pruiett
#include "Registration.h"
#include <iostream>
#include <string>
#include <cctype>
#include <random>
#include <sstream>
#include <fstream>

bool handleCustomerRegistration(const std::string &customerID, std::string &Username, std::string &FirstName, std::string &LastName, std::string &Age, std::string &RewardPoints, std::string &Card);
bool handleUserName(const std::string &username);
bool handleFirstAndLastName(const std::string &name);
bool handleAge(const std::string &ageStr);
bool handleCreditCard(const std::string &creditCard);
std::string generateRandomNumber();
std::string makeUniqueID();
bool handleRewardsPoint(const std::string &RewardsPoints);
int readNthLineUp(const std::string& filename, int n);
int handleCustomerCount(const std::string& filename);

bool handleCustomerRegistration(const std::string &customerID, std::string &Username, std::string &FirstName, std::string &LastName, std::string &Age, std::string &RewardPoints, std::string &Card)
{
    // Implementation of customer registration functionality
    // Placeholder text for testing
    std::cout << "You have selected customer registration.";

    // Sets customerInfoFile to write
    std::ofstream customerInfoFile;
    std::string customerFileName = "customer.txt";
    // Sets customerInfoFile to append mode
    customerInfoFile.open("customer.txt", std::ios::app);
    int customerCount = 0;

    if (
        handleAge(Age) && handleCreditCard(Card) && handleFirstAndLastName(FirstName) && handleFirstAndLastName(LastName) && handleUserName(Username))
    {
        customerCount = handleCustomerCount(customerFileName);
        // Appending to customer.txt
        customerInfoFile << "Customer "<< customerCount << " " << customerID << std::endl;
        customerInfoFile << "Customer "<< customerCount << " " << Username << std::endl;
        customerInfoFile << "Customer "<< customerCount << " " << FirstName << std::endl;
        customerInfoFile << "Customer "<< customerCount << " " << LastName << std::endl;
        customerInfoFile << "Customer "<< customerCount << " " << Age << std::endl;
        customerInfoFile << "Customer "<< customerCount << " Total Rewards Points" << RewardPoints << std::endl;
        customerInfoFile << std::endl;
        return true;
    }
    else
    {
        std::cerr << "you have enterd invaild inputs\n";
        return false;
    }

}

// Checks the validity of username
//  Returns true if valid
bool handleUserName(const std::string &username)
{
    int letterCount = 0;
    int numCount = 0;

    // Check if the string contains at least 10 characters followed by at most 3 numbers
    for (char c : username)
    {
        if (isalpha(c))
        {
            letterCount++;
        }
        else if (isdigit(c))
        {
            if (letterCount < 10)
            {
                std::cout << "Username must contain at least 10 letters before numbers." << std::endl;
                return false;
            }
            numCount++;
            if (numCount > 3)
            {
                std::cout << "Username contains too many numbers (at most 3 numbers allowed after 10 letters)." << std::endl;
                return false;
            }
        }
    }

    if (letterCount < 10)
    {
        std::cout << "Username must contain at least 10 letters before numbers." << std::endl;
        return false;
    }

    // If the string passes all checks, it's a valid username
    return true;
}

// Checks validity of first/last name
// Returns true if valid
bool handleFirstAndLastName(const std::string &name)
{
    // Check the length of the string
    if (name.length() > 12)
    {
        std::cout << "Name is too long (maximum 12 characters allowed)." << std::endl;
        return false;
    }

    // Check if the string contains only alphabetic characters
    for (char c : name)
    {
        if (!isalpha(c))
        {
            std::cout << "Name contains non-alphabetic characters." << std::endl;
            return false;
        }
    }

    // If the string passes both checks, it's valid
    return true;
}

// Checks validity of age
// Returns true if valid
bool handleAge(const std::string &ageStr)
{
    // Check if the age is within the valid range (between 18 and 100)
    int age = 0;
    try
    {
        age = std::stoi(ageStr);
        if (age < 18 || age > 100)
        {
            return false;
        }
    }
    catch (const std::invalid_argument &)
    {
        return false;
    }
    catch (const std::out_of_range &)
    {
        return false;
    }

    // Check if the age doesn't start with '0'
    if (ageStr[0] == '0')
    {
        return false;
    }

    return true;
}

// Checks validity of credit card
// Returns true if valid
bool handleCreditCard(const std::string &creditCard)
{
    // Check if the credit card number is the correct length
    if (creditCard.length() != 14)
    {
        return false;
    }

    // Check if it doesn't start with '0'
    if (creditCard[0] == '0')
    {
        return false;
    }

    // Check if the 'x' characters are digits between 0 and 9
    // Checks for 'xxxx-xxxx-xxxx' format
    for (int i = 0; i < 14; i++)
    {
        if (i % 5 == 4)
        {
            if (creditCard[i] != '-')
            {
                return false;
            }
        }
        else
        {
            if (!isdigit(creditCard[i]))
            {
                return false;
            }
        }
    }

    std::cout << "CC Valid" << std::endl;
    return true;
}

// Generate a random 10-digit number
std::string generateRandomNumber()
{
    std::random_device rd;

    // Seed random generator
    std::mt19937 gen(rd());
    // Gives equal random chance to each number

    std::uniform_int_distribution<long> distribution(1000000000, 9999999999);

    long randomNum = distribution(gen);
    return std::to_string(randomNum);
}

// Takes in randomly generated #
// and combines with prefix.
// Returns the ID
std::string makeUniqueID()
{
    // Set a prefix for the customer ID
    std::string prefix = "CustID";

    // Generate a random 10-digit number
    std::string randomPart = generateRandomNumber();

    // Combine the parts to create customer ID
    std::string uniqueID = prefix + randomPart;

    return uniqueID;
}

bool handleRewardsPoint(const std::string &RewardsPoints)
{
    int letterCount = 0;
    int numCount = 0;

    // Check if the string is a ditgit and posstive
    for (char c : RewardsPoints)
    {
        if (isdigit(c) && c > 0)
        {
            return true;
        }
    }
}

// Used to read the previously used customer number
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

// Uses readNthLineUp to read the previous customer count
// increments and returns the count
int handleCustomerCount(const std::string& filename){
    int customerCount;
    // 3 was chosen to ensure the function is not reading 
    // a blank line at the bottom
    customerCount = readNthLineUp(filename, 3) + 1;
    return customerCount;
}
