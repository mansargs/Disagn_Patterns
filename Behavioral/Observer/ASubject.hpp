#pragma once

class Observer;

class Subject {
	public:
		virtual ~Subject() = default;
	
		virtual void attach(Observer* o) = 0;
		virtual void detach(Observer* o) = 0;
		virtual void notify() = 0;
};
