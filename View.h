//Made by Tyler Gustaf
#ifndef __VIEW_H
#define __VIEW_H 2016
#include "std_lib_facilities.h"
#include <vector>
#include "RobotModel.h"
#include "RobotPart.h"
#include "Customer.h"

class View
{
private:

public:
	View(){}

	void printMM();
	void printCM();
	void printRM();
	void printCustomers(vector <Customer> customers);
	void printParts(vector <RobotPart*> parts);
	void printModels(vector <RobotModel> models);
	void printModelParts(RobotModel model);


};




#endif