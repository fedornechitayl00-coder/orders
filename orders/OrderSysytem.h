#pragma once
#include "Order.h"
#include <vector>

class OrderSysytem
{
	std::vector<Order> orders;

public:
	void addOrder(const Order& order);

	void sortOrdersBy_CookReady();
	void doneOneOrder();
};

