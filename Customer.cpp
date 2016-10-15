//Made by Tyler Gustaf
#include "string.h"
#include <vector>
#include "Customer.h"

using namespace std;


string Customer::getName(){ return name; }
int Customer::getCustomerNum(){ return customerNum; }
double Customer::getWallet(){ return wallet; }
void Customer::setWallet(double newWallet){ wallet = newWallet; }
//void Customer::addOrder(Order order){ orders.push_back(order); }