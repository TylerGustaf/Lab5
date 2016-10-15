//Made by Tyler Gustaf
#include "std_lib_facilities.h"
#include "RobotModel.h"
#include "RobotPart.h"
#include <vector>
#include "View.h"
#include "Controller.h"


int main()
{
	vector <RobotPart*> allParts;
	vector <RobotModel> allModels;
	View view;

	allParts.push_back(new Head("Robs Head", "The head of a nice robot", 4, 15.25, 25.52));
	allParts.push_back(new Torso("Robs Torso", "The torso of a nice robot", 3, 20.50, 35.25, 2));
	allParts.push_back(new Arm("Robs Arm", "The arm of a nice robot", 5, 12.02, 18.92));
	allParts.push_back(new Motor("Robs Motor", "The motor of a nice robot", 2, 30.25, 45.26, 54));
	allParts.push_back(new Battery("Robs Battery", "The battery of a nice robot", 1, 5.50, 3.25, 16, 35));

	allModels.push_back(RobotModel());

	allModels[0].addPart(allParts[1]);
	allModels[0].addPart(allParts[0]);
	allModels[0].addPart(allParts[2]);
	allModels[0].addPart(allParts[2]);
	allModels[0].addPart(allParts[4]);

	allModels[0].setModelNum(1);
	allModels[0].setPrice(10.00);
	allModels[0].setName("Model1");
	allModels.push_back(RobotModel());

	allModels[1].addPart(allParts[0]);
	allModels[1].addPart(allParts[2]);
	allModels[1].addPart(allParts[1]);
	allModels[1].addPart(allParts[3]);
	allModels[1].addPart(allParts[4]);

	allModels[1].setModelNum(2);
	allModels[1].setPrice(20.00);
	allModels[1].setName("Model2");

	view.printModels(allModels);
	view.printModelParts(allModels[1]);

	return 0;
}