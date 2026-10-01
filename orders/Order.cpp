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
	std::cout << "\033[30;107m\tCheck\t\033[3m" << getNumberOrder() <<
		"\n\033[0m\033[30;107m_____________________________________\n";
	std::cout << "\033[1mDATE:\033[22m " << getDateOrder() << "\t" << getTimeOrder() <<
		"\n\033[1mORDER IS READY:\033[22m " << timeOrderIsReady() <<
		"\n_____________________________________\n" <<
		descriptionOfOrder <<
		"\n_____________________________________\n" <<
		"\033[1mTOTAL:\033[22m " << getPriceOrder() << "\033[0m\n";
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
