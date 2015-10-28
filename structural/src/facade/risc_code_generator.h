// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FACADE_RISC_CODE_GENERATOR_H_
#define STRUCTURAL_FACADE_RISC_CODE_GENERATOR_H_

#include "bytecode_stream.h"
#include "code_generator_interface.h"

namespace structural
{
	class RISCCodeGenerator : public CodeGeneratorInterface
	{
	public:
		explicit RISCCodeGenerator(BytecodeStream*);

		virtual void Visit(VariableNodeInterface*) override;
		virtual void Visit(StatementNodeInterface*) override;
		virtual void Visit(ExpressionNodeInterface*) override;

	private:
		BytecodeStream* output_;
	};
}

#endif
