// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "clock_timer.h"

namespace operational
{
namespace observer
{
ClockTimer::ClockTimer() : hours_(0), minutes_(0), seconds_(0)
{
	clock_tick_ = new ClockTick();
}

ClockTimer::~ClockTimer() { }

int ClockTimer::GetHours()
{
	return hours_;
}

int ClockTimer::GetMinutes()
{
	return minutes_;
}

int ClockTimer::GetSeconds()
{
	return seconds_;
}

void ClockTimer::Tick()
{
	seconds_ += 15;
	if (seconds_ >= 60)
	{
		seconds_ = seconds_ % 60;
		minutes_++;
	}
	if (minutes_ >= 60)
	{
		minutes_ = minutes_ % 60;
		hours_++;
	}
	clock_tick_->Notify();
}

void ClockTimer::Attach(ClockTickObserver* observer_interface) const
{
	clock_tick_->Attach(observer_interface);
}

void ClockTimer::Detach(ClockTickObserver* observer_interface) const
{
	clock_tick_->Detach(observer_interface);
}
}
}

