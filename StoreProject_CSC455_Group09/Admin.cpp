// Group 09: Aveline McEntire, Brendan Lance, Kaedon Pruiett
#include "Admin.h"
#include <iostream>

int handleProductAddition(const std::string &ProudctAdd)
{
    // Implementation of product addition functionality
    // Placeholder text for testing
    products.txt.append(ProudctAdd);
    std::cout << "You have selected product addition.";
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