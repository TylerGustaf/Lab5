#include "std_lib_facilities.h"
#include <vector>
#include "RobotModel.h"
#include "RobotPart.h"
#include "View.h"

#ifndef __CONTROLLER_H
#define __CONTROLLER_H 2016

class Controller
{
private:
	
	Controller (Controller const&);
	void operator= (Controller const&);

	vector <RobotPart*> allParts;
	vector <RobotModel> allModels;
	View view;
	
	//Temporary variables for adding parts and models
	int menu, partFromList, partNum, partPosBats, maxSP, modelNum;
	int head, motor, arm, torso, battery, maxBat;
	string partName, partDesc, modelName, trash;
	double partCost, partWeight, partEnergy, maxPow, modelPrice, sum;


public:
	Controller() {};
	static Controller& getInstance();

	int cli();
	void addPart();
	void addModel();

};



#endif