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
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_ask.H>

void ButtonCB(Fl_Widget*, void*);
void CloseCB(Fl_Widget*, void*);
void InputStringCB(Fl_Widget*, void*);

int main()
{
	Fl_Window *win = new Fl_Window(250,250, "Robbie Robot Shop");
	Fl_Button *button1 = new Fl_Button(50,50,50,50,"Button1");
	Fl_Button *button2 = new Fl_Button(50,100,50,50,"Button2");
	button1->when(FL_WHEN_RELEASE);
	button1->callback(ButtonCB,"Button1");
	button2->when(FL_WHEN_RELEASE);
	button2->callback(InputStringCB);
	win->resizable(*button1);
	win->resizable(*button2);
	win->callback(CloseCB);


	win->end();
	win->show();

	return Fl::run();
}

void CloseCB(Fl_Widget* w, void* p)
{
	Fl_Window* win = (Fl_Window*)w;
	
	if(fl_choice("Are you sure you want to quit?","Maybe?","No","Yes") == 2)
	{
		win->hide();
	}
}
void ButtonCB(Fl_Widget* w, void* p)
{
	Fl_Button *b = (Fl_Button*)w;
	cout << (char*)p << " was pressed\n";
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