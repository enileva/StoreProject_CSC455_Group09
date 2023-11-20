#pragma once
#include <string>
using namespace std;

class Registration
{
public:
	void handleCustomerRegistration();
	static int getBaseID(string filename, int linesPerRecord);
	static string getFormattedRewardPoints(int points);
	static string getNewID(int ID);
private:
	bool handleCustomerRegistration(string& Username, string& FirstName, string& LastName, string& Age, string& RewardPoints, string& Card);
	bool handleUserName(const string& username);
	bool handleFirstAndLastName(const string& name);
	bool handleAge(const string& ageStr);
	bool handleCreditCard(const string& creditCard);
	bool handleRewardsPoint(const string& RewardsPoints);
	//int readNthLineUp(const string& filename, int n);
	//int handleCustomerCount(const string& filename);
};
