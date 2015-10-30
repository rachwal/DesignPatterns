// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FACADE_PROGRAM_NODE_BUILDER_H_
#define STRUCTURAL_FACADE_PROGRAM_NODE_BUILDER_H_

#include "program_node_builder_interface.h"

namespace structural
{
namespace facade
{
class ProgramNodeBuilder :public ProgramNodeBuilderInterface
{
	public:
	ProgramNodeBuilder();
	virtual ~ProgramNodeBuilder();

	virtual ProgramNodeInterface *NewVariable(std::string& variableName) override;
	virtual ProgramNodeInterface *NewAssignment(ProgramNodeInterface* variable, ProgramNodeInterface* expression) override;
	virtual ProgramNodeInterface *NewReturnStatement(ProgramNodeInterface* value) override;
	virtual ProgramNodeInterface *NewCondition(ProgramNodeInterface* condition, ProgramNodeInterface* truePart, ProgramNodeInterface* falsePart) override;
	virtual ProgramNodeInterface *GetRootNode() const override;

	private:
	ProgramNodeInterface* node_;
};
}}

#endif
