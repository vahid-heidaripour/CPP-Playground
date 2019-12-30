#include <iostream>
#include "AirlineTicket.h"

int main() {
	AirlineTicket myTicket; //stack-based AirlineTicket
	myTicket.setPassengerName("Vahid H. Lakhani");
	myTicket.setNumberOfMiles(1000);
	double cost = myTicket.calculatePriceInDollars();
	std::cout << "This ticket will cost $" << cost << std::endl;

	auto myTicket2 = std::make_unique<AirlineTicket>(); //heap-based AirlineTicket with smart pointer
	myTicket2->setPassengerName("Saeed H. Lakhani");
	myTicket2->setNumberOfMiles(2000);
	myTicket2->setHasEliteSuperRewardsStatus(true);
	std::cout << "This other ticket will cost $" << myTicket2->calculatePriceInDollars() << std::endl;

	return 0;
}