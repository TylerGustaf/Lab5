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

int RobotPart::powerConsumed(int speed){return 0;};
int RobotPart::getMaxSpeed() {return 0;};
int RobotPart::powerConsumed() {return 0;};
double RobotPart::getEnergy() {return 0;};
double RobotPart::getPower() {return 0;};
int RobotPart::getPossibleBatteries() {return 0;};

int Head::powerConsumed(int speed){return 0;};
int Head::getMaxSpeed() {return 0;};
int Head::powerConsumed() {return 0;};
double Head::getEnergy() {return 0;};
double Head::getPower() {return 0;};
int Head::getPossibleBatteries() {return 0;};

//Convert speed to Meters per Second and multiply by Newtons to get Watts
int Arm::powerConsumed(int speed){return (speed * (5280/11808)) * weight;}
int Arm::getMaxSpeed() {return 0;};
int Arm::powerConsumed() {return 0;};
double Arm::getEnergy() {return 0;};
double Arm::getPower() {return 0;};
int Arm::getPossibleBatteries() {return 0;};

int Motor::getMaxSpeed(){return maxSpeed;}
//Convert speed to Meters per Second and multiply by Newtons to get Watts
int Motor::powerConsumed(){return (maxSpeed * (5280/11808)) * weight;}
int Motor::powerConsumed(int speed){return 0;};
double Motor::getEnergy() {return 0;};
double Motor::getPower() {return 0;};
int Motor::getPossibleBatteries() {return 0;};

double Battery::getEnergy(){return energy;}
double Battery::getPower(){return maxPower;}
int Battery::powerConsumed(int speed){return 0;};
int Battery::getMaxSpeed() {return 0;};
int Battery::powerConsumed() {return 0;};
int Battery::getPossibleBatteries() {return 0;};

int Torso::getPossibleBatteries(){return possibleBatteries;}
int Torso::powerConsumed(int speed){return 0;};
int Torso::getMaxSpeed() {return 0;};
int Torso::powerConsumed() {return 0;};
double Torso::getEnergy() {return 0;};
double Torso::getPower() {return 0;};
