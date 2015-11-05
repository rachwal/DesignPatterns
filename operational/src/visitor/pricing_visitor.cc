// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "pricing_visitor.h"

namespace operational
{
namespace visitor
{
PricingVisitor::PricingVisitor() : total_(0) {}

double PricingVisitor::GetTotalPrice() const
{
	return total_;
}

void PricingVisitor::VisitFloppyDisk(FloppyDiskInterface* floppy)
{
	auto price = floppy->GetBoxPrice();
	total_ += price;
}

void PricingVisitor::VisitCard(CardInterface* card)
{
	auto price = card->GetGoldPrice();
	total_ += price;
}

void PricingVisitor::VisitChassis(ChassisInterface* chassis)
{
	auto price = chassis->GetPrice();
	total_ += price;
}

void PricingVisitor::VisitBus(BusInterface* bus)
{
	auto price = bus->GetLuxPrice();
	total_ += price;
}
}
}

