// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FACADE_PROGRAM_NODE_INTERFACE_H_
#define STRUCTURAL_FACADE_PROGRAM_NODE_INTERFACE_H_

#include "code_generator_interface.h"

namespace structural
{
namespace facade
{
class ProgramNodeInterface
{
	public:
	virtual ~ProgramNodeInterface() { }

	virtual void GetSourcePosition(int& line, int& index) = 0;
	virtual void Add(ProgramNodeInterface*) = 0;
	virtual void Remove(ProgramNodeInterface*) = 0;

	virtual void Traverse(CodeGeneratorInterface&) = 0;
};
}
}

#endif

