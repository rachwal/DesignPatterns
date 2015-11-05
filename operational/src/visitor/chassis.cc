// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "chassis.h"

namespace operational
{
namespace visitor
{
Chassis::Chassis(const std::string& name) : name_(name), price_(0)
{
	parts_ = new iterator::List<VisitedEquipmentInterface*>();
}

Chassis::~Chassis()
{
	delete parts_;
}

std::string Chassis::name() const
{
	return name_;
}

double Chassis::price() const
{
	return price_;
}

void Chassis::price(const double& price)
{
	price_ = price;
}

double Chassis::GetPrice()
{
	return price();
}

void Chassis::Accept(EquipmentVisitorInterface& visitor)
{
	for (iterator::ListIterator<VisitedEquipmentInterface*> i(parts_); !i.IsDone(); i.Next())
	{
		i.CurrentItem()->Accept(visitor);
	}
	visitor.VisitChassis(this);
}

void Chassis::AddPart(VisitedEquipmentInterface* part) const
{
	parts_->Append(part);
}
}
}

