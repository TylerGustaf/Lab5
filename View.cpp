//Made by Tyler Gustaf
#include "std_lib_facilities.h"
#include <vector>
#include "RobotModel.h"
#include "RobotPart.h"
#include "Customer.h"
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

void View::printRM()
{
	cout <<endl;
	cout << "Report" <<endl;
	cout << "------" <<endl;
	cout << "1. Orders" <<endl;
	cout << "2. Customers" <<endl;
	cout << "3. Sales Associates" <<endl;
	cout << "4. Robot Models" <<endl;
	cout << "5. Robot Parts" <<endl;
	cout << "0. Return to Main Menu" <<endl;
}

void View::printCustomers(vector <Customer> customers)
{
	cout << "***List of All Current Customers***" <<endl;
	for(int i = 0; i < customers.size(); i++)
	{
		cout << i+1 << ".";
		cout << "\tCustomer Name: " << customers[i].getName() <<endl;
		cout << "\tCustomer Number: " << customers[i].getCustomerNum() <<endl;
		cout << "\tWallet: " << customers[i].getWallet() <<endl;
	}
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

void View::printModelParts(RobotModel model)
{
	cout << "***List of All Model's Parts***" <<endl;
	for(int i = 0; i < model.getNumOfParts(); i++)
	{
		cout << i+1 << ".";
		cout << "\tPart Number: " << model.getPart(i)->getPartNum() <<endl;
		cout << "\tName: " << model.getPart(i)->getName() <<endl;
		cout << "\tCost: " << model.getPart(i)->getCost() <<endl;
		cout << "\tWeight: " << model.getPart(i)->getWeight() <<endl;
		cout << "\tType: " << model.getPart(i)->getPartType() <<endl;
		if(model.getPart(i)->getPartType() == "Motor")
		{
			cout << "\tMax Speed: " << model.getPart(i)->getMaxSpeed() <<endl;
		}
		else if(model.getPart(i)->getPartType() == "Battery")
		{
			cout << "\tEnergy: " << model.getPart(i)->getEnergy() <<endl;
			cout << "\tMax Power: " << model.getPart(i)->getPower() <<endl;
		}
		else if(model.getPart(i)->getPartType() == "Torso")
		{
			cout << "\tPossible Batteries: " << model.getPart(i)->getPossibleBatteries() <<endl;
		}
		cout << "\tDescription: " << model.getPart(i)->getDescription() <<endl<<endl;

	}
}