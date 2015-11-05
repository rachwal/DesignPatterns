// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "parser.h"

namespace structural
{
namespace facade
{
Parser::Parser() { }

Parser::~Parser() { }

void Parser::Parse(Scanner& scanner, ProgramNodeBuilder& builder)
{
	auto tokens = scanner.Scan();

	for (auto token = tokens.begin(); token != tokens.end(); ++token)
	{
		auto content = (*token)->content();
		if (content.compare("auto") == 0)
		{
			++token;
			auto variable = (*token)->content();
			builder.NewVariable(variable);
		}
	}
}
}
}

