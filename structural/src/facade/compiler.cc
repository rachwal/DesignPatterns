// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "compiler.h"
#include "scanner.h"
#include "program_node_builder.h"
#include "parser.h"
#include "risc_code_generator.h"

namespace structural
{
	Compiler::Compiler()
	{
	}

	Compiler::~Compiler()
	{
	}

	void Compiler::Compile(std::istringstream& input, BytecodeStream* output)
	{
		Scanner scanner(input);
		Parser parser;
		ProgramNodeBuilder builder;
		RISCCodeGenerator generator(output);

		parser.Parse(scanner, builder);
		auto parseTree = builder.GetRootNode();
		if (parseTree)
		{
			parseTree->Traverse(generator);
		}
	}
}
