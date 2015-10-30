// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "risc_code_generator.h"
#include <sstream>

namespace structural
{
namespace facade
{
RISCCodeGenerator::RISCCodeGenerator(BytecodeStream* stream) : output_(stream) { }

void RISCCodeGenerator::Visit(VariableNodeInterface* variable_node)
{
	auto name = variable_node->name();

	std::ostringstream stream;
	stream << "<RISC|variable|" << name << "|variable|RISC>";

	output_->Write(stream.str());
}

void RISCCodeGenerator::Visit(StatementNodeInterface* statne_node)
{
	auto statement = statne_node->statement();

	std::ostringstream stream;
	stream << "<RISC|statement|" << statement << "|statement|RISC>";

	output_->Write(stream.str());
}

void RISCCodeGenerator::Visit(ExpressionNodeInterface* expression_node)
{
	auto expression = expression_node->expression();

	std::ostringstream stream;
	stream << "<RISC|expression|" << expression << "|expression|RISC>";

	output_->Write(stream.str());
}
}}
