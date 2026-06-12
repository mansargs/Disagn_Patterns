#pragma once

#include <string>

class Colleague;

class IMediator {
	public:
		virtual void sendMessage(const std::string& message, Colleague* sender) = 0;
		virtual ~IMediator() = default;
};
