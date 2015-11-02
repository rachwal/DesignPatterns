// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "floppy_disk.h"

namespace operational
{
namespace visitor
{
FloppyDisk::FloppyDisk(const std::string& name) :name_(name), price_(0) {}

std::string FloppyDisk::name() const
{
	return name_;
}

double FloppyDisk::price() const
{
	return price_;
}

void FloppyDisk::price(const double& price)
{
	price_ = price;
}

double FloppyDisk::GetBoxPrice()
{
	return 5 * price();
}

void FloppyDisk::Accept(EquipmentVisitorInterface& visitor)
{
	visitor.VisitFloppyDisk(this);
}
}}
