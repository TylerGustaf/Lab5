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

	//Convert speed to Meters per Second and multiply by Newtons to get Watts
	int Arm::powerConsumed(int speed){return (speed * (5280/11808)) * weight;}

	int Motor::getMaxSpeed(){return maxSpeed;}
	//Convert speed to Meters per Second and multiply by Newtons to get Watts
	int Motor::powerConsumed(){return (maxSpeed * (5280/11808)) * weight;}

	double Battery::getEnergy(){return energy;}
	double Battery::getPower(){return maxPower;}

	int Torso::getPossibleBatteries(){return possibleBatteries;}
