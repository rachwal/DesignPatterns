// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "program_node_builder.h"
#include "variable_node.h"

namespace structural
{
	ProgramNodeBuilder::ProgramNodeBuilder()
	{
		node_ = nullptr;
	}

	ProgramNodeBuilder::~ProgramNodeBuilder()
	{
	}

	ProgramNodeInterface* ProgramNodeBuilder::NewVariable(std::string& variable_name)
	{
		auto variable_node = new VariableNode(variable_name);
		if (!node_)
		{
			node_ = variable_node;
		}
		else
		{
			node_->Add(variable_node);
		}
		return variable_node;
	}

	ProgramNodeInterface* ProgramNodeBuilder::NewAssignment(ProgramNodeInterface* variable, ProgramNodeInterface* expression)
	{
		return nullptr;
	}

	ProgramNodeInterface* ProgramNodeBuilder::NewReturnStatement(ProgramNodeInterface* value)
	{
		return nullptr;
	}

	ProgramNodeInterface* ProgramNodeBuilder::NewCondition(ProgramNodeInterface* condition, ProgramNodeInterface* truePart, ProgramNodeInterface* falsePart)
	{
		return nullptr;
	}

	ProgramNodeInterface* ProgramNodeBuilder::GetRootNode() const
	{
		return node_;
	}
}
