// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_INTERPRETER_VARIABLE_EXP_INTERFACE_H_
#define OPERATIONAL_INTERPRETER_VARIABLE_EXP_INTERFACE_H_

#include <string>

namespace operational
{
namespace interpreter
{
class VariableExpInterface
{
	public:
	virtual ~VariableExpInterface() {}

	virtual std::string name() const = 0;
};
}
}

#endif

