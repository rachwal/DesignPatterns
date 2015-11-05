// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_INTERPRETER_OR_EXP_H_
#define OPERATIONAL_INTERPRETER_OR_EXP_H_

#include "boolean_exp_interface.h"

namespace operational
{
namespace interpreter
{
class OrExp : public BooleanExpInterface
{
	public:
	OrExp(BooleanExpInterface* left_operand, BooleanExpInterface* right_operand);

	virtual bool Evaluate(InterpreterContextInterface& context) override;
	virtual BooleanExpInterface *Replace(const std::string& name, BooleanExpInterface& expression) override;
	virtual BooleanExpInterface *Copy() const override;

	private:
	BooleanExpInterface* left_operand_;
	BooleanExpInterface* right_operand_;
};
}
}

#endif

