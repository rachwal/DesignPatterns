// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_OBSERVER_CLOCK_TICK_H_
#define OPERATIONAL_OBSERVER_CLOCK_TICK_H_

#include "clock_tick_observer.h"
#include "clock_tick_interface.h"

#include "../iterator/list.h"

namespace operational
{
namespace observer
{
class ClockTick : public ClockTickInterface
{
	public:
	ClockTick();
	~ClockTick() override;

	virtual void Attach(ClockTickObserver*) override;
	virtual void Detach(ClockTickObserver*) override;
	virtual void Notify() override;

	private:
	iterator::List<ClockTickObserver*>* observers_;
};
}
}

#endif

