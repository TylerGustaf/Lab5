//Made by Tyler Gustaf
#include "string.h"
#include <vector>
#include "Order.h"

using namespace std;

int Order::getOrderNum(){ return orderNum; }
RobotModel Order::getRobot(){ return robot; }
SalesAssoc Order::getSeller(){ return seller; }
Customer Order::getBuyer(){ return buyer; }
double Order::getTotalPrice(){ return (robot.getPrice() * quantity) + getTax(); }
double Order::getTax(){ return (robot.getPrice() * quantity) * 0.0825; }
int Order::getQuantity(){ return quantity; }