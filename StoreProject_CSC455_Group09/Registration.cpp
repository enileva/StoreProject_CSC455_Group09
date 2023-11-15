// Group 09: Aveline McEntire, Brendan Lance, Kaedon Pruiett
#define _CRT_SECURE_NO_WARNINGS
#include "Registration.h"
#include "Customer.h"
#include <iostream>
#include <string>
#include <cctype>
#include <random>
#include <sstream>
#include <fstream>
#include <sys/stat.h>
using namespace std;
void Registration::handleCustomerRegistration()
{
    string customerUsername;
    string customerFirstName;
    string customerLastName;
    string customerAge;
    string customerCreditCard;
    string customerRewardPoints;

    cout << "You have selected customer registration." << endl;
        
    cout << "Enter the customer's username: " << endl;
    cin >> customerUsername;
    cout << "Enter the customer's first name: " << endl;
    cin >> customerFirstName;
    cout << "Enter the customer's last name: " << endl;
    cin >> customerLastName;
    cout << "Enter the customer's age: " << endl;
    cin >> customerAge;
    cout << "Enter the customer's credit card: " << endl;
    cin >> customerCreditCard;
    cout << "Enter the customer's reward points: " << endl;
    cin >> customerRewardPoints;


    if (handleCustomerRegistration(customerUsername, customerFirstName, customerLastName, customerAge, customerRewardPoints, customerCreditCard))
    {
            
        // Appending to customer.txt
        // Sets customerInfoFile to write
        ofstream customerInfoFile;
        string customerFileName = "customers.txt";
        // Sets customerInfoFile to append mode
        customerInfoFile.open("customers.txt", ios::app);
        int customerCount = 1 + getBaseID("customers.txt", 7);
        string customerID = getNewID(customerCount);
        // TODO: Check custID uniqueness because of customer removal

        customerInfoFile << "Customer " << customerCount << " ID: " << customerID << endl;
        customerInfoFile << "Customer " << customerCount << " Username: " << customerUsername << endl;
        customerInfoFile << "Customer " << customerCount << " First Name: " << customerFirstName << endl;
        customerInfoFile << "Customer " << customerCount << " Last Name: " << customerLastName << endl;
        customerInfoFile << "Customer " << customerCount << " Age: " << customerAge << endl;
        customerInfoFile << "Customer " << customerCount << " Total Reward Points: " << getFormattedRewardPoints(stoi(customerRewardPoints)) << endl;
        
        customerInfoFile << endl;
        customerInfoFile.close();
        cout << "Customer successfully added." << endl;
        return;
        /*
        Customer *newCustomer = new Customer(customerID, customerUsername, customerFirstName, customerLastName, customerAge, customerRewardPoints);
        fstream customerFile;
        customerFile.open("customers.txt", fstream::app || fstream::binary);
        customerFile.write((char*)newCustomer, sizeof(Customer));
        customerFile.close();
        delete newCustomer;
        */
    }
    else
    {
        cout << "Customer was not added." << endl;
        return;
    }
}

int Registration::getBaseID(string filename, int linesPerRecord)
{
    /*
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
    */
    fstream myFile(filename, ios::in);
    if (myFile.fail())
    {
        return 0;
    }
    else
    {
        string str;
        int lines = 0;
        while (getline(myFile, str)) {
            lines++;
        }
        myFile.close();
        return lines/linesPerRecord;
    }
}
/*
int getCurrentRecordCount()
{
    long size = GetFileSize("customers.txt");
    if (size <= 0)
    {
        return 0;
    }
    else
    {
        return (int)size/sizeof(Customer);
    }
}
*/
string Registration::getNewID(int ID)
{
    char buf[20];
    sprintf(buf, "%010d", ID);
    string customerID = buf;
    return string("CustID" + customerID);
}

string Registration::getFormattedRewardPoints(int points)
{
    char buf[20];
    sprintf(buf, "%010d", points);
    string formattedPoints = buf;
    return formattedPoints;
}

bool Registration::handleCustomerRegistration(string& Username, string& FirstName, string& LastName, string& Age, string& RewardPoints, string& Card)
{
    // Implementation of customer registration functionality
    // Placeholder text for testing
    //cout << "You have selected customer registration.";
    if (
        handleAge(Age) && handleCreditCard(Card) && handleFirstAndLastName(FirstName) && handleFirstAndLastName(LastName) && handleUserName(Username))
    {
        return true;
    }
    else
    {
        return false;
    }
    /*
    // Sets customerInfoFile to write
    ofstream customerInfoFile;
    string customerFileName = "customer.txt";
    // Sets customerInfoFile to append mode
    customerInfoFile.open("customer.txt", ios::app);
    int customerCount = 0;

    if (
        handleAge(Age) && handleCreditCard(Card) && handleFirstAndLastName(FirstName) && handleFirstAndLastName(LastName) && handleUserName(Username))
    {
        customerCount = handleCustomerCount(customerFileName);
        // Appending to customer.txt
        customerInfoFile << "Customer " << customerCount << " " << customerID << endl;
        customerInfoFile << "Customer " << customerCount << " " << Username << endl;
        customerInfoFile << "Customer " << customerCount << " " << FirstName << endl;
        customerInfoFile << "Customer " << customerCount << " " << LastName << endl;
        customerInfoFile << "Customer " << customerCount << " " << Age << endl;
        customerInfoFile << "Customer " << customerCount << " Total Rewards Points" << RewardPoints << endl;
        customerInfoFile << endl;
        return true;
    }
    else
    {
        cerr << "you have enterd invaild inputs\n";
        return false;
    }
    */
}

// Checks the validity of username
//  Returns true if valid
bool Registration::handleUserName(const string& username)
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
                cout << "Username must contain at least 10 letters before numbers." << endl;
                return false;
            }
            numCount++;
            if (numCount > 3)
            {
                cout << "Username contains too many numbers (at most 3 numbers allowed after 10 letters)." << endl;
                return false;
            }
        }
    }

    if (letterCount < 10)
    {
        cout << "Username must contain at least 10 letters before numbers." << endl;
        return false;
    }

    // If the string passes all checks, it's a valid username
    return true;
}

// Checks validity of first/last name
// Returns true if valid
bool Registration::handleFirstAndLastName(const string& name)
{
    // Check the length of the string
    if (name.length() > 12)
    {
        cout << "Name is too long (maximum 12 characters allowed)." << endl;
        return false;
    }

    // Check if the string contains only alphabetic characters
    for (char c : name)
    {
        if (!isalpha(c))
        {
            cout << "Name contains non-alphabetic characters." << endl;
            return false;
        }
    }

    // If the string passes both checks, it's valid
    return true;
}

// Checks validity of age
// Returns true if valid
bool Registration::handleAge(const string& ageStr)
{
    // Check if the age is within the valid range (between 18 and 100)
    int age = 0;
    try
    {
        age = stoi(ageStr);
        if (age < 18 || age > 100)
        {
            cout << "Age invalid. Must be in range 18-100." << endl;
            return false;
        }
        else
        {
            // age is likely in correct range
        }
    }
    catch (const invalid_argument&)
    {
        cout << "Age invalid. Invalid argument." << endl;
        return false;
    }
    catch (const out_of_range&)
    {
        cout << "Age invalid. Out of range." << endl;
        return false;
    }

    // Check if the age doesn't start with '0'
    if (ageStr[0] == '0')
    {
        cout << "Age invalid. Must not start with 0." << endl;
        return false;
    }

    return true;
}

// Checks validity of credit card
// Returns true if valid
bool Registration::handleCreditCard(const string& creditCard)
{
    // Check if the credit card number is the correct length
    if (creditCard.length() != 14)
    {
        cout << "Credit card invalid. Incorrect length." << endl;
        return false;
    }

    // Check if it doesn't start with '0'
    if (creditCard[0] == '0')
    {
        cout << "Credit card invalid. Starts with 0." << endl;
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
                cout << "Credit card invalid. Format must be XXXX-XXXX-XXXX." << endl;
                return false;
            }
        }
        else
        {
            if (!isdigit(creditCard[i]))
            {
                cout << "Credit card invalid. Format must be XXXX-XXXX-XXXX." << endl;
                return false;
            }
        }
    }

    cout << "Credit card valid." << endl;
    return true;
}

// Generate a random 10-digit number
/*
string generateRandomNumber()
{
    random_device rd;

    // Seed random generator
    mt19937 gen(rd());
    // Gives equal random chance to each number

    uniform_int_distribution<long> distribution(1000000000, 9999999999);

    long randomNum = distribution(gen);
    return to_string(randomNum);
}
*/

// Takes in randomly generated #
// and combines with prefix.
// Returns the ID
/*
string makeUniqueID()
{
    // Set a prefix for the customer ID
    string prefix = "CustID";

    // Generate a random 10-digit number
    string randomPart = generateRandomNumber();

    // Combine the parts to create customer ID
    string uniqueID = prefix + randomPart;

    return uniqueID;
}
*/

bool Registration::handleRewardsPoint(const string& RewardsPoints)
{
    int letterCount = 0;
    int numCount = 0;

    // Check if the string is a ditgit and posstive
    for (char c : RewardsPoints)
    {
        if (isdigit(c) && c > 0)
        {
            // digit passes
        }
        else
        {
            cout << "Invalid input. Rewards points must be an integer 0 or larger." << endl;
            return false;
        }
    }
    return true;
}

// Used to read the previously used customer number
// Takes in a file and integer and reads n number of lines up
// from the bottom, then captures what is after the first space
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
                }
                catch (const invalid_argument& e) {
                    // Handle the case where the second word cannot be converted to an integer
                    cerr << "Error: The second word is not a valid integer." << endl;
                }
            }
        }
        else {
            // Handle the case where there are not enough lines in the file
            return 0;
        }
        inputFile.close();
    }
    else {
        // Handle the case where the file cannot be opened
        cerr << "Error: Failed to open the file for reading." << endl;
    }
    // Return a default value
    return 0;
}
*/

// Uses readNthLineUp to read the previous customer count
// increments and returns the count
/*
int handleCustomerCount(const string& filename) {
    int customerCount;
    // 3 was chosen to ensure the function is not reading 
    // a blank line at the bottom
    customerCount = readNthLineUp(filename, 3) + 1;
    return customerCount;
}
*/
/*
bool handleCustomerRegistration(const string &customerID, string &Username, string &FirstName, string &LastName, string &Age, string &RewardPoints, string &Card);
bool handleUserName(const string &username);
bool handleFirstAndLastName(const string &name);
bool handleAge(const string &ageStr);
bool handleCreditCard(const string &creditCard);
string generateRandomNumber();
string makeUniqueID();
bool handleRewardsPoint(const string &RewardsPoints);
int readNthLineUp(const string& filename, int n);
int handleCustomerCount(const string& filename);
*/

