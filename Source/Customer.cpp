#include "Customer.h"


	Customer::Customer(const std::string& customerID, std::string& Username, std::string& FirstName, std::string& LastName, std::string& Age, std::string& RewardPoints)
	{
		customerID.copy(_customerID, 16);
		Username.copy(_customerUsername, 13);
		FirstName.copy(_customerFirstName, 12);
		LastName.copy(_customerLastName, 12);
		_customerAge = stoi(Age);
		_customerRewardPoints = stoi(RewardPoints);
	}