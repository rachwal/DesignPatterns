// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "interpreter_context.h"

namespace operational
{
namespace interpreter
{
InterpreterContext::InterpreterContext()
{
	variables_ = new std::map<std::string, bool>();
}

bool InterpreterContext::Lookup(const std::string& name) const
{
	return variables_->operator[](name);
}

void InterpreterContext::Assign(VariableExpInterface* expression, bool value)
{
	auto name = expression->name();
	variables_->operator[](name) = value;
}
}}
