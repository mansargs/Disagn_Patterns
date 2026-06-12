#include "VendingMachine.hpp"
#include "States.hpp"

VendingMachine::VendingMachine() : state(new IdleState()), stock(2) {}

VendingMachine::~VendingMachine() {
	delete state;
}

void VendingMachine::insertCoin() {
	state->insertCoin(*this);
}

void VendingMachine::selectProduct() {
	state->selectProduct(*this);
}

void VendingMachine::dispense() {
	state->dispense(*this);
}

void VendingMachine::setState(IState* newState) {
	delete state;
	state = newState;
}

void VendingMachine::releaseProduct() {
	if (stock > 0)
		--stock;
}
