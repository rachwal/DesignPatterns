// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "variable_exp.h"

namespace operational
{
namespace interpreter
{
VariableExp::VariableExp(const std::string& name) : name_(name) { }

bool VariableExp::Evaluate(InterpreterContextInterface& context)
{
	return context.Lookup(name_);
}

BooleanExpInterface *VariableExp::Copy() const
{
	return new VariableExp(name_);
}

std::string VariableExp::name() const
{
	return name_;
}

BooleanExpInterface *VariableExp::Replace(const std::string& name, BooleanExpInterface& expression)
{
	if (name_.compare(name) == 0)
	{
		return expression.Copy();
	}
	return new VariableExp(name_);
}
}
}

