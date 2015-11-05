// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_STRATEGY_COMPOSITOR_INTERFACE_H_
#define OPERATIONAL_STRATEGY_COMPOSITOR_INTERFACE_H_

namespace operational
{
namespace strategy
{
class CompositorInterface
{
	public:
	virtual ~CompositorInterface() {}

	virtual int Compose(float natural[], float stretch[], float shrink[], int componentCount, int lineWidth, int breaks[]) = 0;
};
}
}

#endif

