// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "clock_tick.h"

#include "../iterator/list_iterator.h"

namespace operational
{
namespace observer
{
ClockTick::ClockTick()
{
	observers_ = new iterator::List<ClockTickObserver*>();
}

ClockTick::~ClockTick()
{
	delete observers_;
}

void ClockTick::Attach(ClockTickObserver* o)
{
	observers_->Append(o);
}

void ClockTick::Detach(ClockTickObserver* o)
{
	observers_->Remove(o);
}

void ClockTick::Notify()
{
	iterator::ListIterator<ClockTickObserver*> i(observers_);

	for (i.First(); !i.IsDone(); i.Next())
	{
		auto current_item = i.CurrentItem();
		current_item->OnClockTick();
	}
}
}}
