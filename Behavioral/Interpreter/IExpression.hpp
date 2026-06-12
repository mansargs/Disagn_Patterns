#pragma once

#include "Context.hpp"

class IExpression {
	public:
		virtual bool interpret(Context& ctx) const = 0;
		virtual ~IExpression() = default;
};
