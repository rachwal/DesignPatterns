// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "or_exp.h"

namespace operational
{
namespace interpreter
{
OrExp::OrExp(BooleanExpInterface* left_operand, BooleanExpInterface* right_operand)
{
	left_operand_ = left_operand;
	right_operand_ = right_operand;
}

bool OrExp::Evaluate(InterpreterContextInterface& context)
{
	return left_operand_->Evaluate(context) || right_operand_->Evaluate(context);
}

BooleanExpInterface *OrExp::Copy() const
{
	return new OrExp(left_operand_->Copy(), right_operand_->Copy());
}

BooleanExpInterface *OrExp::Replace(const std::string& name, BooleanExpInterface& expression)
{
	return new OrExp(left_operand_->Replace(name, expression), right_operand_->Replace(name, expression));
}
}}
