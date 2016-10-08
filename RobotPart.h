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

	
	virtual int powerConsumed(int speed) = 0;
	virtual int getMaxSpeed() = 0;
	virtual int powerConsumed() = 0;
	virtual double getEnergy() = 0;
	virtual double getPower() = 0;
	virtual int getPossibleBatteries() = 0;

};

class Head : public RobotPart
{
private:

public:
	Head(string name1, string desc, int pNum, double cost1, double wei) 
		: RobotPart(name1, desc, pNum, cost1, wei, "Head") {}

	int powerConsumed(int speed);
	int getMaxSpeed();
	int powerConsumed();
	double getEnergy();
	double getPower();
	int getPossibleBatteries();
};

class Arm : public RobotPart
{
private:

public:
	Arm(string name1, string desc, int pNum, double cost1, double wei) 
		: RobotPart(name1, desc, pNum, cost1, wei, "Arm") {}

	int powerConsumed(int speed);
	
	int getMaxSpeed();
	int powerConsumed();
	double getEnergy();
	double getPower();
	int getPossibleBatteries();

};

class Motor : public RobotPart
{
private:

	int maxSpeed;

public:
	Motor(string name1, string desc, int pNum, double cost1, double wei, int speed) 
		: RobotPart(name1, desc, pNum, cost1, wei, "Motor"), maxSpeed(speed) {}

	int getMaxSpeed();
	int powerConsumed();

	int powerConsumed(int speed);
	double getEnergy();
	double getPower();
	int getPossibleBatteries();

};

class Battery : public RobotPart
{
private:

	double energy;
	double maxPower;

public:
	Battery(string name1, string desc, int pNum, double cost1, double wei, double ener, double power) 
		: RobotPart(name1, desc, pNum, cost1, wei, "Battery"), energy(ener), maxPower(power) {}
	
	double getEnergy();
	double getPower();

	int powerConsumed(int speed);
	int getMaxSpeed();
	int powerConsumed();
	int getPossibleBatteries();
};

class Torso : public RobotPart
{
private:

	int possibleBatteries;

public:
	Torso(string name1, string desc, int pNum, double cost1, double wei, int numBats) 
		: RobotPart(name1, desc, pNum, cost1, wei, "Torso"), possibleBatteries(numBats) {}

	int getPossibleBatteries();

	int powerConsumed(int speed);
	int getMaxSpeed();
	int powerConsumed();
	double getEnergy();
	double getPower();

};
#endif