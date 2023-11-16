// Group 09: Aveline McEntire, Brendan Lance, Kaedon Pruiett
#include "Store.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <random>
#include <sstream>
#include <sys/stat.h>
#include "Registration.h"
using namespace std;

void handleShopping() // check this function
{
    // Code for shopping
    // Placeholder text for testing
    cout << "You have selected shopping." << endl;
    fstream productFile;
    productFile.open("products.txt", std::ios::in);
    if (productFile.fail())
    {
        cout << "Nothing in stock currently. Please await new products." << endl;
        return;
    }
    else
    {
        // There are products to buy...
    }
    string customerID;
    cout << "Enter customer ID (starts with \"CustID\"): " << endl;
    ofstream transactionFile;                                // Set to write
    transactionFile.open("transactions.txt", std::ios::app); // Set to append to products.txt

    cin >> customerID;
    int customerPoints = searchForCustomerPoints(customerID);
    if (customerPoints < 0)
    {
        cout << "Customer not found." << endl;
        if (!transactionFile.fail())
        {
            transactionFile.close();
        }
        else
        {
            // no need to close transaction file if it doesn't exist..
        }
        return;
    }
    else
    {
        cout << "Customer found." << endl;
        /* The shopping page has to be dynamic in order for the admin to put in products.
        cout << "A. Milk $10." << endl;
        cout << "B. Eggs $5" << endl;
        cout << "C. Table $50" << endl;
        cin >> customerChoice;
        switch (customerChoice)
        {
        case 'A':
            cout << "You have selected Milk $10";
            transactionFile << "ID " << customerID << " Product: Milk"
                            << "Price $10"
                            << "Total reward points 40 " << endl;

        case 'B':
            cout << "You have selected Eggs $5";
            transactionFile << "ID " << customerID << " Product: Eggs"
                            << "Price $5"
                            << "Total reward points 20 " << endl;
        case 'C':
            cout << "You have selected Table $50";
            transactionFile << "ID " << customerID << " Product: Table"
                            << "Price $50"
                            << "Total reward points 100 " << endl;
        
        }
        */
    }
    cout << "Products: " << endl;
    string line;
    while (getline(productFile, line))
    {
        cout << line << endl;
    }
    cout << "Please input which product you would like to purchase by product ID (must start with \"Prod\")." << endl;
    bool productLoop = true;
    string productID;
    while (productLoop)
    {
        cin >> productID;
        if (productID.find("Prod"))
        {
            productLoop = false;
            break;
        }
        else
        {
            cout << "Product ID must start with \"Prod\"." << endl;
        }
    }
    
    string strID;
    int lines = 0;
    while (getline(productFile, strID))
    {
        if (strID.find(productID))
        {
            string productName;
            string name;
            string productPrice;
            string price;
            string productInventory;
            if (!getline(productFile, productName)) // Go through each detail.
            {
                name = productName.substr(10);
                productFile.close();
                return;
            }
            else
            {
                // record found!
            }
            if (!getline(productFile, productPrice))
            {
                productFile.close();
                return;
            }
            else
            {
                // record found!
            }
            if (!getline(productFile, productInventory))
            {
                // todo: remove from inventory
                productFile.close();
                return;
            }
            else
            {
                cout << "Item purchased." << endl;
                int transactionCount = 1 + Registration::getBaseID("transactions.txt", 6);
                string transactionID = getNewID(transactionCount);
                transactionFile << "Transaction ID " << transactionID << endl << "User ID "
                    << customerID << "Product ID " << productID << "Product Name" << name;
                productFile.close();
                return;
            }
        }
        else
        {
            cout << "Unable to find product with matching ID." << endl;
        }
    }
}

string getNewID(int ID)
{
    char buf[20];
    sprintf(buf, "%010d", ID);
    string transactID = buf;
    return string("Transaction" + transactID);
}

void handleRewardRedemption()
{
    string customerID;
    char customerChoice;
    cout << "You have selected rewards." << endl;
    cout << "Enter customer ID (starts with \"CustID\"): " << endl;
    cin >> customerID;
    int customerPoints = searchForCustomerPoints(customerID);
    if (customerPoints < 0)
    {
        cout << "Customer not found." << endl;
        return;
    }
    else
    {
        cout << "A. Redeem 10% off for 100 points." << endl;
        cout << "B. Redeem $10 card for 500 points." << endl;
        cout << "C. Redeem an in-store item for 2500 points." << endl;
        cin >> customerChoice;
        switch (customerChoice)
        {
        case 'A':
            if (customerPoints >= 100)
            {
                cout << "You redeemed 10% off for 100 points!" << endl;
                redeemPoints(customerID, customerPoints, 100);
            }
            else
            {
                cout << "You don't have enough points for this item." << endl;
            }
        case 'B':
            if (customerPoints >= 500)
            {
                cout << "You redeemed $10 card for 500 points!" << endl;
                redeemPoints(customerID, customerPoints, 500);
            }
            else
            {
                cout << "You don't have enough points for this item." << endl;
            }
        case 'C':
            if (customerPoints >= 2500)
            {
                cout << "You redeemed in-store item for 2500 points!" << endl;
                redeemPoints(customerID, customerPoints, 2500);
            }
            else
            {
                cout << "You don't have enough points for this item." << endl;
            }
        }
    }
}

void redeemPoints(string customerID, int customerPoints, int pointsDeducted)
{
    fstream myFile("customers.txt", ios::in);
    if (myFile.fail())
    {
        // TODO: Log failure
        cout << "Customers file does not exist." << endl;
        return;
    }
    else
    {
        // TODO: Log success
    }
    // Begin process of finding reward points. We can't really
    // reuse the last function because the change must occur inside
    // of the while loop.
    string strID;
    int lines = 0;
    while (getline(myFile, strID))
    {
        if (strID.find(customerID))
        {
            string strUsername;
            string strFirstName;
            string strLastName;
            string strAge;
            string strRewardPoints;
            if (!getline(myFile, strUsername)) // Go through each detail.
            {
                myFile.close();
                return;
            }
            else
            {
                // record found!
            }
            if (!getline(myFile, strFirstName))
            {
                myFile.close();
                return;
            }
            else
            {
                // record found!
            }
            if (!getline(myFile, strLastName))
            {
                myFile.close();
                return;
            }
            else
            {
                // record found!
            }
            if (!getline(myFile, strAge))
            {
                myFile.close();
                return;
            }
            else
            {
                // record found!
            }
            if (!getline(myFile, strRewardPoints)) // Now that we've found reward points we can rest assured this is not a partial record.
            {
                myFile.close();
                return;
            }
            else
            {
                // record found!
                int pos = (int)strRewardPoints.find(" Total Reward Points: ");                           // Find position of reward points in string
                int newCustomerPoints = customerPoints - pointsDeducted;                                 // Get new value of reward points
                string strNewCustomerPoints = Registration::getFormattedRewardPoints(newCustomerPoints); // Format points to equal 10 char total
                strRewardPoints.replace(pos, 10, strNewCustomerPoints);                                  // Replace old points value with new points value
                // string points = strRewardPoints.substr(pos);
                myFile.close();
                return;
            }
        }
    }
    myFile.close();
}

int searchForCustomerPoints(string id)
{
    fstream myFile("customers.txt", ios::in);
    if (myFile.fail())
    {
        // TODO: Log failure
        cout << "Customers file does not exist." << endl;
        return -1;
    }
    else
    {
        // TODO: Log success
    }
    string strID;
    int lines = 0;
    while (getline(myFile, strID))
    {
        if (strID.find(id))
        {
            string strUsername;
            string strFirstName;
            string strLastName;
            string strAge;
            string strRewardPoints;
            if (!getline(myFile, strUsername))
            {
                myFile.close();
                return -1;
            }
            else
            {
                // record found!
            }
            if (!getline(myFile, strFirstName))
            {
                myFile.close();
                return -1;
            }
            else
            {
                // record found!
            }
            if (!getline(myFile, strLastName))
            {
                myFile.close();
                return -1;
            }
            else
            {
                // record found!
            }
            if (!getline(myFile, strAge))
            {
                myFile.close();
                return -1;
            }
            else
            {
                // record found!
            }
            if (!getline(myFile, strRewardPoints))
            {
                myFile.close();
                return -1;
            }
            else
            {
                // record found!
                int pos = (int)strRewardPoints.find(" Total Reward Points: ");
                string points = strRewardPoints.substr(pos + 31);
                myFile.close();
                return stoi(points);
            }
        }
    }
    myFile.close();

    return -1;
}
/*
int handleRewardRedemption(const string &Redem, string &Points)
{
    // Code for redeeming rewards
    // Placeholder text for testing
    // cout << "You have selected rewards.";
    char redemChoice;
    redemChoice = Redem[0];
    if (isalpha(redemChoice))
    {
        // switch to other cpp file with choice here.
        switch (redemChoice)
        {
        case 'A':// && Points == "100":
            cout << "you redemed a 10% off\n";
            break;
        case 'B' && Points == "500":
            cout << "you redemed a $10 card\n";
            break;
        case 'C' && Points == "2500":
            cout << "you redemed a instore item\n";
        }
    }
}

int handlePointsAwared(const string &Points)
{
    // add code here
    Points = Points + '50'; // THIS NEEDS FIXED
    cout << "you have recieved 50 more points";
}
*/
/*
bool handleProductID(const string &ProductID)
{
    int letterCount = 0;
    int numCount = 0;

    // Check if the string contains Prod followed by 5 ditgits
    for (char c : ProductID)
    {
        if (isalpha(c))
        {
            letterCount++;
        }
        else if (isdigit(c))
        {
            if (c != 'Prod')
            {
                cout << "Must be Prod before numbers." << endl;
                return false;
            }
            numCount++;
            if (numCount != 5)
            {
                cout << "Username contains too many numbers (only 5 numbers allowed after Prod)." << endl;
                return false;
            }
        }
    }

    /* IS this needed?    if (letterCount < 10)
        {
            cout << "Username must contain at least 10 letters before numbers." << endl;
            return false;
        }

        // If the string passes all checks, it's a valid username
return true;
}
*/

bool handleProductName(const string &ProductName)
{
    // Check the length of the string
    if (ProductName.length() > 12)
    {
        cout << "Name is too long (maximum 12 characters allowed)." << endl;
        return false;
    }

    // Check if the string contains only alphabetic characters
    for (char c : ProductName)
    {
        if (!isalpha(c))
        {
            cout << "Name contains non-alphabetical characters." << endl;
            return false;
        }
    }

    // If the string passes both checks, it's valid
    return true;
}

bool handleProductPrice(const string &ProductPrice)
{
    // check to see if ProductPrice is a number
    for (char c : ProductPrice)
    {
        if (isdigit(c))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool handleProductNumber(const string &ProductNumber)
{
    int letterCount = 0;
    int numCount = 0;

    // Check if the string is a ditgit and posstive
    for (char c : ProductNumber)
    {
        if (isdigit(c) && c > 0)
        {
            return true;
        }
    }
    return false;
}
