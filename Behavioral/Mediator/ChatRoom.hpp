#pragma once

#include <vector>

#include "Colleague.hpp"
#include "IMediator.hpp"

class User : public Colleague {
	public:
		User(IMediator* mediator, const std::string& name)
			: Colleague(mediator, name) {}

		void receive(const std::string& message) override {
			std::cout << "[" << name << "] received: " << message << "\n";
		}
};

class ChatRoom : public IMediator {
	private:
		std::vector<Colleague*> users;

	public:
		void addUser(Colleague* user) {
			users.push_back(user);
		}

		void sendMessage(const std::string& message, Colleague* sender) override {
			for (Colleague* user : users) {
				if (user != sender)
					user->receive(message);
			}
		}
};
