#include <string.h>
#include <iostream>

using namespace std;
#ifndef __ROBOTPART_H
#define __ROBOTPART_H 2016;


class RobotPart{

protected:
	string name;
	string description;
	string partType;
	int partNum;
	double cost;
	double weight;

public:
	RobotPart(string name1, string desc, int pNum, double cost1, double wei, string pType) : name(name1), 
		description(desc), partNum(pNum), cost(cost1), weight(wei), partType(pType) {}

	string getName();
	string getDescription();
	string getPartType();
	int getPartNum();
	double getCost();
	double getWeight();


};

class Arm : public RobotPart
{
private:

public:
	Arm(string name1, string desc, int pNum, double cost1, double wei) : RobotPart(name1, desc, pNum, cost1, wei, "Arm") {}

	int powerConsumed(int speed);

};

#endif