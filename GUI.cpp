//Made by Tyler Gustaf
#include "std_lib_facilities.h"
#include "RobotModel.h"
#include "RobotPart.h"
#include <vector>
#include "View.h"
//#include "Controller.h"
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
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Valuator.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Box.H>

//Callback Functions
void CloseCB(Fl_Widget*, void*);
void AddPartCB(Fl_Widget*, void*);
void HeadCB(Fl_Widget*, void*);
void ArmCB(Fl_Widget*, void*);
void TorsoCB(Fl_Widget*, void*);
void MotorCB(Fl_Widget*, void*);
void BatteryCB(Fl_Widget*, void*);
void PartToModelCB(Fl_Widget*, void*);
void FinishCB(Fl_Widget*, void*);
void AddModelCB(Fl_Widget*, void*);
void ReportPartsCB(Fl_Widget*, void*);
void ReportModelsCB(Fl_Widget*, void*);
void CheckPartsCB(Fl_Widget*, void*);
void AddCustomerCB(Fl_Widget*, void*);
void ReportCustomersCB(Fl_Widget*, void*);
void AddSACB(Fl_Widget*, void*);
void ReportSACB(Fl_Widget*, void*);
void AddOrderCB(Fl_Widget*, void*);
void ReportOrdersCB(Fl_Widget*, void*);

//Vectors
vector <RobotPart*> allParts;
vector <RobotModel> allModels;
vector <Order> allOrders;
vector <SalesAssoc> allSalesAssoc;
vector <Customer> allCustomers;
View view;

//GUI Widgets
Fl_JPEG_Image *jImage;
Fl_PNG_Image *pImage;
Fl_Shared_Image *sharedImage;
Fl_Box *box;
Fl_Window *win;
Fl_Input *nameGUI;
Fl_Input *modelNameGUI;
Fl_Input *modelPicGUI;
Fl_Input *custNameGUI;
Fl_Input *custPhoneGUI;
Fl_Input *custEmailGUI;
Fl_Input *saNameGUI;
Fl_Value_Input *saNumGUI;
Fl_Value_Input *custNumGUI;
Fl_Value_Input *custWalletGUI;
Fl_Value_Input *partNumGUI;
Fl_Value_Input *partCostGUI;
Fl_Value_Input *partWeightGUI;
Fl_Multiline_Input *descriptionGUI;
Fl_Value_Input *maxSpeedGUI;
Fl_Value_Input *energyGUI;
Fl_Value_Input *maxPowerGUI;
Fl_Value_Input *partIndexGUI;
Fl_Value_Input *modelNumGUI;
Fl_Value_Output *modelCostGUI;
Fl_Value_Input *modelPriceGUI;
Fl_Value_Input *checkPartGUI;
Fl_Value_Input *orderModelGUI;
Fl_Value_Input *orderSAGUI;
Fl_Value_Input *orderCustGUI;
Fl_Value_Input *orderNumGUI;
Fl_Value_Input *orderQuanGUI;
Fl_Round_Button *headButton;
Fl_Round_Button *armButton;
Fl_Round_Button *torsoButton;
Fl_Round_Button *motorButton;
Fl_Round_Button *batteryButton;
Fl_Round_Button *JPEGButton;
Fl_Round_Button *PNGButton;
Fl_Button *addModel;
Fl_Button *addPartToModel;
Fl_Button *finish;
Fl_Group *numBats;
Fl_Round_Button *bat1;
Fl_Round_Button *bat2;
Fl_Round_Button *bat3;
Fl_Tabs *tabs;
Fl_Text_Display *reportModels;
Fl_Text_Display *reportModels2;
Fl_Text_Buffer *partsBuffer = new Fl_Text_Buffer();
Fl_Text_Buffer *modelsBuffer = new Fl_Text_Buffer();
Fl_Text_Buffer *custBuffer = new Fl_Text_Buffer();
Fl_Text_Buffer *saBuffer = new Fl_Text_Buffer();
Fl_Text_Buffer *ordersBuffer = new Fl_Text_Buffer();


//Temporary variables for adding parts, models, customers, sales associates, and orders
int menu, partFromList, partNum, partPosBats, maxSP, modelNum, quan, currentlyWorking = 0;
int num, head = 0, motor = 0, arm = 0, torso = 0, battery = 0, maxBat = 3, seller, cust;
string partName, partDesc, modelName, trash, name, phone, email, image;
double partCost, partWeight, partEnergy, maxPow, modelPrice, sum, custNum, wallet;

//Constants
const int w = 500;
const int h = 500;

int main()
{
	
	fl_register_images();
	win = new Fl_Window(w , h, "Robbie Robot Shop");
	
	
	tabs = new Fl_Tabs(0, 0, w, h);
	{
		Fl_Group *tab1 = new Fl_Group(0, 25, w, h-25,"Order");
		{
			Fl_Tabs *subTabs = new Fl_Tabs(0, 25, w, h-25);
			{
				Fl_Group *subTab1 = new Fl_Group(0, 50, w, h-50, "Create");
				{
					Fl_Button *updateModels = new Fl_Button((w/2)-75,55+(h/3),75,25,"Update");
					updateModels->when(FL_WHEN_RELEASE);
					updateModels->callback(ReportModelsCB);
					orderModelGUI = new Fl_Value_Input((w/2)-115,55+(h/3),40,25,"Model Index:");
					Fl_Text_Display *reportModels = new Fl_Text_Display(0, 55, w/2, h/3,"");
					reportModels->buffer(modelsBuffer);

					Fl_Button *updateSA = new Fl_Button((w/2)-75,90+(2*h/3),75,25,"Update");
					updateSA->when(FL_WHEN_RELEASE);
					updateSA->callback(ReportSACB);
					orderSAGUI = new Fl_Value_Input((w/2)-115,90+(2*h/3),40,25,"SalesAssoc Index:");
					Fl_Text_Display *reportSA = new Fl_Text_Display(0, 90+(h/3), w/2, h/3,"");
					reportSA->buffer(saBuffer);

					Fl_Button *updateCust = new Fl_Button(w-75,55+(h/3),75,25,"Update");
					updateCust->when(FL_WHEN_RELEASE);
					updateCust->callback(ReportCustomersCB);
					orderCustGUI = new Fl_Value_Input(w-115,55+(h/3),40,25,"Customer Index:");
					Fl_Text_Display *reportCust = new Fl_Text_Display(w/2, 55, w/2, h/3,"");
					reportCust->buffer(custBuffer);

					win->resizable(*updateCust);
					win->resizable(*updateSA);

					orderNumGUI = new Fl_Value_Input(w-(w/4),h-(h/4),40,25,"Order Number:");
					orderQuanGUI = new Fl_Value_Input(w-(w/4),h-(h/4)+25,40,25,"Quantity:");
					Fl_Button *addOrder = new Fl_Button(w-100,h-25,100,25,"Add Order");
					addOrder->when(FL_WHEN_RELEASE);
					addOrder->callback(AddOrderCB);
				}
				subTab1->end();
				Fl_Group *subTab2 = new Fl_Group(0, 50, w, h-50, "Report");
				{
					Fl_Button *updateOrders = new Fl_Button(0,h-25,75,25,"Update");
					updateOrders->when(FL_WHEN_RELEASE);
					updateOrders->callback(ReportOrdersCB);
					Fl_Text_Display *reportOrders = new Fl_Text_Display(0, 55, w, h-80,"");
					reportOrders->buffer(ordersBuffer);
				}
				subTab2->end();
			}
			subTabs->end();
		}
		tab1->end();
		Fl_Group *tab2 = new Fl_Group(0, 25, w, h-25,"Customer");
		{
			Fl_Tabs *subTabs = new Fl_Tabs(0, 25, w, h-25);
			{
				Fl_Group *subTab1 = new Fl_Group(0, 50, w, h-50, "Create");
				{
					custNameGUI = new Fl_Input(w/2,(h/2)-50,180,25,"Customer's Name");
					custPhoneGUI = new Fl_Input(w/2,(h/2)-25,180,25,"Customer's Phone #:");
					custEmailGUI = new Fl_Input(w/2,h/2,180,25,"Customer's Email:");
					custNumGUI = new Fl_Value_Input(w/2,(h/2)+25,90,25,"Customer Number:");
					custWalletGUI = new Fl_Value_Input(w/2,(h/2)+50,90,25,"Money in Customer's Wallet:");
					Fl_Button *addCust = new Fl_Button(w-100,h-25,100,25,"Add Customer");
					addCust->when(FL_WHEN_RELEASE);
					addCust->callback(AddCustomerCB);

				}
				subTab1->end();
				Fl_Group *subTab2 = new Fl_Group(0, 80, w, h-80, "Report");
				{
					Fl_Button *updateCustomers = new Fl_Button(0,h-25,75,25,"Update");
					updateCustomers->when(FL_WHEN_RELEASE);
					updateCustomers->callback(ReportCustomersCB);
					Fl_Text_Display *reportCustomers = new Fl_Text_Display(0, 55, w, h-80,"");
					reportCustomers->buffer(custBuffer);
				}
				subTab2->end();
			}
			subTabs->end();
		}
		tab2->end();
		Fl_Group *tab3 = new Fl_Group(0, 25, w, h-25,"Sales Assoc");
		{
			Fl_Tabs *subTabs = new Fl_Tabs(0, 25, w, h-25);
			{
				Fl_Group *subTab1 = new Fl_Group(0, 50, w, h-50, "Create");
				{
					saNameGUI = new Fl_Input(w/2,h/2,180,25,"Sales Associate's Name:");
					saNumGUI = new Fl_Value_Input(w/2,(h/2)+25,90,25,"Employee Number:");
					Fl_Button *addSA = new Fl_Button(w-135,h-25,135,25,"Add Sales Associate");
					addSA->when(FL_WHEN_RELEASE);
					addSA->callback(AddSACB);
				}
				subTab1->end();
				Fl_Group *subTab2 = new Fl_Group(0, 50, w, h-50, "Report");
				{
					Fl_Button *updateSA = new Fl_Button(0,h-25,75,25,"Update");
					updateSA->when(FL_WHEN_RELEASE);
					updateSA->callback(ReportSACB);
					Fl_Text_Display *reportSA = new Fl_Text_Display(0, 55, w, h-80,"");
					reportSA->buffer(saBuffer);

				}
				subTab2->end();
			}
			subTabs->end();
		}
		tab3->end();
		Fl_Group *tab4 = new Fl_Group(0, 25, w, h-25,"Robot Model");
		{
			Fl_Tabs *subTabs = new Fl_Tabs(0, 25, w, h-25);
			{
				Fl_Group *subTab1 = new Fl_Group(0, 50, w, h-50, "Create");
				{
					Fl_Button *update = new Fl_Button((w/2)-75,85+(h-150),75,25,"Update");
					update->when(FL_WHEN_RELEASE);
					update->callback(ReportPartsCB);
					Fl_Text_Display *report = new Fl_Text_Display(0, 55, w/2, h-120,"");
					report->buffer(partsBuffer);
					addPartToModel = new Fl_Button(95,110+(h-150),75,40,"Add Part\nTo Model");
					addPartToModel->when(FL_WHEN_RELEASE);
					addPartToModel->callback(PartToModelCB);
					finish = new Fl_Button((w/2)-75,110+(h-150),75,25,"Finish");
					finish->when(FL_WHEN_RELEASE);
					finish->callback(FinishCB);
					partIndexGUI = new Fl_Value_Input(80,85+(h-150),90,25,"List Number\nof Part:");
					modelNameGUI = new Fl_Input(w-150,60,140,25,"Model Name:");
					modelNumGUI = new Fl_Value_Input(w-100,90,90,25,"Model Number:");
					modelPriceGUI = new Fl_Value_Input(w-100,120,90,25,"Model Price:");
					modelCostGUI = new Fl_Value_Output(w-100,150,90,25,"Model's Cost:");
					modelPicGUI = new Fl_Input(w-150,180,140,25,"Model Picture:");
					addModel = new Fl_Button(w-75,h-25,75,25,"Add Model");
					addModel->when(FL_WHEN_RELEASE);
					addModel->callback(AddModelCB);
					Fl_Group *radio = new Fl_Group(w-150,190,w-(w-150),240,"");
					{
						JPEGButton = new Fl_Round_Button(w-150,210,15,15,"JPEG");
						JPEGButton->type(102);
						JPEGButton->setonly();
						PNGButton = new Fl_Round_Button(w-90,210,15,15,"PNG");
						PNGButton->type(102);
					}
					addModel->deactivate();
					modelNameGUI->deactivate();
					modelNumGUI->deactivate();
					modelPriceGUI->deactivate();
					modelCostGUI->deactivate();
					JPEGButton->deactivate();
					PNGButton->deactivate();
					modelPicGUI->deactivate();

				}
				subTab1->end();
				Fl_Group *subTab2 = new Fl_Group(0, 50, w, h-50, "Report");
				{
					Fl_Button *updateModels = new Fl_Button(0,h-25,75,25,"Update");
					updateModels->when(FL_WHEN_RELEASE);
					updateModels->callback(ReportModelsCB);
					Fl_Button *back = new Fl_Button(w-210,h-25,75,25,"Back");
					back->when(FL_WHEN_RELEASE);
					back->callback(ReportModelsCB);
					Fl_Button *checkParts = new Fl_Button(w-85,h-25,85,25,"Check Parts");
					checkParts->when(FL_WHEN_RELEASE);
					checkParts->callback(CheckPartsCB);
					reportModels = new Fl_Text_Display(0, 55, w, h-80,"");
					reportModels->buffer(modelsBuffer);
					reportModels2 = new Fl_Text_Display(0, 55, w/2, h-80,"");
					reportModels2->buffer(modelsBuffer);
					reportModels2->hide();
					checkPartGUI = new Fl_Value_Input(w-135,h-25,50,25,"");
					box = new Fl_Box(w/2, 55, w/2, h-55, "");
					box->hide();
				}
				subTab2->end();
			}
			subTabs->end();
		}
		tab4->end();
		Fl_Group *tab5 = new Fl_Group(0, 25, w, h-25,"Robot Part");
		{
			Fl_Tabs *subTabs = new Fl_Tabs(0, 25, w, h-25);
			{
				Fl_Group *subTab1 = new Fl_Group(0, 50, w, h-50, "Create");
				{
					Fl_Button *addPart = new Fl_Button(w-75,h-25,75,25,"Add Part");
					addPart->when(FL_WHEN_RELEASE);
					addPart->callback(AddPartCB);
					nameGUI = new Fl_Input(w-150,60,140,25,"Part Name:");
					partNumGUI = new Fl_Value_Input(w-100,90,90,25,"Part Number:");
					partCostGUI = new Fl_Value_Input(w-100,120,90,25,"Part Cost:");
					partWeightGUI = new Fl_Value_Input(w-100,150,90,25,"Part Weight:");
					descriptionGUI = new Fl_Multiline_Input(w-200,180,190,80,"Part Description:\n(Max.500)");
					maxSpeedGUI = new Fl_Value_Input(w-100,h-2100,90,25,"Motor Speed MPH:");
					maxSpeedGUI->deactivate();
					energyGUI = new Fl_Value_Input(w-100,h-185,90,25,"Battery's Energy:");
					energyGUI->deactivate();
					maxPowerGUI = new Fl_Value_Input(w-100,h-160,90,25,"Battery's Max Power:");
					maxPowerGUI->deactivate();

					Fl_Group *radio = new Fl_Group(w-(w-15),70,50,h-70,"Part Type:");
					{
						headButton = new Fl_Round_Button(5,75,15,15,"Head");
						headButton->type(102);
						headButton->when(FL_WHEN_RELEASE);
						headButton->callback(HeadCB);
						headButton->setonly();
					
						armButton = new Fl_Round_Button(5,95,15,15,"Arm");
						armButton->type(102);
						armButton->when(FL_WHEN_RELEASE);
						armButton->callback(ArmCB);
					
						torsoButton = new Fl_Round_Button(5,115,15,15,"Torso");
						torsoButton->type(102);
						torsoButton->when(FL_WHEN_RELEASE);
						torsoButton->callback(TorsoCB);

						motorButton = new Fl_Round_Button(5,135,15,15,"Motor");
						motorButton->type(102);
						motorButton->when(FL_WHEN_RELEASE);
						motorButton->callback(MotorCB);

						batteryButton = new Fl_Round_Button(5,155,15,15,"Battery");
						batteryButton->type(102);
						batteryButton->when(FL_WHEN_RELEASE);
						batteryButton->callback(BatteryCB);
					}
					numBats = new Fl_Group(w-(w-15),h-180,50,150,"Max Number\nof Batteries:");
					{
						bat1 = new Fl_Round_Button(5,h-175,15,15,"1");
						bat1->type(102);
						bat1->when(FL_WHEN_RELEASE);
					
						bat2 = new Fl_Round_Button(5,h-155,15,15,"2");
						bat2->type(102);
						bat2->when(FL_WHEN_RELEASE);
					
						bat3 = new Fl_Round_Button(5,h-135,15,15,"3");
						bat3->type(102);
						bat3->when(FL_WHEN_RELEASE);
						bat3->setonly();
					}
					numBats->deactivate();
				}
				subTab1->end();
				Fl_Group *subTab2 = new Fl_Group(0, 50, w, h-50, "Report");
				{
					Fl_Button *updateParts = new Fl_Button(0,h-25,75,25,"Update");
					updateParts->when(FL_WHEN_RELEASE);
					updateParts->callback(ReportPartsCB);
					Fl_Text_Display *reportParts = new Fl_Text_Display(0, 55, w, h-80,"");
					reportParts->buffer(partsBuffer);
				}
				subTab2->end();
			}
			subTabs->end();
		}
		tab5->end();
		Fl_Group *tab6 = new Fl_Group(0, 25, w, h-25,"Help");
		{
			Fl_Text_Display *help = new Fl_Text_Display(0, 25, w, h-25,"");
			Fl_Text_Buffer *helpBuffer = new Fl_Text_Buffer();
			help->buffer(helpBuffer);
			helpBuffer->text("");
			helpBuffer->append("\tWelcome to Robbie Robot Shop!\n\n");
			helpBuffer->append("Main Tabs:\n");
			helpBuffer->append("Along the top of the application window you will the main tabs.\n");
			helpBuffer->append("These represent each category of information that can be of interest to you.\n");
			helpBuffer->append("Therefore, if you wish to add a Robot Part click the “Robot Part” tab.\n\n");
			helpBuffer->append("Sub Tabs:\n");
			helpBuffer->append("There are two sub tabs for each main section of information, Create and Report.\n");
			helpBuffer->append("Each sub tab can be accessed once the main tab has been selected.\n");
			helpBuffer->append("Therefore, if you wish to report the Robot Models first click the “Robot Model” tab then click the “Report” sub tab.\n\n");
			helpBuffer->append("Creating:\n");
			helpBuffer->append("When creating any type of information, in the bottom right of the window will be the Add button which will add the entered data into the system.\n");
			helpBuffer->append("Be sure to fill out every entry field on that type’s “Create” sub tab before clicking its “Add” button.\n");
			helpBuffer->append("If some information has not been entered when the “Add” button is clicked a pop-up window will appear either telling you to enter the data or ask you if you would like to proceed with the data set to zero.\n\n");
			helpBuffer->append("Updating Lists:\n");
			helpBuffer->append("When you see a list window, click the “Update” button to update the list with the latest information of that type.\n\n");
			helpBuffer->append("Choosing from a List:\n");
			helpBuffer->append("When choosing an item from a list, such as a Robot Part to add into a Model, enter the item’s list number into the associated entry field as opposed to something like that Part’s Part Number.\n\n");
			helpBuffer->append("Robot Model Finish Button:\n");
			helpBuffer->append("When creating a Robot Model in the “Robot Model” tab “Create” sub tab,\nselect the Robot Parts you want to be in the model, one at a time, from the list on the left side of the window.\nWhen you are done adding Parts to the Model, click the “Finish” button.\nThis will not allow you to add any more Parts to the Model but will allow you to set the Model’s name, number, price, and picture.\nYou will not be able to start adding any other Models until the “Add Model” button is click with valid information in the entry fields.\n\n");
			helpBuffer->append("Reporting:\n");
			helpBuffer->append("If you wish to see all the information of a given type that is in the system,\nselect that type’s Main Tab then click the “Report” sub tab. It may be necessary to click the “Update” button to see the most recent list of information.\n");
		}
		tab6->end();
	}
	tabs->end();

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
		partNumGUI->value(0);
		partCostGUI->value(0);
		partWeightGUI->value(0);

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
		partNumGUI->value(0);
		partCostGUI->value(0);
		partWeightGUI->value(0);
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
			partPosBats = 1;
		}
		else if(bat2->value())
		{
			partPosBats = 2;
		}
		else if(bat3->value())
		{
			partPosBats = 3;
		}
		else
		{
			fl_choice("ERROR Please select a Maximum Number of Batteries",0,0,"Okay");
			return;
		}

		allParts.push_back(new Torso(partName, partDesc, partNum, partCost, partWeight, partPosBats));

		nameGUI->replace(0,nameGUI->size(),"",0);
		descriptionGUI->replace(0,descriptionGUI->size(),"",0);
		partNumGUI->value(0);
		partCostGUI->value(0);
		partWeightGUI->value(0);
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
		partNumGUI->value(0);
		partCostGUI->value(0);
		partWeightGUI->value(0);
		maxSpeedGUI->value(0);
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
		partNumGUI->value(0);
		partCostGUI->value(0);
		partWeightGUI->value(0);
		maxPowerGUI->value(0);
		energyGUI->value(0);
		
	}
}

void PartToModelCB(Fl_Widget*, void*)
{
	if(currentlyWorking == 0)
	{
		allModels.push_back(RobotModel());
		currentlyWorking = 1;
	}

	if(partIndexGUI->value() >= 1 && partIndexGUI->value() <= allParts.size())
	{
		if(allParts[partIndexGUI->value()-1]->getPartType() == "Head")
		{
			if(head > 0)
			{
				fl_choice("ERROR You already have a Part of this Type",0,0,"Okay");
			}
			else
			{
				allModels[allModels.size()-1].addPart(allParts[partIndexGUI->value()-1]);
				head++;
			}
		}
		else if(allParts[partIndexGUI->value()-1]->getPartType() == "Arm")
		{
			if(arm > 1)
			{
				fl_choice("ERROR You already have a Part of this Type",0,0,"Okay");
			}
			else
			{
				allModels[allModels.size()-1].addPart(allParts[partIndexGUI->value()-1]);
				arm++;
			}

		}
		else if(allParts[partIndexGUI->value()-1]->getPartType() == "Torso")
		{
			if(torso > 0)
			{
				fl_choice("ERROR You already have a Part of this Type",0,0,"Okay");
			}
			else
			{
				if(battery > allParts[partIndexGUI->value()-1]->getPossibleBatteries())
				{
					fl_choice("ERROR You have too may Batteries for this Torso",0,0,"Okay");
				}
				else
				{
					allModels[allModels.size()-1].addPart(allParts[partIndexGUI->value()-1]);
					torso++;
					maxBat = allParts[partIndexGUI->value()-1]->getPossibleBatteries();
				}
			}
		}
		else if(allParts[partIndexGUI->value()-1]->getPartType() == "Motor")
		{
			if(motor > 0)
			{
				fl_choice("ERROR You already have a Part of this Type",0,0,"Okay");
			}
			else
			{
				allModels[allModels.size()-1].addPart(allParts[partIndexGUI->value()-1]);
				motor++;
			}
		}
		else if(allParts[partIndexGUI->value()-1]->getPartType() == "Battery")
		{
			if(battery >= maxBat)
			{
				fl_choice("ERROR You already have enough Parts of this Type",0,0,"Okay");
			}
			else
			{
				allModels[allModels.size()-1].addPart(allParts[partIndexGUI->value()-1]);
				battery++;
			}
		}
	}
	else
	{
		fl_choice("ERROR No such List Number",0,0,"Okay");
	}
		
	if(allModels[allModels.size()-1].getNumOfParts() == 0)
	{
		allModels.pop_back();
		currentlyWorking = 0;
	}
	partIndexGUI->value(0);
}

void FinishCB(Fl_Widget*, void*)
{
	static int prevNumOfModels = 0;

	if(allModels.size() > prevNumOfModels)
	{
		if(fl_choice("WARNING You will not be able to add any more Parts to this Model\nDo you wish to Continue?",0,fl_no,fl_yes) == 2)
		{
			partIndexGUI->deactivate();
			addPartToModel->deactivate();
			finish->deactivate();
			addModel->activate();
			modelNameGUI->activate();
			modelNumGUI->activate();
			modelPriceGUI->activate();
			modelCostGUI->activate();
			JPEGButton->activate();
			PNGButton->activate();
			modelPicGUI->activate();

			int sum = 0;
			for(int i = 0; i < allModels[allModels.size() - 1].getNumOfParts(); i++)
			{
				sum += allModels[allModels.size()-1].getPart(i)->getCost();
			}

			modelCostGUI->value(sum);

			prevNumOfModels++;
			head = 0;
			arm = 0;
			torso = 0;
			battery = 0;
			motor = 0;
			maxBat = 3;
			currentlyWorking = 0;
		}
	}
	else
	{
		fl_choice("ERROR You must add at least 1 Part to the Model before Continuing",0,0,"Okay");
	}

}

void AddModelCB(Fl_Widget*, void*)
{
	modelName = modelNameGUI->value();
	modelPrice = modelPriceGUI->value();
	modelNum = modelNumGUI->value();
	image = modelPicGUI->value();
	if(modelName == "")
	{
		fl_choice("ERROR Please enter a Model Name",0,0,"Okay");
		return;
	}
	if(image == "")
	{
		fl_choice("ERROR Please enter a path to a Picture",0,0,"Okay");
		return;
	}
	if(modelPrice == 0)
	{
		if(fl_choice("WARNING Model's Price is set to 0\nDo you wish to Continue?",0,fl_no,fl_yes) != 2)
		{
			return;
		}
	}

	allModels[allModels.size()-1].setName(modelName);
	allModels[allModels.size()-1].setPrice(modelPrice);
	allModels[allModels.size()-1].setModelNum(modelNum);
	allModels[allModels.size()-1].setImage(image);
	if(JPEGButton->value())
	{
		allModels[allModels.size()-1].setPicJPEG(1);
	}
	else
	{
		allModels[allModels.size()-1].setPicJPEG(0);
	}

	modelNameGUI->replace(0,modelNameGUI->size(),"",0);
	modelPicGUI->replace(0,modelNameGUI->size(),"",0);
	modelPriceGUI->value(0);
	modelCostGUI->value(0);
	modelNumGUI->value(0);

	partIndexGUI->activate();
	addPartToModel->activate();
	finish->activate();
	addModel->deactivate();
	modelNameGUI->deactivate();
	modelNumGUI->deactivate();
	modelPriceGUI->deactivate();
	modelCostGUI->deactivate();
	JPEGButton->deactivate();
	PNGButton->deactivate();
	modelPicGUI->deactivate();
}

void ReportPartsCB(Fl_Widget*, void*)
{
	char text[500];
	partsBuffer->text("");
	partsBuffer->append("***List of All Current Parts***\n");
	for(int i = 0; i < allParts.size(); i++)
	{
		sprintf_s(text,sizeof(text),"%d.",i+1);
		partsBuffer->append(text);
		partsBuffer->append("\tPart Number: ");
		sprintf_s(text,sizeof(text),"%d\n",allParts[i]->getPartNum());
		partsBuffer->append(text);
		partsBuffer->append("\tName: ");
		sprintf_s(text,sizeof(text),"%s\n",allParts[i]->getName().c_str());
		partsBuffer->append(text);
		partsBuffer->append("\tCost: ");
		sprintf_s(text,sizeof(text),"%.2f\n",allParts[i]->getCost());
		partsBuffer->append(text);
		partsBuffer->append("\tWeight: ");
		sprintf_s(text,sizeof(text),"%.2f\n",allParts[i]->getWeight());
		partsBuffer->append(text);
		partsBuffer->append("\tType: ");
		sprintf_s(text,sizeof(text),"%s\n",allParts[i]->getPartType().c_str());
		partsBuffer->append(text);
		if(allParts[i]->getPartType() == "Motor")
		{
			partsBuffer->append("\tMax Speed: ");
			sprintf_s(text,sizeof(text),"%d\n",allParts[i]->getMaxSpeed());
			partsBuffer->append(text);
		}
		else if(allParts[i]->getPartType() == "Battery")
		{
			partsBuffer->append("\tEnergy: ");
			sprintf_s(text,sizeof(text),"%.2f\n",allParts[i]->getEnergy());
			partsBuffer->append(text);
			partsBuffer->append("\tMax Power: ");
			sprintf_s(text,sizeof(text),"%.2f\n",allParts[i]->getPower());
			partsBuffer->append(text);
		}
		else if(allParts[i]->getPartType() == "Torso")
		{
			partsBuffer->append("\tPossible Batteries: ");
			sprintf_s(text,sizeof(text),"%d\n",allParts[i]->getPossibleBatteries());
			partsBuffer->append(text);
		}
		partsBuffer->append("\tDescription: ");
		sprintf_s(text,sizeof(text),"%s\n\n",allParts[i]->getDescription().c_str());
		partsBuffer->append(text);
	}
}

void ReportModelsCB(Fl_Widget*, void*)
{
	reportModels->show();
	reportModels2->hide();
	box->hide();
	char text[500];
	modelsBuffer->text("");
	modelsBuffer->append("***List of All Current Models***\n");
	for(int i = 0; i < allModels.size(); i++)
	{
		sprintf_s(text,sizeof(text),"%d.",i+1);
		modelsBuffer->append(text);
		modelsBuffer->append("\tModel Number: ");
		sprintf_s(text,sizeof(text),"%d\n",allModels[i].getModelNum());
		modelsBuffer->append(text);
		modelsBuffer->append("\tName: ");
		sprintf_s(text,sizeof(text),"%s\n",allModels[i].getName().c_str());
		modelsBuffer->append(text);
		modelsBuffer->append("\tPrice: ");
		sprintf_s(text,sizeof(text),"%.2f\n\n",allModels[i].getPrice());
		modelsBuffer->append(text);
	}
	checkPartGUI->activate();
}

void CheckPartsCB(Fl_Widget* widget, void* p)
{
	if(checkPartGUI->value() <= 0 || checkPartGUI->value() > allModels.size())
	{
		fl_choice("ERROR No such List Number",0,0,"Okay");
		return;
	}
	reportModels->hide();
	reportModels2->show();
	if(allModels[checkPartGUI->value()-1].isJPEG())
	{
		jImage = new Fl_JPEG_Image(allModels[checkPartGUI->value()-1].getImage().c_str());
		Fl_Image *scaled = jImage->copy(w/2,w/2);
		box->image(scaled);
	}
	else
	{
		pImage = new Fl_PNG_Image(allModels[checkPartGUI->value()-1].getImage().c_str());
		Fl_Image *scaled = pImage->copy(w/2,h-110);
		box->image(pImage);
	}
	box->show();
	win->redraw();
	char text[500];
	modelsBuffer->text("");
	modelsBuffer->append("***List of All Model's Parts***\n");
	for(int i = 0; i < allModels[checkPartGUI->value()-1].getNumOfParts(); i++)
	{
		sprintf_s(text,sizeof(text),"%d.",i+1);
		modelsBuffer->append(text);
		modelsBuffer->append("\tPart Number: ");
		sprintf_s(text,sizeof(text),"%d\n",allModels[checkPartGUI->value()-1].getPart(i)->getPartNum());
		modelsBuffer->append(text);
		modelsBuffer->append("\tName: ");
		sprintf_s(text,sizeof(text),"%s\n",allModels[checkPartGUI->value()-1].getPart(i)->getName().c_str());
		modelsBuffer->append(text);
		modelsBuffer->append("\tCost: ");
		sprintf_s(text,sizeof(text),"%.2f\n",allModels[checkPartGUI->value()-1].getPart(i)->getCost());
		modelsBuffer->append(text);
		modelsBuffer->append("\tWeight: ");
		sprintf_s(text,sizeof(text),"%.2f\n",allModels[checkPartGUI->value()-1].getPart(i)->getWeight());
		modelsBuffer->append(text);
		modelsBuffer->append("\tType: ");
		sprintf_s(text,sizeof(text),"%s\n",allModels[checkPartGUI->value()-1].getPart(i)->getPartType().c_str());
		modelsBuffer->append(text);
		if(allModels[checkPartGUI->value()-1].getPart(i)->getPartType() == "Motor")
		{
			modelsBuffer->append("\tMax Speed: ");
			sprintf_s(text,sizeof(text),"%d\n",allModels[checkPartGUI->value()-1].getPart(i)->getMaxSpeed());
			modelsBuffer->append(text);
		}
		else if(allModels[checkPartGUI->value()-1].getPart(i)->getPartType() == "Battery")
		{
			modelsBuffer->append("\tEnergy: ");
			sprintf_s(text,sizeof(text),"%.2f\n",allModels[checkPartGUI->value()-1].getPart(i)->getEnergy());
			modelsBuffer->append(text);
			modelsBuffer->append("\tMax Power: ");
			sprintf_s(text,sizeof(text),"%.2f\n",allModels[checkPartGUI->value()-1].getPart(i)->getPower());
			modelsBuffer->append(text);
		}
		else if(allModels[checkPartGUI->value()-1].getPart(i)->getPartType() == "Torso")
		{
			modelsBuffer->append("\tPossible Batteries: ");
			sprintf_s(text,sizeof(text),"%d\n",allModels[checkPartGUI->value()-1].getPart(i)->getPossibleBatteries());
			modelsBuffer->append(text);
		}
		modelsBuffer->append("\tDescription: ");
		sprintf_s(text,sizeof(text),"%s\n\n",allModels[checkPartGUI->value()-1].getPart(i)->getDescription().c_str());
		modelsBuffer->append(text);

	}
	checkPartGUI->value(0);
	checkPartGUI->deactivate();

}

void AddCustomerCB(Fl_Widget* w, void* p)
{
	name = custNameGUI->value();
	if(name == "")
	{
		fl_choice("ERROR Please enter a Name",0,0,"Okay");
		return;
	}
	phone = custPhoneGUI->value();
	if(phone == "")
	{
		fl_choice("ERROR Please enter a Phone Number",0,0,"Okay");
		return;
	}
	email = custEmailGUI->value();
	if(email == "")
	{
		fl_choice("ERROR Please enter an Email Address",0,0,"Okay");
		return;
	}
	if(custWalletGUI->value() == 0)
	{
		if(fl_choice("WARNING Customer's Wallet is set to 0\nDo you wish to Continue?",0,fl_no,fl_yes) != 2)
		{
			return;
		}
	}
	custNum = custNumGUI->value();

	allCustomers.push_back(Customer(name, custNum, custWalletGUI->value(), phone, email));
	
	custNameGUI->replace(0,custNameGUI->size(),"",0);
	custPhoneGUI->replace(0,custPhoneGUI->size(),"",0);
	custEmailGUI->replace(0,custEmailGUI->size(),"",0);
	custWalletGUI->value(0);
	custNumGUI->value(0);
}

void ReportCustomersCB(Fl_Widget* w, void* p)
{
	char text[500];
	custBuffer->text("");
	custBuffer->append("***List of All Current Customers***\n");
	for(int i = 0; i < allCustomers.size(); i++)
	{
		sprintf_s(text,sizeof(text),"%d.",i+1);
		custBuffer->append(text);
		custBuffer->append("\tCustomer Name: ");
		sprintf_s(text,sizeof(text),"%s\n",allCustomers[i].getName().c_str());
		custBuffer->append(text);
		custBuffer->append("\tCustomer Number: ");
		sprintf_s(text,sizeof(text),"%d\n",allCustomers[i].getCustomerNum());
		custBuffer->append(text);
		custBuffer->append("\tWallet: $");
		sprintf_s(text,sizeof(text),"%.2f\n",allCustomers[i].getWallet());
		custBuffer->append(text);
		custBuffer->append("\tPhone #: ");
		sprintf_s(text,sizeof(text),"%s\n",allCustomers[i].getPhone().c_str());
		custBuffer->append(text);
		custBuffer->append("\tEmail: ");
		sprintf_s(text,sizeof(text),"%s\n\n",allCustomers[i].getEmail().c_str());
		custBuffer->append(text);
	}
}

void AddSACB(Fl_Widget* w, void* p)
{
	name = saNameGUI->value();
	if(name == "")
	{
		fl_choice("ERROR Please enter a Name",0,0,"Okay");
		return;
	}

	allSalesAssoc.push_back(SalesAssoc(saNameGUI->value(),saNumGUI->value()));

	saNameGUI->replace(0,saNameGUI->size(),"",0);
	saNumGUI->value(0);

}

void ReportSACB(Fl_Widget* w, void* p)
{
	char text[500];
	saBuffer->text("");
	saBuffer->append("***List of All Current Sales Associates***\n");
	for(int i = 0; i < allSalesAssoc.size(); i++)
	{
		sprintf_s(text,sizeof(text),"%d.",i+1);
		saBuffer->append(text);
		saBuffer->append("\tSales Associate's Name: ");
		sprintf_s(text,sizeof(text),"%s\n",allSalesAssoc[i].getName().c_str());
		saBuffer->append(text);
		saBuffer->append("\tEmployee Number: ");
		sprintf_s(text,sizeof(text),"%d\n\n",allSalesAssoc[i].getEmployeeNum());
		saBuffer->append(text);
	}

}

void AddOrderCB(Fl_Widget* w, void* p)
{
	modelNum = orderModelGUI->value();
	if(modelNum < 1 || modelNum > allModels.size())
	{
		fl_choice("ERROR No such Model List Number",0,0,"Okay");
		return;
	}
	seller = orderSAGUI->value();
	if(seller < 1 || seller > allSalesAssoc.size())
	{
		fl_choice("ERROR No such Sales Associate List Number",0,0,"Okay");
		return;
	}
	cust = orderCustGUI->value();
	if(cust < 1 || cust > allCustomers.size())
	{
		fl_choice("ERROR No such Customer List Number",0,0,"Okay");
		return;
	}
	quan = orderQuanGUI->value();
	if(quan < 1)
	{
		fl_choice("ERROR Please enter a positive Quantity",0,0,"Okay");
		return;
	}
	num = orderNumGUI->value();

	allOrders.push_back(Order(num, allModels[modelNum-1], quan, allSalesAssoc[seller-1], allCustomers[cust-1]));

	orderModelGUI->value(0);
	orderSAGUI->value(0);
	orderCustGUI->value(0);
	orderQuanGUI->value(0);
	orderNumGUI->value(0);
}

void ReportOrdersCB(Fl_Widget* w, void* p)
{
	char text[500];
	ordersBuffer->text("");
	ordersBuffer->append("***List of All Current Orders***\n");
	for(int i = 0; i < allOrders.size(); i++)
	{
		sprintf_s(text,sizeof(text),"%d.",i+1);
		ordersBuffer->append(text);
		ordersBuffer->append("\tOrder Number: ");
		sprintf_s(text,sizeof(text),"%d\n",allOrders[i].getOrderNum());
		ordersBuffer->append(text);
		ordersBuffer->append("\tRobot Model Name: ");
		sprintf_s(text,sizeof(text),"%s\n",allOrders[i].getRobot().getName().c_str());
		ordersBuffer->append(text);
		ordersBuffer->append("\tRobot Model Number: ");
		sprintf_s(text,sizeof(text),"%d\n",allOrders[i].getRobot().getModelNum());
		ordersBuffer->append(text);
		ordersBuffer->append("\tQuantity: ");
		sprintf_s(text,sizeof(text),"%d\n",allOrders[i].getQuantity());
		ordersBuffer->append(text);
		ordersBuffer->append("\tTotal Price: $");
		sprintf_s(text,sizeof(text),"%.2f\n",allOrders[i].getTotalPrice());
		ordersBuffer->append(text);
		ordersBuffer->append("\tSold by: ");
		sprintf_s(text,sizeof(text),"%s\n",allOrders[i].getSeller().getName().c_str());
		ordersBuffer->append(text);
		ordersBuffer->append("\tBought by: ");
		sprintf_s(text,sizeof(text),"%s\n\n",allOrders[i].getBuyer().getName().c_str());
		ordersBuffer->append(text);
	}
}