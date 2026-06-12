#pragma once

#include <iostream>
#include "Ticket.hpp"

class Handler {
	private:
		Handler* next = nullptr;

	public:
		virtual ~Handler() = default;

		Handler* get_next() const {
			return next;
		}

		void setNext(Handler* nextHandler) {
			next = nextHandler;
		}

		void handle(const Ticket& ticket) {
			if (process(ticket))
				return;
			if (next)
				next->handle(ticket);
			else
				std::cout << "Ticket " << ticket.id << " was NOT handled\n";
		}

	protected:
		virtual bool process(const Ticket& ticket) = 0;
};

class L1Support : public Handler {
	protected:
		bool process(const Ticket& ticket) override {
			if (ticket.type == GENERAL || (ticket.type == BUG && ticket.priority == LOW)) {
				std::cout << "[L1] handled ticket " << ticket.id << "\n";
				return true;
			}
			return false;
		}
};

class L2Support : public Handler {
	protected:
		bool process(const Ticket& ticket) override {
			if (ticket.type == BUG && ticket.priority == MEDIUM) {
				std::cout << "[L2] handled medium bug " << ticket.id << "\n";
				return true;
			}
			if (ticket.type == FEATURE_REQUEST) {
				std::cout << "[L2] handled feature request " << ticket.id << "\n";
				return true;
			}
			return false;
		}
};

class SeniorEngineer : public Handler {
	protected:
		bool process(const Ticket& ticket) override {
			if (ticket.type == BUG && ticket.priority == HIGH) {
				std::cout << "[Senior] fixed critical bug " << ticket.id << "\n";
				return true;
			}
			if (ticket.type == FEATURE_REQUEST) {
				std::cout << "[Senior] implemented feature " << ticket.id << "\n";
				return true;
			}
			return false;
		}
};

class Manager : public Handler {
	protected:
		bool process(const Ticket& ticket) override {
			std::cout << "[Manager] escalated ticket " << ticket.id << "\n";
			return true;
		}
};
