// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_INTERPRETER_INTERPRETER_CONTEXT_INTERFACE_H_
#define OPERATIONAL_INTERPRETER_INTERPRETER_CONTEXT_INTERFACE_H_

#include "variable_exp_interface.h"

#include <string>

namespace operational
{
namespace interpreter
{
class InterpreterContextInterface
{
	public:
	virtual ~InterpreterContextInterface() { }

	virtual void Assign(VariableExpInterface* expression, bool) = 0;
	virtual bool Lookup(const std::string& name) const = 0;
};
}}

#endif
