#include "Order.h"

int Order::count = 0;

Order::Order()
{
	dateOrder = Date();
	timeOrder = Time();
	cookOrderDuration = 0;
	descriptionOfOrder = "undefined";
	priceOrder = 0;
	numberOrder = 0;
}

Order::Order(Date dateOrder, Time timeOrder, int cookOrderDuration, std::string descriptionOfOrder,
	float priceOrder)
{
	this->dateOrder = dateOrder;
	this->timeOrder = timeOrder;
	this->cookOrderDuration = cookOrderDuration;
	this->descriptionOfOrder = descriptionOfOrder;
	this->priceOrder = priceOrder;

	numberOrder = ++count;
}

Date Order::getDateOrder() const
{
	return dateOrder;
}

Time Order::getTimeOrder() const
{
	return timeOrder;
}

int Order::getCookOrderDuration() const
{
	return cookOrderDuration;
}

float Order::getPriceOrder() const
{
	return priceOrder;
}

int Order::getNumberOrder() const
{ 
	return numberOrder;
}

Time Order::timeOrderIsReady() const
{
	return (timeOrder + cookOrderDuration);
}

void Order::makeACheck() const
{
	std::cout << "\tCheck\n" << getNumberOrder() <<
		"\n_____________________________________\n";
	std::cout << "DATE: " << getDateOrder() << "\t" << getTimeOrder() <<
		"\nORDER IS READY: " << timeOrderIsReady() <<
		"\n_____________________________________\n" <<
		descriptionOfOrder <<
		"\n_____________________________________\n" <<
		"TOTAL: " << getPriceOrder();
}

std::ostream& operator<<(std::ostream& out, const Order& obj)
{
	out << std::endl << obj.getNumberOrder();
	out << "\nDATE: " << obj.getDateOrder() << "\t" << obj.getTimeOrder() <<
		"\nORDER IS READY: " << obj.timeOrderIsReady() <<
		obj.descriptionOfOrder <<
		"\n_____________________________________\n" <<
		"TOTAL: " << obj.getPriceOrder();
	return out;
}
