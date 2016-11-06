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
//FLTK Include Files
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_ask.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Valuator.H>
#include <FL/Fl_Text_Buffer.H>

//Callback Functions
void ButtonCB(Fl_Widget*, void*);
void CloseCB(Fl_Widget*, void*);
void InputStringCB(Fl_Widget*, void*);
void AddPartCB(Fl_Widget*, void*);
void HeadCB(Fl_Widget*, void*);
void ArmCB(Fl_Widget*, void*);
void TorsoCB(Fl_Widget*, void*);
void MotorCB(Fl_Widget*, void*);
void BatteryCB(Fl_Widget*, void*);
void ReportPartsCB(Fl_Widget*, void*);

//Vectors
vector <RobotPart*> allParts;
vector <RobotModel> allModels;
vector <Order> allOrders;
vector <SalesAssoc> allSalesAssoc;
vector <Customer> allCustomers;
View view;

//GUI Widgets
Fl_Window *win;
Fl_Input *nameGUI;
Fl_Value_Input *partNumGUI;
Fl_Value_Input *partCostGUI;
Fl_Value_Input *partWeightGUI;
Fl_Multiline_Input *descriptionGUI;
Fl_Value_Input *maxSpeedGUI;
Fl_Value_Input *energyGUI;
Fl_Value_Input *maxPowerGUI;
Fl_Round_Button *headButton;
Fl_Round_Button *armButton;
Fl_Round_Button *torsoButton;
Fl_Round_Button *motorButton;
Fl_Round_Button *batteryButton;
Fl_Group *numBats;
Fl_Round_Button *bat1;
Fl_Round_Button *bat2;
Fl_Round_Button *bat3;
Fl_Tabs *tabs;
Fl_Text_Buffer *buffer;
Fl_Menu_Bar *menubar;
Fl_Menu_Item menuItems[] = {
							{"&File", 0, 0, 0, FL_SUBMENU},
								{"&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB},
								{0},
							{"&Create", 0, 0, 0, FL_SUBMENU},
								{"&Order", FL_ALT + 'o', (Fl_Callback *)InputStringCB, 0, FL_MENU_DIVIDER},
								{"Sales &Associate", FL_ALT + 'a', (Fl_Callback *)InputStringCB},
								{"&Customer", FL_ALT + 'c', (Fl_Callback *)InputStringCB, 0, FL_MENU_DIVIDER},
								{"Robot &Part", FL_ALT + 'p', (Fl_Callback *)AddPartCB},
								{"Robot &Model", FL_ALT + 'm', (Fl_Callback *)InputStringCB},
								{0},
							{"&Report", 0, 0, 0, FL_SUBMENU},
								{"&Orders", FL_CTRL + 'o', (Fl_Callback *)InputStringCB, 0, FL_MENU_DIVIDER},
								{"Sales &Associates", FL_CTRL + 'a', (Fl_Callback *)InputStringCB},
								{"&Customers", FL_CTRL + 'c', (Fl_Callback *)InputStringCB, 0, FL_MENU_DIVIDER},
								{"Robot &Parts", FL_CTRL + 'p', (Fl_Callback *)InputStringCB},
								{"Robot &Models", FL_CTRL + 'm', (Fl_Callback *)InputStringCB},
								{0}};


//Temporary variables for adding parts, models, customers, sales associates, and orders
int menu, partFromList, partNum, partPosBats, maxSP, modelNum, quan;
int num, head, motor, arm, torso, battery, maxBat, seller, cust;
string partName, partDesc, modelName, trash;
double partCost, partWeight, partEnergy, maxPow, modelPrice, sum, custNum;

//Constants
const int w = 500;
const int h = 500;

int main()
{
	

	win = new Fl_Window(w , h, "Robbie Robot Shop");
	
	
	tabs = new Fl_Tabs(0, 30, w, h-30);
	{
		Fl_Group *tab1 = new Fl_Group(0, 55, w, h-55,"Order");
		{
			Fl_Tabs *subTabs = new Fl_Tabs(0, 55, w, h-55);
			{
				Fl_Group *subTab1 = new Fl_Group(0, 80, w, h-80, "Create");
				{
					Fl_Button *button1;
					button1 = new Fl_Button(50,80,50,50,"Button1");
					button1->when(FL_WHEN_RELEASE);
					button1->callback(ButtonCB,"Button1");
				 	win->resizable(*button1);
				}
				subTab1->end();
				Fl_Group *subTab2 = new Fl_Group(0, 80, w, h-80, "Report");
				{

				}
				subTab2->end();
			}
			subTabs->end();
		}
		tab1->end();
		Fl_Group *tab2 = new Fl_Group(0, 55, w, h-55,"Customer");
		{
			Fl_Tabs *subTabs = new Fl_Tabs(0, 55, w, h-55);
			{
				Fl_Group *subTab1 = new Fl_Group(0, 80, w, h-80, "Create");
				{

				}
				subTab1->end();
				Fl_Group *subTab2 = new Fl_Group(0, 80, w, h-80, "Report");
				{
					Fl_Button *button2;
					button2 = new Fl_Button(0,80,50,50,"Button2");
					button2->when(FL_WHEN_RELEASE);
					button2->callback(InputStringCB);
					win->resizable(*button2);
				}
				subTab2->end();
			}
			subTabs->end();
		}
		tab2->end();
		Fl_Group *tab3 = new Fl_Group(0, 55, w, h-55,"Sales Assoc");
		{
			Fl_Tabs *subTabs = new Fl_Tabs(0, 55, w, h-55);
			{
				Fl_Group *subTab1 = new Fl_Group(0, 80, w, h-80, "Create");
				{

				}
				subTab1->end();
				Fl_Group *subTab2 = new Fl_Group(0, 80, w, h-80, "Report");
				{

				}
				subTab2->end();
			}
			subTabs->end();
		}
		tab3->end();
		Fl_Group *tab4 = new Fl_Group(0, 55, w, h-55,"Robot Model");
		{
			Fl_Tabs *subTabs = new Fl_Tabs(0, 55, w, h-55);
			{
				Fl_Group *subTab1 = new Fl_Group(0, 80, w, h-80, "Create");
				{

				}
				subTab1->end();
				Fl_Group *subTab2 = new Fl_Group(0, 80, w, h-80, "Report");
				{

				}
				subTab2->end();
			}
			subTabs->end();
		}
		tab4->end();
		Fl_Group *tab5 = new Fl_Group(0, 55, w, h-55,"Robot Part");
		{
			Fl_Tabs *subTabs = new Fl_Tabs(0, 55, w, h-55);
			{
				Fl_Group *subTab1 = new Fl_Group(0, 80, w, h-80, "Create");
				{
					Fl_Button *addPart = new Fl_Button(w-75,h-25,75,25,"Add Part");
					addPart->when(FL_WHEN_RELEASE);
					addPart->callback(AddPartCB);
					nameGUI = new Fl_Input(w-150,90,140,25,"Part Name:");
					partNumGUI = new Fl_Value_Input(w-100,120,90,25,"Part Number:");
					partCostGUI = new Fl_Value_Input(w-100,150,90,25,"Part Cost:");
					partWeightGUI = new Fl_Value_Input(w-100,180,90,25,"Part Weight:");
					descriptionGUI = new Fl_Multiline_Input(w-200,210,190,80,"Part Description:\n(Max.500)");
					maxSpeedGUI = new Fl_Value_Input(w-100,h-180,90,25,"Motor Speed MPH:");
					maxSpeedGUI->deactivate();
					energyGUI = new Fl_Value_Input(w-100,h-155,90,25,"Battery's Energy:");
					energyGUI->deactivate();
					maxPowerGUI = new Fl_Value_Input(w-100,h-130,90,25,"Battery's Max Power:");
					maxPowerGUI->deactivate();

					Fl_Group *radio = new Fl_Group(w-(w-15),100,50,h-100,"Part Type:");
					{
						headButton = new Fl_Round_Button(5,105,15,15,"Head");
						headButton->type(102);
						headButton->when(FL_WHEN_RELEASE);
						headButton->callback(HeadCB);
						headButton->setonly();
					
						armButton = new Fl_Round_Button(5,125,15,15,"Arm");
						armButton->type(102);
						armButton->when(FL_WHEN_RELEASE);
						armButton->callback(ArmCB);
					
						torsoButton = new Fl_Round_Button(5,145,15,15,"Torso");
						torsoButton->type(102);
						torsoButton->when(FL_WHEN_RELEASE);
						torsoButton->callback(TorsoCB);

						motorButton = new Fl_Round_Button(5,165,15,15,"Motor");
						motorButton->type(102);
						motorButton->when(FL_WHEN_RELEASE);
						motorButton->callback(MotorCB);

						batteryButton = new Fl_Round_Button(5,185,15,15,"Battery");
						batteryButton->type(102);
						batteryButton->when(FL_WHEN_RELEASE);
						batteryButton->callback(BatteryCB);
					}
					numBats = new Fl_Group(w-(w-15),h-150,50,150,"Max Number\nof Batteries:");
					{
						bat1 = new Fl_Round_Button(5,h-145,15,15,"1");
						bat1->type(102);
						bat1->when(FL_WHEN_RELEASE);
					
						bat2 = new Fl_Round_Button(5,h-125,15,15,"2");
						bat2->type(102);
						bat2->when(FL_WHEN_RELEASE);
					
						bat3 = new Fl_Round_Button(5,h-105,15,15,"3");
						bat3->type(102);
						bat3->when(FL_WHEN_RELEASE);
					}
					numBats->deactivate();
				}
				subTab1->end();
				Fl_Group *subTab2 = new Fl_Group(0, 80, w, h-80, "Report");
				{
					Fl_Button *update = new Fl_Button(0,h-25,75,25,"Update");
					update->when(FL_WHEN_RELEASE);
					update->callback(ReportPartsCB);
					Fl_Text_Display *report = new Fl_Text_Display(0, 85, w, h-110,"");
					buffer = new Fl_Text_Buffer();
					report->buffer(buffer);
				}
				subTab2->end();
			}
			subTabs->end();
		}
		tab4->end();
	}
	tabs->end();


	menubar = new Fl_Menu_Bar(0,0,w,30);
	menubar->menu(menuItems);



	


	win->callback(CloseCB);

	win->end();
	win->show();

	return Fl::run();
}

void CloseCB(Fl_Widget* w, void* p)
{
	if(fl_choice("Are you sure you want to quit?","Maybe?","No","Yes") == 2)
	{
		win->hide();
	}
}

void HeadCB(Fl_Widget* w, void* p)
{
	numBats->deactivate();
	maxSpeedGUI->deactivate();
	energyGUI->deactivate();
	maxPowerGUI->deactivate();
	win->redraw();
}
void ArmCB(Fl_Widget* w, void* p)
{
	numBats->deactivate();
	maxSpeedGUI->deactivate();
	energyGUI->deactivate();
	maxPowerGUI->deactivate();
	win->redraw();
}
void TorsoCB(Fl_Widget* w, void* p)
{
	numBats->activate();
	maxSpeedGUI->deactivate();
	energyGUI->deactivate();
	maxPowerGUI->deactivate();
	win->redraw();
}
void MotorCB(Fl_Widget* w, void* p)
{
	numBats->deactivate();
	maxSpeedGUI->activate();
	energyGUI->deactivate();
	maxPowerGUI->deactivate();
	win->redraw();
}
void BatteryCB(Fl_Widget* w, void* p)
{
	numBats->deactivate();
	maxSpeedGUI->deactivate();
	energyGUI->activate();
	maxPowerGUI->activate();
	win->redraw();
}

void ButtonCB(Fl_Widget* w, void* p)
{
	cout << (char*)p << " was pressed\n";
	view.printParts(allParts);
}

void InputStringCB(Fl_Widget* w, void* p)
{
	string real;
	
	void* name = (void*) fl_input("Please enter a Name","");

	if(name == NULL)
	{
		real = "";
	}
	else
	{
		real = (char*) name;
	}

	cout << "*"+real+"*\n";
}

void AddPartCB(Fl_Widget* w, void* p)
{

	if(headButton->value())
	{
		partName = nameGUI->value();
		if(partName == "")
		{
			fl_choice("ERROR Please enter a Name",0,0,"Okay");
			return;
		}
		
		partDesc = descriptionGUI->value();
		if(partDesc == "")
		{
			fl_choice("ERROR Please enter a Description",0,0,"Okay");
			return;
		}

		partNum = partNumGUI->value();

		partCost = partCostGUI->value();
		if(partCost == 0)
		{
			if(fl_choice("WARNING Part's Cost is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}

		partWeight = partWeightGUI->value();
		if(partWeight == 0)
		{
			if(fl_choice("WARNING Part's Weight is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}

		allParts.push_back(new Head(partName, partDesc, partNum, partCost, partWeight));

		nameGUI->replace(0,nameGUI->size(),"",0);
		descriptionGUI->replace(0,descriptionGUI->size(),"",0);
		win->redraw();

	}

	else if(armButton->value())
	{
		partName = nameGUI->value();
		if(partName == "")
		{
			fl_choice("ERROR Please enter a Name",0,0,"Okay");
			return;
		}

		partDesc = descriptionGUI->value();
		if(partDesc == "")
		{
			fl_choice("ERROR Please enter a Description",0,0,"Okay");
			return;
		}

		partNum = partNumGUI->value();

		partCost = partCostGUI->value();
		if(partCost == 0)
		{
			if(fl_choice("WARNING Part's Cost is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}

		partWeight = partWeightGUI->value();
		if(partWeight == 0)
		{
			if(fl_choice("WARNING Part's Weight is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}

		allParts.push_back(new Arm(partName, partDesc, partNum, partCost, partWeight));

		nameGUI->replace(0,nameGUI->size(),"",0);
		descriptionGUI->replace(0,descriptionGUI->size(),"",0);
		win->redraw();
	}

	else if(torsoButton->value())
	{
		partName = nameGUI->value();
		if(partName == "")
		{
			fl_choice("ERROR Please enter a Name",0,0,"Okay");
			return;
		}

		partDesc = descriptionGUI->value();
		if(partDesc == "")
		{
			fl_choice("ERROR Please enter a Description",0,0,"Okay");
			return;
		}
		partNum = partNumGUI->value();

		partCost = partCostGUI->value();
		if(partCost == 0)
		{
			if(fl_choice("WARNING Part's Cost is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}

		partWeight = partWeightGUI->value();
		if(partWeight == 0)
		{
			if(fl_choice("WARNING Part's Weight is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}

		if(bat1->value())
		{
			maxBat = 1;
		}
		else if(bat2->value())
		{
			maxBat = 2;
		}
		else if(bat3->value())
		{
			maxBat = 3;
		}
		else
		{
			fl_choice("ERROR Please select a Maximum Number of Batteries",0,0,"Okay");
			return;
		}

		allParts.push_back(new Torso(partName, partDesc, partNum, partCost, partWeight, maxBat));

		nameGUI->replace(0,nameGUI->size(),"",0);
		descriptionGUI->replace(0,descriptionGUI->size(),"",0);
		win->redraw();
	}

	else if(motorButton->value())
	{
		partName = nameGUI->value();
		if(partName == "")
		{
			fl_choice("ERROR Please enter a Name",0,0,"Okay");
			return;
		}

		partDesc = descriptionGUI->value();
		if(partDesc == "")
		{
			fl_choice("ERROR Please enter a Description",0,0,"Okay");
			return;
		}

		partNum = partNumGUI->value();

		partCost = partCostGUI->value();
		if(partCost == 0)
		{
			if(fl_choice("WARNING Part's Cost is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}

		partWeight = partWeightGUI->value();
		if(partWeight == 0)
		{
			if(fl_choice("WARNING Part's Weight is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}

		maxSP = maxSpeedGUI->value();
		if(maxSP == 0)
		{
			if(fl_choice("WARNING Motor's Max Speed is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}
		
		allParts.push_back(new Motor(partName, partDesc, partNum, partCost, partWeight, maxSP));

		nameGUI->replace(0,nameGUI->size(),"",0);
		descriptionGUI->replace(0,descriptionGUI->size(),"",0);
		win->redraw();
	}

	else if(batteryButton->value())
	{
		partName = nameGUI->value();
		if(partName == "")
		{
			fl_choice("ERROR Please enter a Name",0,0,"Okay");
			return;
		}

		partDesc = descriptionGUI->value();
		if(partDesc == "")
		{
			fl_choice("ERROR Please enter a Description",0,0,"Okay");
			return;
		}

		partNum = partNumGUI->value();

		partCost = partCostGUI->value();
		if(partCost == 0)
		{
			if(fl_choice("WARNING Part's Cost is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}

		partWeight = partWeightGUI->value();
		if(partWeight == 0)
		{
			if(fl_choice("WARNING Part's Weight is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}

		partEnergy = energyGUI->value();
		if(partEnergy == 0)
		{
			if(fl_choice("WARNING Battery's Energy is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}

		maxPow = maxPowerGUI->value();
		if(maxPow == 0)
		{
			if(fl_choice("WARNING Battery's Maximum Power is set to 0\nDo you wish to add the Part?",0,fl_no,fl_yes) == 1)
			{
				return;
			}
		}
		
		allParts.push_back(new Battery(partName, partDesc, partNum, partCost, partWeight, partEnergy, maxPow));

		nameGUI->replace(0,nameGUI->size(),"",0);
		descriptionGUI->replace(0,descriptionGUI->size(),"",0);
		win->redraw();
	}
}

void ReportPartsCB(Fl_Widget*, void*)
{
	char text[500];
	buffer->text("");
	buffer->append("***List of All Current Parts***\n");
	for(int i = 0; i < allParts.size(); i++)
	{
		sprintf_s(text,sizeof(text),"%d.",i+1);
		buffer->append(text);
		buffer->append("\tPart Number: ");
		sprintf_s(text,sizeof(text),"%d\n",allParts[i]->getPartNum());
		buffer->append(text);
		buffer->append("\tName: ");
		sprintf_s(text,sizeof(text),"%s\n",allParts[i]->getName().c_str());
		buffer->append(text);
		buffer->append("\tCost: ");
		sprintf_s(text,sizeof(text),"%.2f\n",allParts[i]->getCost());
		buffer->append(text);
		buffer->append("\tWeight: ");
		sprintf_s(text,sizeof(text),"%.2f\n",allParts[i]->getWeight());
		buffer->append(text);
		buffer->append("\tType: ");
		sprintf_s(text,sizeof(text),"%s\n",allParts[i]->getPartType().c_str());
		buffer->append(text);
		if(allParts[i]->getPartType() == "Motor")
		{
			buffer->append("\tMax Speed: ");
			sprintf_s(text,sizeof(text),"%d\n",allParts[i]->getMaxSpeed());
			buffer->append(text);
		}
		else if(allParts[i]->getPartType() == "Battery")
		{
			buffer->append("\tEnergy: ");
			sprintf_s(text,sizeof(text),"%f\n",allParts[i]->getEnergy());
			buffer->append(text);
			buffer->append("\tMax Power: ");
			sprintf_s(text,sizeof(text),"%f\n",allParts[i]->getPower());
			buffer->append(text);
		}
		else if(allParts[i]->getPartType() == "Torso")
		{
			buffer->append("\tPossible Batteries: ");
			sprintf_s(text,sizeof(text),"%d\n",allParts[i]->getPossibleBatteries());
			buffer->append(text);
		}
		buffer->append("\tDescription: ");
		sprintf_s(text,sizeof(text),"%s\n\n",allParts[i]->getDescription().c_str());
		buffer->append(text);
	}
}