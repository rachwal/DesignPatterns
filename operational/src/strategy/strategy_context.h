// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_STRATEGY_CONTEXT_H_
#define OPERATIONAL_STRATEGY_CONTEXT_H_

namespace operational
{
namespace strategy
{
template<class AStrategy>
class StrategyContext
{
	public:
	void Operation()
	{
		result_ = strategy_.DoAlgorithm();
	}

	std::string result() const;

	private:
	std::string result_;
	AStrategy strategy_;
};

template<class AStrategy>
std::string StrategyContext<AStrategy>::result() const
{
	return result_;
}
}
}

#endif

