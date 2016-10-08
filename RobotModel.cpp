#include <string.h>
#include <iostream>
#include "RobotPart.h"
#include "RobotModel.h"

using namespace std;


string RobotModel::getName(){return name;}
int RobotModel::getModelNum(){return modelNum;}
double RobotModel::getPrice(){return price;}
RobotPart* RobotModel::getPart(int i){return parts[i];}
int RobotModel::getNumOfParts(){return parts.size();}
void RobotModel::setName(string name1){name = name1;}
void RobotModel::setModelNum(int num){modelNum = num;}
void RobotModel::setPrice(double pri){price = pri;}
void RobotModel::addPart(RobotPart* part){parts.push_back(part);}

