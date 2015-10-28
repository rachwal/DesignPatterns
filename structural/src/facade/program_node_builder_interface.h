// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FACADE_PROGRAM_NODE_BUILDER_INTERFACE_H_
#define STRUCTURAL_FACADE_PROGRAM_NODE_BUILDER_INTERFACE_H_

#include "program_node_interface.h"

#include <string>

namespace structural
{
	class ProgramNodeBuilderInterface
	{
	public:
		virtual ~ProgramNodeBuilderInterface()
		{
		}

		virtual ProgramNodeInterface* NewVariable(std::string& variableName) = 0;
		virtual ProgramNodeInterface* NewAssignment(ProgramNodeInterface* variable, ProgramNodeInterface* expression) = 0;
		virtual ProgramNodeInterface* NewReturnStatement(ProgramNodeInterface* value) = 0;
		virtual ProgramNodeInterface* NewCondition(ProgramNodeInterface* condition, ProgramNodeInterface* truePart, ProgramNodeInterface* falsePart) = 0;
		virtual ProgramNodeInterface* GetRootNode() const = 0;
	};
}

#endif
