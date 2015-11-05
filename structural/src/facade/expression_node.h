// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FACADE_EXPRESSION_NODE_H_
#define STRUCTURAL_FACADE_EXPRESSION_NODE_H_

#include "program_node_interface.h"
#include "expression_node_interface.h"

#include "../../../Operational/src/iterator/list.h"

namespace structural
{
namespace facade
{
class ExpressionNode : public ProgramNodeInterface, public ExpressionNodeInterface
{
	public:
	ExpressionNode();

	virtual void GetSourcePosition(int& line, int& index) override;

	virtual void Add(ProgramNodeInterface*) override;
	virtual void Remove(ProgramNodeInterface*) override;

	virtual void Traverse(CodeGeneratorInterface&) override;

	protected:
	operational::iterator::List<ProgramNodeInterface*>* children_;
};
}
}

#endif

