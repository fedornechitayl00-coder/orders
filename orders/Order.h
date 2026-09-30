#pragma once
#include "Date.h"
#include "Time.h"

class Order
{
	static int count;
	Date dateOrder;
	Time timeOrder;
	int cookOrderDuration;
	std::string descriptionOfOrder;
	float priceOrder;
	int numberOrder;

public:
	Order();
	Order(Date dateOrder, Time timeOrder, int cookOrderDuration, std::string descriptionOfOrder,
		float priceOrder);

	Date getDateOrder() const;
	Time getTimeOrder() const;
	int getCookOrderDuration() const;
	float getPriceOrder() const;
	int getNumberOrder() const;

	Time timeOrderIsReady() const;
	void makeACheck() const;

	friend std::ostream& operator << (std::ostream& out, const Order& obj);
};

