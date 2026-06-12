#include <iostream>
#include "IObserver.hpp"

class ConcreteObserver : public Observer {
public:
	void update(int value) override {
		std::cout << "Observer received value: " << value << std::endl;
	}
};
