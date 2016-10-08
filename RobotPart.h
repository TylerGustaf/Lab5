#ifndef __ROBOTPART_H
#define __ROBOTPART_H 2016;

class RobotPart{

protected:
	string name;
	string description;
	int partNum;
	double cost;
	double weight;

public:
	RobotPart(string name1, string desc, int pNum, double cost1, double wei) : name(name1), 
		description(desc), partNum(pNum), cost(cost1), weight(wei) {}

	string getName();
	string getDescription();
	int getPartNum();
	double getCost();
	double getWeight();


}



#endif