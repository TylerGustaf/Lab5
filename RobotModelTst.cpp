#include "std_lib_facilities.h"
#include "RobotModel.h"
#include "RobotPart.h"
#include <vector>
#include "View.h"

int main()
{
	vector <RobotPart*> allParts;
	vector <RobotModel> allModels;
	View view;

	allParts.push_back(new Arm("Robs Arm", "The arm of a nice robot", 1, 45.99, 69.69));
	allParts.push_back(new Torso("Robs Torso", "The body of a nice robot", 2, 55.99, 79.69, 2));
	allParts.push_back(new Head("Robs Head", "The head of a nice robot", 3, 25.99, 39.69));
	allParts.push_back(new Battery("Robs Battery", "The battery of a nice robot", 4, 15.99, 10.69, 19, 25));
	allParts.push_back(new Motor("Robs Motor", "The motor of a nice robot", 5, 22.99, 65.01, 50));
	allParts.push_back(new Battery("Robs Battery2", "The 2nd battery of a nice robot", 6, 15.99, 12.69, 22, 28));

	view.printParts(allParts);

	allModels.push_back(RobotModel());
	allModels[0].addPart(allParts[1]);
	allModels[0].addPart(allParts[2]);
	allModels[0].addPart(allParts[0]);
	allModels[0].addPart(allParts[5]);
	allModels[0].addPart(allParts[4]);
	
	double sum = 0;
	for(int i = 0; i < 5; i++) 
	{
		cout << "Name: " << allModels[0].getPart(i)->getName();
		cout << ", Cost : " << allModels[0].getPart(i)->getCost() <<endl;
		sum += allModels[0].getPart(i)->getCost();
	}
	cout << "Total Cost: " << sum <<endl<<endl;

	allModels[0].setPrice(sum+20);
	allModels[0].setName("Robbie");
	allModels[0].setModelNum(50);

	view.printModels(allModels);

	return 0;
}
