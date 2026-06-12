#pragma once

#include <iostream>

class CaffeineBeverage {
	public:
		void prepareRecipe() {
			boilWater();
			brew();
			pourInCup();
			if (customerWantsCondiments())
				addCondiments();
		}

		virtual ~CaffeineBeverage() = default;

	protected:
		void boilWater() {
			std::cout << "Boiling water\n";
		}

		void pourInCup() {
			std::cout << "Pouring into cup\n";
		}

		virtual void brew() = 0;
		virtual void addCondiments() = 0;

		virtual bool customerWantsCondiments() {
			return true;
		}
};

class Coffee : public CaffeineBeverage {
	protected:
		void brew() override {
			std::cout << "Dripping coffee through filter\n";
		}

		void addCondiments() override {
			std::cout << "Adding sugar and milk\n";
		}
};

class Tea : public CaffeineBeverage {
	protected:
		void brew() override {
			std::cout << "Steeping the tea\n";
		}

		void addCondiments() override {
			std::cout << "Adding lemon\n";
		}

		bool customerWantsCondiments() override {
			return false;
		}
};
