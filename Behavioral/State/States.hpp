#pragma once

#include "IState.hpp"
#include "VendingMachine.hpp"

class IdleState : public IState {
	public:
		void insertCoin(VendingMachine& machine) override;
		void selectProduct(VendingMachine& machine) override;
		void dispense(VendingMachine& machine) override;
};

class ReadyState : public IState {
	public:
		void insertCoin(VendingMachine& machine) override;
		void selectProduct(VendingMachine& machine) override;
		void dispense(VendingMachine& machine) override;
};

class SoldState : public IState {
	public:
		void insertCoin(VendingMachine& machine) override;
		void selectProduct(VendingMachine& machine) override;
		void dispense(VendingMachine& machine) override;
};

class SoldOutState : public IState {
	public:
		void insertCoin(VendingMachine& machine) override;
		void selectProduct(VendingMachine& machine) override;
		void dispense(VendingMachine& machine) override;
};
