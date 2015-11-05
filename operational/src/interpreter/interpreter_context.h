// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_INTERPRETER_INTERPRETER_CONTEXT_H_
#define OPERATIONAL_INTERPRETER_INTERPRETER_CONTEXT_H_

#include "interpreter_context_interface.h"

#include <map>

namespace operational
{
namespace interpreter
{
class InterpreterContext :public InterpreterContextInterface
{
	public:
	InterpreterContext();

	virtual void Assign(VariableExpInterface* expression, bool) override;
	virtual bool Lookup(const std::string& name) const override;

	private:
	std::map<std::string, bool>* variables_;
};
}
}

#endif

