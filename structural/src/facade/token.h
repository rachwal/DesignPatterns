// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FACADE_TOKEN_H_
#define STRUCTURAL_FACADE_TOKEN_H_

#include <string>

namespace structural
{
namespace facade
{
class Token
{
	public:
	explicit Token(const std::string& content);

	std::string content() const;

	private:
	std::string content_;
};
}
}

#endif

