// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_STRATEGY_MY_STRATEGY_H_
#define OPERATIONAL_STRATEGY_MY_STRATEGY_H_

#include <string>

namespace operational
{
namespace strategy
{
class MyStrategy
{
	public:
	static std::string DoAlgorithm();
};
}
}

#endif

