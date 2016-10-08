#include <string.h>
#include <iostream>
#include "RobotPart.h"

using namespace std;

	string RobotPart::getName(){return name;}
	string RobotPart::getDescription(){return description;}
	string RobotPart::getPartType(){return partType;}
	int RobotPart::getPartNum(){return partNum;}
	double RobotPart::getCost(){return cost;}
	double RobotPart::getWeight(){return weight;}

	int Arm::powerConsumed(int speed)
	{
		//Convert speed to Meters per Second and multiply by Newtons to get Watts
		return (speed * (5280/11808)) * weight;
	}