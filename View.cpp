#include "std_lib_facilities.h"
#include <vector>
#include "RobotModel.h"
#include "RobotPart.h"
#include "View.h"


void View::printParts(vector <RobotPart*> &parts)
{
	cout << "***List of All Current Parts***" <<endl;
	for(int i = 0; i < parts.size(); i++)
	{
		cout << "Part Number: " << parts[i]->getPartNum() <<endl;
		cout << "Name: " << parts[i]->getName() <<endl;
		cout << "Cost: " << parts[i]->getCost() <<endl;
		cout << "Weight: " << parts[i]->getWeight() <<endl;
		cout << "Type: " << parts[i]->getPartType() <<endl;
		if(parts[i]->getPartType() == "Motor")
		{
			cout << "Max Speed: " << parts[i]->getMaxSpeed() <<endl;
		}
		else if(parts[i]->getPartType() == "Battery")
		{
			cout << "Energy: " << parts[i]->getEnergy() <<endl;
			cout << "Max Power: " << parts[i]->getPower() <<endl;
		}
		else if(parts[i]->getPartType() == "Torso")
		{
			cout << "Possible Batteries: " << parts[i]->getPossibleBatteries() <<endl;
		}
		cout << "Description: " <<parts[i]->getDescription() <<endl<<endl;
	}
}