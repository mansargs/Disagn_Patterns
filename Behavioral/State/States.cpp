#include "States.hpp"

void IdleState::insertCoin(VendingMachine& machine) {
	std::cout << "Coin inserted.\n";
	machine.setState(new ReadyState());
}

void IdleState::selectProduct(VendingMachine& machine) {
	(void)machine;
	std::cout << "Insert a coin first.\n";
}

void IdleState::dispense(VendingMachine& machine) {
	(void)machine;
	std::cout << "Insert a coin first.\n";
}

void ReadyState::insertCoin(VendingMachine& machine) {
	(void)machine;
	std::cout << "Coin already inserted.\n";
}

void ReadyState::selectProduct(VendingMachine& machine) {
	std::cout << "Product selected.\n";
	machine.setState(new SoldState());
}

void ReadyState::dispense(VendingMachine& machine) {
	(void)machine;
	std::cout << "Select a product first.\n";
}

void SoldState::insertCoin(VendingMachine& machine) {
	(void)machine;
	std::cout << "Please wait, dispensing product.\n";
}

void SoldState::selectProduct(VendingMachine& machine) {
	(void)machine;
	std::cout << "Product already selected.\n";
}

void SoldState::dispense(VendingMachine& machine) {
	std::cout << "Product dispensed.\n";
	machine.releaseProduct();
	if (machine.hasStock())
		machine.setState(new IdleState());
	else
		machine.setState(new SoldOutState());
}

void SoldOutState::insertCoin(VendingMachine& machine) {
	(void)machine;
	std::cout << "Machine is sold out.\n";
}

void SoldOutState::selectProduct(VendingMachine& machine) {
	(void)machine;
	std::cout << "Machine is sold out.\n";
}

void SoldOutState::dispense(VendingMachine& machine) {
	(void)machine;
	std::cout << "Machine is sold out.\n";
}
