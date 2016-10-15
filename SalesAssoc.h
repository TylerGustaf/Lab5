//Made by Tyler Gustaf
#ifndef __SALESASSOC_H
#define __SALESASSOC_H 2016
#include <string.h>
#include <iostream>
#include <vector>
//#include "Order.h"

using namespace std;

class SalesAssoc
{
private:
	string name;
	int employeeNum;
	//vector <Order> orders;

public:
	SalesAssoc(string name1, int employNum) : name(name1), employeeNum(employNum){}

	string getName();
	int getEmployeeNum();
	//void addOrder(Order order);

};
#endif