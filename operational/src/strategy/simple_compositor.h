// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_STRATEGY_SIMPLE_COMPOSITOR_H_
#define OPERATIONAL_STRATEGY_SIMPLE_COMPOSITOR_H_

#include "compositor_interface.h"

namespace operational
{
namespace strategy
{
class SimpleCompositor : public CompositorInterface
{
	public:
	virtual int Compose(float natural[], float stretch[], float shrink[], int componentCount, int lineWidth, int breaks[]) override;
};
}
}

#endif

