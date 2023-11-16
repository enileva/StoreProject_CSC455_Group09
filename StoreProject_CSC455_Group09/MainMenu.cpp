// MainMenu.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Group 09: Aveline McEntire, Brendan Lance, Kaedon Pruiett
/* Some notes; I've changed my mind that we should include a login.cpp. I think it makes more sense to have a file for registration to replace login.cpp
   and have users login on the store pages. This avoids confusion for an admin login, which requires a password only on the admin pages. - Aveline */

#include <iostream>

// We will include headers so we can access the other cpp files.
#include "Registration.h"
#include "Admin.h"
#include "Store.h"

int main()
{
    Registration *Reg = new Registration();
    std::string userInput;
    char menuChoice;
    while (true)
    {
        std::cout << "Welcome to the Super Rewards system!\n\n";
        std::cout << "Please choose from the following options:\n";
        std::cout << "A. Customer registration\n";    // Registration.cpp
        std::cout << "B. Shopping\n";                 // Store.cpp
        std::cout << "C. Redeem rewards\n";           // Store.cpp
        std::cout << "D. Product addition (admin)\n"; // Admin.cpp
        std::cout << "E. Product removal (admin)\n";  // Admin.cpp
        std::cout << "F. Customer removal (admin)\n"; // Admin.cpp
        std::cout << "G. View a customer (admin)\n";   // Admin.cpp
        std::cout << "H. Stop the program\n\n";       // Break

        std::cin >> userInput;
        // Check if the input string has exactly one character
        if (userInput.length() == 1)
        {
            menuChoice = userInput[0];

            // Check if the input is a letter
            if (isalpha(menuChoice))
            {
                // switch to other cpp file with choice here.
                switch (menuChoice)
                {
                case 'A':
                    Reg->handleCustomerRegistration();
                    break;
                case 'B':
                    handleShopping();
                    break;
                case 'C':
                    handleRewardRedemption();
                    break;
                case 'D':
                    Admin::handleProductAddition();
                    break;
                case 'E':
                    Admin::handleProductRemoval();
                    break;
                case 'F':
                    Admin::handleCustomerRemoval();
                    break;
                case 'G':
                    Admin::viewCustomers();
                    break;
                case 'H':
                    break;
                default:
                    std::cout << "Invalid choice.\n";
                }
            }
            else
            {
                std::cout << "Invalid input. Please enter a letter." << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid input. Please enter exactly one character." << std::endl;
        }
    }
    delete Reg;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
