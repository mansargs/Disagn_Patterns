#pragma once

#include <iostream>

class Light {
	public:
		void turnOn() {
			std::cout << "The light turned on.\n";
		}

		void turnOff() {
			std::cout << "The light turned off.\n";
		}
};

class TV {
	public:
		void turnOn() {
			std::cout << "The TV turned on.\n";
		}

		void turnOff() {
			std::cout << "The TV turned off.\n";
		}
};


class Stereo {
	public:
		void play() {
			std::cout << "The Stereo is playing.\n";
		}

		void stop() {
			std::cout << "The Stereo stoped.\n";
		}
};
