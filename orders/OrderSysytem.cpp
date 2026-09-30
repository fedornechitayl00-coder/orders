#include "OrderSysytem.h"
#include "Order.h"
#include <algorithm>

void OrderSysytem::addOrder(const Order& order)
{
	orders.push_back(order);
}

void OrderSysytem::sortOrdersBy_CookReady()
{
	std::sort(orders.begin(), orders.end(), [](Order& a, Order& b)
		{return a.timeOrderIsReady() < b.timeOrderIsReady(); });
}

void OrderSysytem::doneOneOrder() 
{
	if (!orders.empty()) {
		orders.front().makeACheck();  //берем первый элемент в масиве, front() - возвращает сам объект(посилання)
		orders.erase(orders.begin());   //begin - возвращает указатель на первый элемент
	}
}
