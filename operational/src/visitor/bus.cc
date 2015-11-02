// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "bus.h"

namespace operational
{
namespace visitor
{
Bus::Bus(const std::string& name) :name_(name), price_(0) {}

std::string Bus::name() const
{
	return name_;
}

double Bus::price() const
{
	return price_;
}

void Bus::price(const double& price)
{
	price_ = price;
}

double Bus::GetLuxPrice()
{
	return 3.0 * price();
}

double Bus::GetRegularPrice()
{
	return 2.0 * price();
}

void Bus::Accept(EquipmentVisitorInterface& visitor)
{
	visitor.VisitBus(this);
}
}}
