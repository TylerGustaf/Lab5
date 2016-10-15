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
	double customerNum;
	double wallet;
	//vector <Order> orders;

public:

	Customer(string name1, double custNum) : name(name1), customerNum(custNum), wallet(0){}

	string getName();
	double getCustomerNum();
	double getWallet();
	void setWallet(double newWallet);
	//void addOrder(Order order);

};
#endif