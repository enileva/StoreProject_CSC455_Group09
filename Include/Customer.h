#pragma once
#include <string>
class Customer
{
public:
	char _customerID[16];
	char _customerUsername[13];
	char _customerFirstName[12];
	char _customerLastName[12];
	int _customerAge;
	int _customerRewardPoints;
    Customer(const std::string& customerID, std::string& Username, std::string& FirstName, std::string& LastName, std::string& Age, std::string& RewardPoints);
};

