//Made by Tyler Gustaf
#ifndef __CONTROLLER_H
#define __CONTROLLER_H 2016
#include "std_lib_facilities.h"
#include <vector>
#include "RobotModel.h"
#include "RobotPart.h"
#include "View.h"
#include "Customer.h"
#include "SalesAssoc.h"
#include "Order.h"

class Controller
{
private:
	
	Controller (Controller const&);
	void operator= (Controller const&);

	vector <RobotPart*> allParts;
	vector <RobotModel> allModels;
	vector <Order> allOrders;
	vector <SalesAssoc> allSalesAssoc;
	vector <Customer> allCustomers;
	View view;
	
	//Temporary variables for adding parts and models
	int menu, partFromList, partNum, partPosBats, maxSP, modelNum;
	int custNum, head, motor, arm, torso, battery, maxBat;
	string custName, partName, partDesc, modelName, trash;
	double partCost, partWeight, partEnergy, maxPow, modelPrice, sum;


public:
	Controller() {};
	static Controller& getInstance();

	int cli();
	void addCustomer();
	void addPart();
	void addModel();

};



#endif