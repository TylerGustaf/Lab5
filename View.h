//Made by Tyler Gustaf
#ifndef __VIEW_H
#define __VIEW_H 2016
#include "std_lib_facilities.h"
#include <vector>
#include "RobotModel.h"
#include "RobotPart.h"
#include "Customer.h"
#include "SalesAssoc.h"
#include "Order.h"

class View
{
private:

public:
	View(){}

	void printMM();
	void printCM();
	void printRM();
	void printOrders(vector <Order> orders);
	void printCustomers(vector <Customer> customers);
	void printSalesAssoc(vector <SalesAssoc> salesAssoc);
	void printParts(vector <RobotPart*> parts);
	void printModels(vector <RobotModel> models);
	void printModelParts(RobotModel model);


};




#endif