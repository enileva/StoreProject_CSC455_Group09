#pragma once
#include <string>
using namespace std;
class Admin
{
public:
	static void handleProductAddition();
	static void handleProductRemoval();
	static void handleCustomerRemoval();
	static void viewCustomers();
	static int handleProductRemoval(const string& ProductRemove);
	static int handleCustomerRemoval(const string& CustomerRemove);
	static bool handleProductAddition(string& productName, string& productPrice, string& inventory);
	static void removeContentAndFollowingLines(const std::string& filename, const std::string& contentToRemove);
};