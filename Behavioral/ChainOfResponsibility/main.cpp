#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

#include "Ticket.hpp"
#include "Handler.hpp"

static Handler* buildChain() {
	auto* l1 = new L1Support();
	auto* l2 = new L2Support();
	auto* senior = new SeniorEngineer();
	auto* manager = new Manager();
	l1->setNext(l2);
	l2->setNext(senior);
	senior->setNext(manager);
	return l1;
}

static void delete_chain(Handler* h) {
	while (h) {
		auto temp = h->get_next();
		delete(h);
		h = temp;
	}
}

TEST(ChainTest, L1HandlesLowBug) {
	Handler* chain = buildChain();

	Ticket t = TicketFactory::create(BUG, LOW, "UI bug");

	testing::internal::CaptureStdout();
	chain->handle(t);
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_NE(output.find("[L1]"), std::string::npos);

	delete_chain(chain);
}

TEST(ChainTest, L2HandlesMediumBug) {
	Handler* chain = buildChain();

	Ticket t = TicketFactory::create(BUG, MEDIUM, "performance issue");

	testing::internal::CaptureStdout();
	chain->handle(t);
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_NE(output.find("[L2]"), std::string::npos);

	delete chain;
}


TEST(ChainTest, SeniorHandlesHighBug) {
	Handler* chain = buildChain();

	Ticket t = TicketFactory::create(BUG, HIGH, "crash");

	testing::internal::CaptureStdout();
	chain->handle(t);
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_NE(output.find("[Senior]"), std::string::npos);

	delete_chain(chain);
}

TEST(ChainTest, ManagerHandlesBilling) {
	Handler* chain = buildChain();

	Ticket t = TicketFactory::create(BILLING, LOW, "refund request");

	testing::internal::CaptureStdout();
	chain->handle(t);
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_NE(output.find("[Manager]"), std::string::npos);

	delete chain;
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


