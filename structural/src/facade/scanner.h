// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FACADE_SCANNER_H_
#define STRUCTURAL_FACADE_SCANNER_H_

#include "token.h"

#include <sstream>
#include <vector>

namespace structural
{
namespace facade
{
class Scanner
{
	public:
	explicit Scanner(std::istringstream&);
	virtual ~Scanner();

	virtual std::vector<Token*> Scanner::Scan();

	private:
	std::istringstream& input_stream_;
};
}}

#endif
