#include "RobotPart.h"
#include "std_lib_facilities.h"

int main()
{
	string name = "Robert";
	string desc = "He is a nice robot";
	Arm robbie(name, desc, 5, 59.99, 69.69);

	
	cout << robbie.getName() <<endl <<robbie.getDescription() <<endl;
	cout << "PartNum " << robbie.getPartNum();
	cout <<endl << "Cost " << robbie.getCost() <<endl << "Weight " << robbie.getWeight() <<endl;
	cout <<robbie.getPartType() <<endl;
	
	return 0;
}
