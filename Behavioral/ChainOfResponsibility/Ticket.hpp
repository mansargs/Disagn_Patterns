#pragma once

#include <string>

enum TicketType {
	BUG,
	BILLING,
	FEATURE_REQUEST,
	GENERAL
};

enum TicketPriority {
	LOW,
	MEDIUM,
	HIGH
};

class TicketIdGenerator {
	private:
		static inline size_t counter = 0;
	public:
		static size_t next() {
			return ++counter;
		}
};

struct Ticket {
	size_t id;
	TicketType type;
	TicketPriority priority;
	std::string msg;

	Ticket(size_t id, TicketType t, TicketPriority p, std::string m) : id(id), type(t),
		priority(p), msg(std::move(m)) {}
};


class TicketFactory {
	public:
		static Ticket create(TicketType type, TicketPriority priority, std::string msg) {
			return Ticket(
				TicketIdGenerator::next(),
				type,
				priority,
				std::move(msg)
			);
		}
};


