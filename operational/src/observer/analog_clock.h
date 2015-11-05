// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_OBSERVER_ANALOG_CLOCK_H_
#define OPERATIONAL_OBSERVER_ANALOG_CLOCK_H_

#include "observer_widget_interface.h"
#include "clock_tick_observer.h"
#include "clock_timer.h"

#include <string>

namespace operational
{
namespace observer
{
class AnalogClock : public ObserverWidgetInterface, public ClockTickObserver
{
	public:
	explicit AnalogClock(ClockTimer* clock_timer);
	virtual ~AnalogClock() override;

	virtual void OnClockTick() override;

	virtual void Draw() override;

	std::string formated_time() const;

	private:
	ClockTimer* clock_timer_;
	std::string formated_time_;
};
}
}

#endif

