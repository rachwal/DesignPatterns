// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "currency.h"

namespace structural
{
namespace composite
{
Currency::Currency(const double& price) : value_(price) { }

double Currency::value() const
{
	return value_;
}

void Currency::value(double value)
{
	value_ = value;
}
}
}

