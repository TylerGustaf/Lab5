//Made by Tyler Gustaf
#ifndef __ROBOTMODEL_H
#define __ROBOTMODEL_H 2016
#include <string.h>
#include <iostream>
#include "RobotPart.h"
#include <vector>

using namespace std;


class RobotModel
{
private:

	string name;
	int modelNum;
	double price;
	vector <RobotPart*> parts;
	string image;
	int jpeg;
	

public:
	RobotModel() : name(""), modelNum(-1), price(-1), image(""){}

	string getName();
	int getModelNum();
	double getPrice();
	string getImage();
	int isJPEG();
	int getNumOfParts();
	RobotPart* getPart(int i);
	void setName(string name1);
	void setModelNum(int num);
	void setPrice(double pri);
	void addPart(RobotPart* part);
	void setImage(string pic);
	void setPicJPEG(int type);
	
	
};

#endif