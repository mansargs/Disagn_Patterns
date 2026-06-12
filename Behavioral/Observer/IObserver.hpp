#pragma once

#pragma once

class Observer {
	public:
		virtual ~Observer() = default;
		virtual void update(int value) = 0;
};
