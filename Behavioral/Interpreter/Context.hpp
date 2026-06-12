#pragma once

#include <map>
#include <string>

class Context {
	private:
		std::map<std::string, bool> variables;

	public:
		void setVariable(const std::string& name, bool value) {
			variables[name] = value;
		}

		bool lookup(const std::string& name) const {
			auto it = variables.find(name);
			return it != variables.end() && it->second;
		}
};
