// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_OBSERVER_CLOCK_TICK_INTERFACE_H_
#define OPERATIONAL_OBSERVER_CLOCK_TICK_INTERFACE_H_

#include "clock_tick_observer.h"

namespace operational
{
namespace observer
{
class ClockTickInterface
{
	public:
	virtual ~ClockTickInterface() { }

	virtual void Attach(ClockTickObserver*) = 0;
	virtual void Detach(ClockTickObserver*) = 0;
	virtual void Notify() = 0;
};
}
}

#endif

