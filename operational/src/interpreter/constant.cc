// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "constant.h"

namespace operational
{
namespace interpreter
{
Constant::Constant(const bool& value)
{
	value_ = value;
}

bool Constant::Evaluate(InterpreterContextInterface& context)
{
	return value_;
}

BooleanExpInterface *Constant::Replace(const std::string& name, BooleanExpInterface& expression)
{
	return expression.Copy();
}

BooleanExpInterface *Constant::Copy() const
{
	return new Constant(value_);
}
}}
