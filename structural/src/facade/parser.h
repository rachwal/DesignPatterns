// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FACADE_PARSER_H_
#define STRUCTURAL_FACADE_PARSER_H_

#include "program_node_builder.h"
#include "scanner.h"

namespace structural
{
namespace facade
{
class Parser
{
	public:
	Parser();
	virtual ~Parser();

	virtual void Parse(Scanner&, ProgramNodeBuilder&);
};
}}

#endif
