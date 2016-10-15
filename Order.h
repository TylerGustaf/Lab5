//Made by Tyler Gustaf
#ifndef __ORDER_H
#define __ORDER_H 2016
#include <string.h>
#include <iostream>
#include "RobotModel.h"
#include "Customer.h"
#include "SalesAssoc.h"

using namespace std;

class Order
{
private:
	int orderNum;
	RobotModel robot;
	SalesAssoc seller;
	Customer buyer;

public:
	Order(int num, RobotModel model, SalesAssoc saleAssoc, Customer cust) : orderNum(num), robot(model), seller(saleAssoc), buyer(cust){}

	int getOrderNum();
	RobotModel getRobot();
	SalesAssoc getSeller();
	Customer getBuyer();

};
#endif