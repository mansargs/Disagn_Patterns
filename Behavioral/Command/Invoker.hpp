#pragma once

#include "ICommand.hpp"

class RemoteControl {
	public:
		void press(ICommand* cmd) {
				cmd->execute();
		}
};
