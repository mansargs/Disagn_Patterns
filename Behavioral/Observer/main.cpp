#include "ConcreteObserver.hpp"
#include "ConcreteSubject.hpp"

int main() {
	ConcreteSubject subject;
	ConcreteObserver obs;

	subject.attach(&obs);
	subject.setState(42);

	return 0;
}
