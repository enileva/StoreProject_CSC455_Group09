// Group 09: Aveline McEntire, Brendan Lance, Kaedon Pruiett
#include "Store.h"
#include <iostream>

void handleShopping()
{
    // Code for shopping
    // Placeholder text for testing
    std::cout << "You have selected shopping.";
}

void handleRewardRedemption()
{
    // Code for redeeming rewards
    // Placeholder text for testing
    std::cout << "You have selected rewards.";
}
void handlePointsAwared()
{
    // add code here
}

bool handleProductID(const std::string &ProudctID)
{
    int letterCount = 0;
    int numCount = 0;

    // Check if the string contains Prod followed by 5 ditgits
    for (char c : ProudctID)
    {
        if (isalpha(c))
        {
            letterCount++;
        }
        else if (isdigit(c))
        {
            if (c != 'Prod')
            {
                std::cout << "Must be Prod before numbers." << std::endl;
                return false;
            }
            numCount++;
            if (numCount != 5)
            {
                std::cout << "Username contains too many numbers (only 5 numbers allowed after Prod)." << std::endl;
                return false;
            }
        }
    }

    /* IS this needed?    if (letterCount < 10)
        {
            std::cout << "Username must contain at least 10 letters before numbers." << std::endl;
            return false;
        }*/

    // If the string passes all checks, it's a valid username
    return true;
}

bool handleProductName(const std::string &Proudctname)
{
    // Check the length of the string
    if (Proudctname.length() > 12)
    {
        std::cout << "Name is too long (maximum 12 characters allowed)." << std::endl;
        return false;
    }

    // Check if the string contains only alphabetic characters
    for (char c : Proudctname)
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

void handleProductPrice()
{
    // add code here
}

bool handlePrdouctNumer(const std::string &ProudctNumber)
{
    int letterCount = 0;
    int numCount = 0;

    // Check if the string is a ditgit and posstive
    for (char c : ProudctNumber)
    {
        if (isdigit(c) && c > 0)
        {
            return true;
        }
    }
}
