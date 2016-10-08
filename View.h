#include "std_lib_facilities.h"
#include <vector>
#include "RobotModel.h"
#include "RobotPart.h"
#ifndef __VIEW_H
#define __VIEW_H 2016

class View
{
private:

public:
	View(){}

	void printMM();
	void printParts(vector <RobotPart*> &parts);
	void printModels(vector <RobotModel*> &models);


};




#endif