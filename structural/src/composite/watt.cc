// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "watt.h"

namespace structural
{
namespace composite
{
Watt::Watt(const double& value) : value_(value) { }

double Watt::value() const
{
	return value_;
}

void Watt::value(double value)
{
	value_ = value;
}
}
}

