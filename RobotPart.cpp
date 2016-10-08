#include <string.h>
#include <iostream>
#include "RobotPart.h"

using namespace std;

	string RobotPart::getName(){return name;}
	string RobotPart::getDescription(){return description;}
	int RobotPart::getPartNum(){return partNum;}
	double RobotPart::getCost(){return cost;}
	double RobotPart::getWeight(){return weight;}