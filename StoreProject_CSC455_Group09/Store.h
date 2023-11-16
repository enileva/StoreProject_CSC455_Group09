#pragma once
#include <string>
using namespace std;
void handleShopping();
int searchForCustomerPoints(string id);
void handleRewardRedemption();
void handlePointsAwared();
bool handleProductID();
bool handleProductName();
bool handleProductPrice();
bool handleProductNumber();
void redeemPoints(string customerID, int customerPoints, int pointsDeducted);
string getNewID(int ID);