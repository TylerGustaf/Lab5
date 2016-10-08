#include "RobotPart.h"
#include "std_lib_facilities.h"

int main()
{
	Torso robbie("Robert", "He is a nice robot", 5, 59.99, 69.69, 3);

	
	cout << robbie.getName() <<endl <<robbie.getDescription() <<endl;
	cout << "PartNum " << robbie.getPartNum();
	cout <<endl << "Cost " << robbie.getCost() <<endl << "Weight " << robbie.getWeight() <<endl;
	cout <<"Possible Batteries " << robbie.getPossibleBatteries() <<endl;
	cout <<robbie.getPartType() <<endl;
	
	return 0;
}
