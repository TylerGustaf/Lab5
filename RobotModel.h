//Made by Tyler Gustaf
#include <string.h>
#include <iostream>
#include "RobotPart.h"
#include <vector>

using namespace std;
#ifndef __ROBOTMODEL_H
#define __ROBOTMODEL_H 2016


class RobotModel
{
private:

	string name;
	int modelNum;
	double price;
	vector <RobotPart*> parts;

public:
	RobotModel() : name(""), modelNum(-1), price(-1){}

	string getName();
	int getModelNum();
	double getPrice();
	int getNumOfParts();
	RobotPart* getPart(int i);
	void setName(string name1);
	void setModelNum(int num);
	void setPrice(double pri);
	void addPart(RobotPart* part);
	
	
};

#endif