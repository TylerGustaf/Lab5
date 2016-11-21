//Made by Tyler Gustaf
#ifndef __CUSTOMER_H
#define __CUSTOMER_H 2016
#include <string.h>
#include <iostream>
#include <vector>
//#include "Order.h"

using namespace std;

class Customer
{
private:

	string name;
	int customerNum;
	double wallet;
	//vector <Order> orders;
	string custPhone;
	string custEmail;

public:

	Customer(string name1, int custNum, double wal, string phone, string email) : name(name1), customerNum(custNum), custPhone(phone), custEmail(email), wallet(wal){}

	string getName();
	int getCustomerNum();
	double getWallet();
	void setWallet(double newWallet);
	//void addOrder(Order order);
	string getPhone();
	string getEmail();

};
#endif