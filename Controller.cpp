//Made by Tyler Gustaf
#include "std_lib_facilities.h"
#include "RobotModel.h"
#include "RobotPart.h"
#include <vector>
#include "View.h"
#include "Controller.h"
#include "Customer.h"
#include "SalesAssoc.h"
#include "Order.h"


Controller& Controller::getInstance(){static Controller instance; return instance;}

int Controller::cli()
{
	do
	{
		view.printMM();
		cin >> menu;

		if(menu == 1)
		{
			do
			{
				view.printCM();
				cin >> menu;
				if(menu == 1){addOrder();}

				else if(menu == 2){addCustomer();}

				else if(menu == 3){addSalesAssoc();}

				else if(menu == 4){addModel();}

				else if(menu == 5){addPart();}

			}while(menu != 0);
			menu = -1;
		}
		
		else if(menu == 2)
		{
			do
			{
				view.printRM();
				cin >> menu;
				if(menu == 1){view.printOrders(allOrders);}

				else if(menu == 2){view.printCustomers(allCustomers);}

				else if(menu == 3){view.printSalesAssoc(allSalesAssoc);}

				else if(menu == 4)
				{
					do
					{
						view.printModels(allModels);
						cout <<endl << "Enter a Model's List Number to View its Parts (0 to Exit)" <<endl;
						cin >> menu;
						if(menu > 0 && menu <= allModels.size())
						{
							view.printModelParts(allModels[menu-1]);
							getline(cin, trash);
							cout <<endl << "Enter any key to return to List of Models" <<endl;
							getline(cin, trash);
						}

					}while(menu != 0);
					menu = -1;
				}

				else if(menu == 5){addPart();}

			}while(menu != 0);
			menu = -1;
		}

		else if(menu == 3){printf("\nFeature not yet implimented\n");}


	}while(menu != 0);

	return 0;
}

void Controller::addCustomer()
{
	cout << "Please enter the Customer's Name" <<endl;
	getline(cin, trash);
	getline(cin, name);
	cout << "Please enter the Customer's Phone Number (Without -'s)" <<endl;
	cin >> custNum;
	//allCustomers.push_back(Customer(name, custNum));
}

void Controller::addSalesAssoc()
{
	cout << "Please enter the Sales Associate's Name" <<endl;
	getline(cin, trash);
	getline(cin, name);
	cout << "Please enter their Employee Number" <<endl;
	cin >> num;
	allSalesAssoc.push_back(SalesAssoc(name, num));
}

void Controller::addOrder()
{
	if(allModels.size() < 1)
	{
		cout << "No Models Found. Please Try Again When Models are Available" <<endl;
		return;
	}
	if(allCustomers.size() < 1)
	{
		cout << "No Customers Found. Please Try Again When Customers are Registered" <<endl;
		return;
	}
	if(allSalesAssoc.size() < 1)
	{
		cout << "No Sales Associates Found. Please Try Again When Associates are Registered" <<endl;
		return;
	}

	cout << "Please enter an Order Number" <<endl;
	cin >> num;
	do
	{
		cout << "**Please select a Model from Our**" <<endl;
		view.printModels(allModels);
		cin >> modelNum;
	}while(modelNum < 1 || modelNum > allModels.size());
	cout << "Please enter a Quantity" << endl;
	cin >> quan;
	do
	{
		cout << "**Please select a Sales Associate from Our**" << endl;
		view.printSalesAssoc(allSalesAssoc);
		cin >> seller;
	}while(seller < 1 || seller > allSalesAssoc.size());
	do
	{
		cout << "**Please select a Customer from Our**" << endl;
		view.printCustomers(allCustomers);
		cin >> cust;
	}while(cust < 1 || cust > allCustomers.size());
	
	allOrders.push_back(Order(num, allModels[modelNum-1], quan, allSalesAssoc[seller-1], allCustomers[cust-1]));
}

void Controller::addPart()
{
	cout << "Choose a Part from the List" <<endl;
	cout << "1. Head" <<endl << "2. Torso" <<endl << "3. Arm" << endl;
	cout << "4. Motor" <<endl << "5. Battery" <<endl;
	cin >> partFromList;
	cout << "Please enter the Name of the Part: ";
	getline(cin, trash);
	getline(cin, partName);
	//cout << partName <<endl;
	cout << "Please enter the Part Number: ";
	cin >> partNum;
	cout << "Please enter the Cost of the Part: ";
	cin >> partCost;
	cout << "Please enter the Weight of the Part: ";
	cin >> partWeight;
	cout << "Please enter a Description of the Part:" <<endl;
	getline(cin, trash);
	getline(cin, partDesc);
	

	if(partFromList == 1)
	{
		allParts.push_back(new Head(partName, partDesc, partNum, partCost, partWeight));
	}
	else if(partFromList == 2)
	{
		cout << "Please enter the Number of Batteries Possible: ";
		cin >> partPosBats;
		allParts.push_back(new Torso(partName, partDesc, partNum, partCost, partWeight, partPosBats));
	}
	else if(partFromList == 3)
	{
		allParts.push_back(new Arm(partName, partDesc, partNum, partCost, partWeight));
	}
	else if(partFromList == 4)
	{
		cout << "Please enter the Max Speed of the Motor: ";
		cin >> maxSP;
		allParts.push_back(new Motor(partName, partDesc, partNum, partCost, partWeight, maxSP));
	}
	else if(partFromList == 5)
	{
		cout << "Please enter the Energy of the Battery: ";
		cin >> partEnergy;
		cout << "Please enter the Max Power of the Battery: ";
		cin >> maxPow;
		allParts.push_back(new Battery(partName, partDesc, partNum, partCost, partWeight, partEnergy, maxPow));
	}
}

void Controller::addModel()
{
	head = 0; arm = 0; torso = 0; battery = 0; motor = 0; maxBat = 3;
	allModels.push_back(RobotModel());
	do
	{
		cout << "Choose a Part from the List" <<endl <<"Enter 0 to Continue" <<endl;
		view.printParts(allParts);
		cin >> partFromList;

		if(partFromList >= 1 && partFromList <= allParts.size())
		{
			if(allParts[partFromList-1]->getPartType() == "Head")
			{
				if(head > 0)
				{
					cout << "You already have a Part of this Type." <<endl;
				}
				else
				{
					allModels[allModels.size()-1].addPart(allParts[partFromList-1]);
					head++;
				}
			}
			else if(allParts[partFromList-1]->getPartType() == "Arm")
			{
				if(arm > 1)
				{
					cout << "You already have two Parts of this Type." <<endl;
				}
				else
				{
					allModels[allModels.size()-1].addPart(allParts[partFromList-1]);
					arm++;
				}

			}
			else if(allParts[partFromList-1]->getPartType() == "Torso")
			{
				if(torso > 0)
				{
					cout << "You already have a Part of this Type." <<endl;
				}
				else
				{
					if(battery > allParts[partFromList-1]->getPossibleBatteries())
					{
						cout << "You have too many Batteries for this Torso." <<endl;
					}
					else
					{
						allModels[allModels.size()-1].addPart(allParts[partFromList-1]);
						torso++;
						maxBat = allParts[partFromList-1]->getPossibleBatteries();
					}
				}
	
			}
			else if(allParts[partFromList-1]->getPartType() == "Motor")
			{
				if(motor > 0)
				{
					cout << "You already have a Part of this Type." <<endl;
				}
				else
				{
					allModels[allModels.size()-1].addPart(allParts[partFromList-1]);
					motor++;
				}
			}
			else if(allParts[partFromList-1]->getPartType() == "Battery")
			{
				if(battery >= maxBat)
				{
					cout << "You already have enough Parts of this Type." <<endl;
				}
				else
				{
					allModels[allModels.size()-1].addPart(allParts[partFromList-1]);
					battery++;
				}
			}
		}
	}while(partFromList != 0);
		
	if(allModels[allModels.size()-1].getNumOfParts() == 0)
	{
		cout << "No Parts Chosen. Returning to Menu." <<endl;
		allModels.pop_back();
		return;
	}
	
	sum = 0;
	for(int i = 0; i < allModels[allModels.size()-1].getNumOfParts(); i++) 
	{
		//cout << "Name: " << allModels[allModels.size()-1].getPart(i)->getName();
		//cout << ", Cost : " << allModels[allModels.size()-1].getPart(i)->getCost() <<endl;
		sum += allModels[allModels.size()-1].getPart(i)->getCost();
	}
	cout << "Total Cost of Parts: " << sum <<endl<<endl;

	cout << "Please enter a Price for this Model: " <<endl;
	cin >> modelPrice;
	allModels[allModels.size()-1].setPrice(modelPrice);
	cout << "Please enter a Name for this Model: " <<endl;
	getline(cin, trash);
	getline(cin, modelName);
	allModels[allModels.size()-1].setName(modelName);
	cout << "Please enter a Model Number: " <<endl;
	cin >> modelNum;
	allModels[allModels.size()-1].setModelNum(modelNum);
}