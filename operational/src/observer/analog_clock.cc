// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "analog_clock.h"

#include <ostream>
#include <sstream>

namespace operational
{
namespace observer
{
AnalogClock::AnalogClock(ClockTimer* clock_timer) : clock_timer_(clock_timer)
{
	clock_timer_->Attach(this);
}

AnalogClock::~AnalogClock()
{
	clock_timer_->Detach(this);
}

void AnalogClock::OnClockTick()
{
	Draw();
}

void AnalogClock::Draw()
{
	auto hours = clock_timer_->GetHours();
	auto minutes = clock_timer_->GetMinutes();

	std::ostringstream stringStream;
	stringStream << hours << "/" << minutes;
	formated_time_ = stringStream.str();
}

std::string AnalogClock::formated_time() const
{
	return formated_time_;
}
}}
