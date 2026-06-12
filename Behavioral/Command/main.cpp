#include <gtest/gtest.h>

#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "Receivers.hpp"
#include "ConcreteCommands.hpp"
#include "Invoker.hpp"

class CoutCapture {
	public:
		CoutCapture() : oldBuf(std::cout.rdbuf(oss.rdbuf())) {}

		~CoutCapture() { std::cout.rdbuf(oldBuf); }

		std::string str() const { return oss.str(); }

		void clear() { oss.str(""); oss.clear(); }

	private:
	
		std::ostringstream oss;
		std::streambuf* oldBuf;
};

TEST(LightCommands, OnOff) {
	Light light;
	LightOnCommand on(&light);
	LightOffCommand off(&light);

	CoutCapture cap;
	on.execute();
	EXPECT_NE(std::string::npos, cap.str().find("The light turned on."));
	cap.clear();
	off.execute();
	EXPECT_NE(std::string::npos, cap.str().find("The light turned off."));
}

TEST(TVCommands, OnOff) {
	TV tv;
	TVOnCommand on(&tv);
	TVOffCommand off(&tv);

	CoutCapture cap;
	on.execute();
	EXPECT_NE(std::string::npos, cap.str().find("The TV turned on."));
	cap.clear();
	off.execute();
	EXPECT_NE(std::string::npos, cap.str().find("The TV turned off."));
}

TEST(StereoCommands, PlayStop) {
	Stereo s;
	StereoPlayCommand play(&s);
	StereoStopCommand stop(&s);

	CoutCapture cap;
	play.execute();
	EXPECT_NE(std::string::npos, cap.str().find("The Stereo is playing."));
	cap.clear();
	stop.execute();
	EXPECT_NE(std::string::npos, cap.str().find("The Stereo stoped."));
}

TEST(InvokerTest, RemoteControlExecutes) {
	Light light;
	LightOnCommand on(&light);
	RemoteControl rc;

	CoutCapture cap;
	rc.press(&on);
	EXPECT_NE(std::string::npos, cap.str().find("The light turned on."));
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
