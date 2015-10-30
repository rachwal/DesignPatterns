// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "token.h"

namespace structural
{
namespace facade
{
Token::Token(const std::string& content) : content_(content) { }

std::string Token::content() const
{
	return content_;
}
}}
