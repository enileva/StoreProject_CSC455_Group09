// Group 09: Aveline McEntire, Brendan Lance, Kaedon Pruiett
#include "Registration.h"
#include <iostream>
#include <string>
#include <cctype>
#include <random>
void handleCustomerRegistration()
{
    // Implementation of customer registration functionality
    // Placeholder text for testing
    std::cout << "You have selected customer registration.";
}

//Checks the validity of username
// Returns true if valid
bool handleUserName(const std::string &username) {
    int letterCount = 0;
    int numCount = 0;

    // Check if the string contains at least 10 characters followed by at most 3 numbers
    for (char c : username) {
        if (isalpha(c)) {
            letterCount++;
        } else if (isdigit(c)) {
            if (letterCount < 10) {
                std::cout << "Username must contain at least 10 letters before numbers." << std::endl;
                return false;
            }
            numCount++;
            if (numCount > 3) {
                std::cout << "Username contains too many numbers (at most 3 numbers allowed after 10 letters)." << std::endl;
                return false;
            }
        }
    }

    if (letterCount < 10) {
        std::cout << "Username must contain at least 10 letters before numbers." << std::endl;
        return false;
    }

    // If the string passes all checks, it's a valid username
    return true;
}

// Checks validity of first/last name
// Returns true if valid
bool handleFirstAndLastName(const std::string &name) {
    // Check the length of the string
    if (name.length() > 12) {
        std::cout << "Name is too long (maximum 12 characters allowed)." << std::endl;
        return false;
    }

    // Check if the string contains only alphabetic characters
    for (char c : name) {
        if (!isalpha(c)) {
            std::cout << "Name contains non-alphabetic characters." << std::endl;
            return false;
        }
    }

    // If the string passes both checks, it's valid
    return true;
}

// Checks validity of age
// Returns true if valid
bool handleAge(const std::string &ageStr) {
    // Check if the age is within the valid range (between 18 and 100)
    int age = 0;
    try {
        age = std::stoi(ageStr);
        if (age < 18 || age > 100) {
            return false;
        }
    } catch (const std::invalid_argument&) {
        return false;
    } catch (const std::out_of_range&) {
        return false;
    }

    // Check if the age doesn't start with '0'
    if (ageStr[0] == '0') {
        return false;
    }

    return true;
}

// Checks validity of credit card
// Returns true if valid
bool handleCreditCard(const std::string &creditCard) {
    // Check if the credit card number is the correct length
    if (creditCard.length() != 14) {
        return false;
    }

    // Check if it doesn't start with '0'
    if (creditCard[0] == '0') {
        return false;
    }

    // Check if the 'x' characters are digits between 0 and 9
    // Checks for 'xxxx-xxxx-xxxx' format
    for (int i = 0; i < 14; i++) {
        if (i % 5 == 4) {
            if (creditCard[i] != '-') {
                return false;
            }
        } else {
            if (!isdigit(creditCard[i])) {
                return false;
            }
        }
    }

    std::cout << "CC Valid" << std::endl;
    return true;
}

// Generate a random 10-digit number
std::string generateRandomNumber() {
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
std::string makeUniqueID() {
    // Set a prefix for the customer ID
    std::string prefix = "CustID";

    // Generate a random 10-digit number
    std::string randomPart = generateRandomNumber();

    // Combine the parts to create customer ID
    std::string uniqueID = prefix + randomPart;

    return uniqueID;
}

void StartRewardsPoint()
{
    // add code here
}