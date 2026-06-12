#pragma once

#include "ICommand.hpp"
#include "Receivers.hpp"


class LightOnCommand : public ICommand {
	private:
		Light* light;
	public:
		LightOnCommand(Light* l) : light(l) {}

		void execute() {
			light->turnOn();
		}
};

class LightOffCommand : public ICommand {
	private:
		Light* light;
	public:
		LightOffCommand(Light* l) : light(l) {}

		void execute() {
			light->turnOff();
		}
};


class TVOnCommand : public ICommand {
	private:
		TV* tv;
	public:
		TVOnCommand(TV* t) : tv(t) {}

		void execute() {
			tv->turnOn();
		}
};

class TVOffCommand : public ICommand {
	private:
		TV* tv;
	public:
		TVOffCommand(TV* t) : tv(t) {}

		void execute() {
			tv->turnOff();
		}
};


class StereoPlayCommand : public ICommand {
	private:
		Stereo* st;
	public:
		StereoPlayCommand(Stereo* s) : st(s) {}

		void execute() {
			st->play();
		}
};

class StereoStopCommand : public ICommand {
	private:
		Stereo* st;
	public:
		StereoStopCommand(Stereo* s) : st(s) {}

		void execute() {
			st->stop();
		}
};
