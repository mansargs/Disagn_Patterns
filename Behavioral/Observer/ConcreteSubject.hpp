#include <vector>
#include <algorithm>

#include "ASubject.hpp"
#include "IObserver.hpp"

class ConcreteSubject : public Subject {
	private:
		std::vector<Observer*> observers;
		int state = 0;
	
	public:
		void attach(Observer* o) override {
			observers.push_back(o);
		}
	
		void detach(Observer* o) override {
			observers.erase(
				std::remove(observers.begin(), observers.end(), o),
				observers.end()
			);
		}
	
		void notify() override {
			for (auto* obs : observers) {
				obs->update(state);
			}
		}
	
		void setState(int newState) {
			state = newState;
			notify();
		}
};
