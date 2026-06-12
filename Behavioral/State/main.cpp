#include "VendingMachine.hpp"

int main() {
	VendingMachine machine;

	machine.insertCoin();
	machine.selectProduct();
	machine.dispense();

	machine.insertCoin();
	machine.selectProduct();
	machine.dispense();

	machine.insertCoin();

	return 0;
}
