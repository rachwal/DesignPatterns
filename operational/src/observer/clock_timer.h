// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_OBSERVER_CLOCK_TIMER_H_
#define OPERATIONAL_OBSERVER_CLOCK_TIMER_H_

#include "clock_tick_observer.h"
#include "clock_tick.h"

namespace operational
{
namespace observer
{
class ClockTimer
{
	public:
	ClockTimer();

	virtual ~ClockTimer();

	virtual int GetHours();
	virtual int GetMinutes();
	virtual int GetSeconds();

	void Tick();

	void Attach(ClockTickObserver* observer_interface) const;
	void Detach(ClockTickObserver* observer_interface) const;

	private:
	int hours_;
	int minutes_;
	int seconds_;

	ClockTick* clock_tick_;
};
}}

#endif
