// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_INTERPRETER_VARIABLE_EXP_H_
#define OPERATIONAL_INTERPRETER_VARIABLE_EXP_H_

#include "boolean_exp_interface.h"
#include "variable_exp_interface.h"

namespace operational
{
namespace interpreter
{
class VariableExp : public BooleanExpInterface, public VariableExpInterface
{
	public:
	explicit VariableExp(const std::string& name);

	virtual bool Evaluate(InterpreterContextInterface& context) override;
	virtual BooleanExpInterface *Replace(const std::string& name, BooleanExpInterface& expression) override;
	virtual BooleanExpInterface *Copy() const override;

	virtual std::string name() const override;

	private:
	std::string name_;
};
}}

#endif
