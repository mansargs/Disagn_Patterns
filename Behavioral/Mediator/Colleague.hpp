#pragma once

#include <iostream>
#include <string>

#include "IMediator.hpp"

class Colleague {
	protected:
		IMediator* mediator;
		std::string name;

	public:
		Colleague(IMediator* mediator, const std::string& name)
			: mediator(mediator), name(name) {}

		virtual ~Colleague() = default;

		void send(const std::string& message) {
			std::cout << "[" << name << "] sends: " << message << "\n";
			mediator->sendMessage(message, this);
		}

		virtual void receive(const std::string& message) = 0;
};
