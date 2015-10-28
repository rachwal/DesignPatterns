// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FACADE_CODE_GENERATOR_INTERFACE_H_
#define STRUCTURAL_FACADE_CODE_GENERATOR_INTERFACE_H_

#include "expression_node_interface.h"
#include "statement_node_interface.h"
#include "variable_node_interface.h"

namespace structural
{
	class CodeGeneratorInterface
	{
	public:
		virtual ~CodeGeneratorInterface()
		{
		}

		virtual void Visit(VariableNodeInterface*) = 0;
		virtual void Visit(ExpressionNodeInterface*) = 0;
		virtual void Visit(StatementNodeInterface*) = 0;
	};
}

#endif
