#include <iostream>
#include <memory>

#include "Context.hpp"
#include "Expressions.hpp"

int main() {
	Context ctx;
	ctx.setVariable("loggedIn", true);
	ctx.setVariable("isAdmin", false);
	ctx.setVariable("hasPermission", true);

	auto expr = std::make_unique<OrExpression>(
		std::make_unique<AndExpression>(
			std::make_unique<VariableExpression>("loggedIn"),
			std::make_unique<VariableExpression>("hasPermission")
		),
		std::make_unique<VariableExpression>("isAdmin")
	);

	std::cout << "Expression: (loggedIn && hasPermission) || isAdmin\n";
	std::cout << "Result: " << (expr->interpret(ctx) ? "true" : "false") << "\n";

	auto denied = std::make_unique<NotExpression>(
		std::make_unique<VariableExpression>("isAdmin")
	);
	std::cout << "\nExpression: !isAdmin\n";
	std::cout << "Result: " << (denied->interpret(ctx) ? "true" : "false") << "\n";

	return 0;
}
