// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "digital_clock.h"

#include <sstream>

namespace operational
{
	DigitalClock::DigitalClock(ClockTimer* clock_timer) :clock_timer_(clock_timer)
	{
		clock_timer_->Attach(this);
	}

	DigitalClock::~DigitalClock()
	{
		clock_timer_->Detach(this);
	}

	void DigitalClock::OnClockTick()
	{
		Draw();
	}

	void DigitalClock::Draw()
	{
		auto hours = clock_timer_->GetHours();
		auto minutes = clock_timer_->GetMinutes();
		auto seconds = clock_timer_->GetSeconds();

		std::ostringstream stringStream;
		stringStream << hours << ":" << minutes << ":" << seconds;

		formated_time_ = stringStream.str();
	}

	std::string DigitalClock::formated_time() const
	{
		return formated_time_;
	}
}
