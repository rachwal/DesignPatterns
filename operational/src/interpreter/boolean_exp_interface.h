// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_INTERPRETER_BOOLEAN_EXP_INTERFACE_H_
#define OPERATIONAL_INTERPRETER_BOOLEAN_EXP_INTERFACE_H_

#include "interpreter_context_interface.h"

#include <string>

namespace operational
{
namespace interpreter
{
class BooleanExpInterface
{
	public:
	virtual ~BooleanExpInterface() { };

	virtual bool Evaluate(InterpreterContextInterface& context) = 0;
	virtual BooleanExpInterface *Replace(const std::string& name, BooleanExpInterface& expression) = 0;
	virtual BooleanExpInterface *Copy() const = 0;
};
}}

#endif
