// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "variable_node.h"

namespace structural
{
namespace facade
{
VariableNode::VariableNode(const std::string name) :name_(name)
{
	children_ = new operational::iterator::List<ProgramNodeInterface*>();
}

void VariableNode::GetSourcePosition(int& line, int& index) { }

void VariableNode::Add(ProgramNodeInterface* program_node)
{
	children_->Append(program_node);
}

void VariableNode::Remove(ProgramNodeInterface* program_node)
{
	children_->Remove(program_node);
}

void VariableNode::Traverse(CodeGeneratorInterface& code_generator)
{
	operational::iterator::ListIterator<ProgramNodeInterface*> i(children_);

	for (i.First(); !i.IsDone(); i.Next())
	{
		i.CurrentItem()->Traverse(code_generator);
	}

	code_generator.Visit(this);
}

std::string VariableNode::name() const
{
	return name_;
}
}}
