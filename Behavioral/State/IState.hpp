#pragma once

#include <iostream>

class VendingMachine;

class IState {
	public:
		virtual void insertCoin(VendingMachine& machine) = 0;
		virtual void selectProduct(VendingMachine& machine) = 0;
		virtual void dispense(VendingMachine& machine) = 0;
		virtual ~IState() = default;
};
