#pragma once

#include <memory>
#include <string>

#include "IExpression.hpp"

class VariableExpression : public IExpression {
	private:
		std::string name;

	public:
		explicit VariableExpression(const std::string& name) : name(name) {}

		bool interpret(Context& ctx) const override {
			return ctx.lookup(name);
		}
};

class AndExpression : public IExpression {
	private:
		std::unique_ptr<IExpression> left;
		std::unique_ptr<IExpression> right;

	public:
		AndExpression(std::unique_ptr<IExpression> left, std::unique_ptr<IExpression> right)
			: left(std::move(left)), right(std::move(right)) {}

		bool interpret(Context& ctx) const override {
			return left->interpret(ctx) && right->interpret(ctx);
		}
};

class OrExpression : public IExpression {
	private:
		std::unique_ptr<IExpression> left;
		std::unique_ptr<IExpression> right;

	public:
		OrExpression(std::unique_ptr<IExpression> left, std::unique_ptr<IExpression> right)
			: left(std::move(left)), right(std::move(right)) {}

		bool interpret(Context& ctx) const override {
			return left->interpret(ctx) || right->interpret(ctx);
		}
};

class NotExpression : public IExpression {
	private:
		std::unique_ptr<IExpression> operand;

	public:
		explicit NotExpression(std::unique_ptr<IExpression> operand)
			: operand(std::move(operand)) {}

		bool interpret(Context& ctx) const override {
			return !operand->interpret(ctx);
		}
};
