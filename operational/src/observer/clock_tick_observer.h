// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_OBSERVER_CLOCK_TICK_OBSERVER_H_
#define OPERATIONAL_OBSERVER_CLOCK_TICK_OBSERVER_H_

namespace operational
{
	class ClockTickObserver
	{
	public:
		virtual ~ClockTickObserver()
		{
		}

		virtual void OnClockTick() = 0;
	};
}

#endif
