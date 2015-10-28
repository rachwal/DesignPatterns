// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "expression_node.h"

#include "../../../Operational/src/iterator/list_iterator.h"

namespace structural
{
	ExpressionNode::ExpressionNode()
	{
		children_ = new operational::List<ProgramNodeInterface*>(10);
	}

	void ExpressionNode::GetSourcePosition(int& line, int& index)
	{
	}

	void ExpressionNode::Add(ProgramNodeInterface* node)
	{
		children_->Append(node);
	}

	void ExpressionNode::Remove(ProgramNodeInterface* node)
	{
		children_->Remove(node);
	}

	void ExpressionNode::Traverse(CodeGeneratorInterface& cg)
	{
		cg.Visit(this);
		operational::ListIterator<ProgramNodeInterface*> i(children_);

		for (i.First(); !i.IsDone(); i.Next())
		{
			i.CurrentItem()->Traverse(cg);
		}
	}
}
