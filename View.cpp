#include "std_lib_facilities.h"
#include <vector>
#include "RobotModel.h"
#include "RobotPart.h"
#include "View.h"


void View::printMM()
{
	cout <<endl;
	cout << "Main Menu" <<endl;
	cout << "---------" <<endl;
	cout << "1. Create" <<endl;
	cout << "2. Report" <<endl;
	cout << "3. Save" <<endl;
	cout << "0. Quit" <<endl;
}

void View::printCM()
{
	cout <<endl;
	cout << "Create" <<endl;
	cout << "------" <<endl;
	cout << "1. Order" <<endl;
	cout << "2. Customer" <<endl;
	cout << "3. Sales Associate" <<endl;
	cout << "4. Robot Model" <<endl;
	cout << "5. Robot Part" <<endl;
	cout << "0. Return to Main Menu" <<endl;
}

void View::printParts(vector <RobotPart*> parts)
{
	cout << "***List of All Current Parts***" <<endl;
	for(int i = 0; i < parts.size(); i++)
	{
		cout << i+1 << ".";
		cout << "\tPart Number: " << parts[i]->getPartNum() <<endl;
		cout << "\tName: " << parts[i]->getName() <<endl;
		cout << "\tCost: " << parts[i]->getCost() <<endl;
		cout << "\tWeight: " << parts[i]->getWeight() <<endl;
		cout << "\tType: " << parts[i]->getPartType() <<endl;
		if(parts[i]->getPartType() == "Motor")
		{
			cout << "\tMax Speed: " << parts[i]->getMaxSpeed() <<endl;
		}
		else if(parts[i]->getPartType() == "Battery")
		{
			cout << "\tEnergy: " << parts[i]->getEnergy() <<endl;
			cout << "\tMax Power: " << parts[i]->getPower() <<endl;
		}
		else if(parts[i]->getPartType() == "Torso")
		{
			cout << "\tPossible Batteries: " << parts[i]->getPossibleBatteries() <<endl;
		}
		cout << "\tDescription: " <<parts[i]->getDescription() <<endl<<endl;
	}
}

void View::printModels(vector <RobotModel> models)
{
	cout << "***List of All Current Models***" <<endl;
	for(int i = 0; i < models.size(); i++)
	{
		cout << i+1 << ".";
		cout << "\tModel Number: " << models[i].getModelNum() <<endl;
		cout << "\tName: " << models[i].getName() <<endl;
		cout << "\tPrice: " << models[i].getPrice() <<endl;




	}
}