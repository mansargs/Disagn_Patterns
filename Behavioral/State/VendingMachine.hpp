#pragma once

class IState;

class VendingMachine {
	private:
		IState* state;
		int stock;

	public:
		VendingMachine();
		~VendingMachine();

		void insertCoin();
		void selectProduct();
		void dispense();

		void setState(IState* newState);
		void releaseProduct();

		int getStock() const { return stock; }
		bool hasStock() const { return stock > 0; }
};
