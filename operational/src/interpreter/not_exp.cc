// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "not_exp.h"

namespace operational
{
namespace interpreter
{
NotExp::NotExp(BooleanExpInterface* operand) : operand_(operand) { }

bool NotExp::Evaluate(InterpreterContextInterface& context)
{
	return !operand_->Evaluate(context);
}

BooleanExpInterface *NotExp::Replace(const std::string& name, BooleanExpInterface& expression)
{
	return new NotExp(operand_->Replace(name, expression));
}

BooleanExpInterface *NotExp::Copy() const
{
	return new NotExp(operand_->Copy());
}
}
}

