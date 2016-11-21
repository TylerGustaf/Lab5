//Made by Tyler Gustaf
#include <string.h>
#include <iostream>
#include "RobotPart.h"
#include "RobotModel.h"

using namespace std;


string RobotModel::getName(){return name;}
int RobotModel::getModelNum(){return modelNum;}
double RobotModel::getPrice(){return price;}
string RobotModel::getImage(){return image;}
int RobotModel::isJPEG(){return jpeg;}
RobotPart* RobotModel::getPart(int i){return parts[i];}
int RobotModel::getNumOfParts(){return parts.size();}
void RobotModel::setName(string name1){name = name1;}
void RobotModel::setModelNum(int num){modelNum = num;}
void RobotModel::setPrice(double pri){price = pri;}
void RobotModel::addPart(RobotPart* part){parts.push_back(part);}
void RobotModel::setImage(string pic){image = pic;}
void RobotModel::setPicJPEG(int type){jpeg = type;}

