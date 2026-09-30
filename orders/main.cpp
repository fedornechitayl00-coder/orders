#include "Order.h"
#include "OrderSysytem.h"
#include <fstream>
#include "Date.h"
#include "Time.h"


int main()
{
	OrderSysytem system;
	
	Date currentDate(30, 9, 2026);
	Time currentTime(18, 50, 0);

	Order order1(currentDate, currentTime, 25, "Pizza Margarita, Apple juice", 185);
	Order order2(currentDate, currentTime, 40, "3 Cheseeburgers, Cola", 340);
	Order order3(currentDate, currentTime, 15, "Pizza Pepperoni, Green tea", 130);

	order1.makeACheck();

	std::cout << "__________________________________\n\n";

	system.addOrder(order1);
	system.addOrder(order2);
	system.addOrder(order3);

	std::cout << "__________________________________\n\n";

	system.sortOrdersBy_CookReady();

	std::cout << "\n____________________________________\n making orders:...\n";
	system.doneOneOrder();  //delete № 3 - 15min

	std::cout << "......\n";
	system.doneOneOrder();  //delete №1 - 25 min

	std::cout << "........\n";
	system.doneOneOrder();  //delete №2 - 40 min

	return 0;
}