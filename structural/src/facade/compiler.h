// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FACADE_COMPILER_H_
#define STRUCTURAL_FACADE_COMPILER_H_

#include "bytecode_stream.h"

#include <istream>

namespace structural
{
namespace facade
{
class Compiler
{
	public:
	Compiler();
	virtual ~Compiler();

	virtual void Compile(std::istringstream&, BytecodeStream*);
};
}}

#endif
