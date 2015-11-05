// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "inventory_visitor.h"

namespace operational
{
namespace visitor
{
InventoryVisitor::InventoryVisitor() : inventory_(new Inventory()) {}

Inventory *InventoryVisitor::GetInventory() const
{
	return new Inventory(*inventory_);
}

void InventoryVisitor::VisitFloppyDisk(FloppyDiskInterface*)
{
	inventory_->Accumulate(nullptr);
}

void InventoryVisitor::VisitCard(CardInterface*)
{
	inventory_->Accumulate(nullptr);
}

void InventoryVisitor::VisitChassis(ChassisInterface*)
{
	inventory_->Accumulate(nullptr);
}

void InventoryVisitor::VisitBus(BusInterface*)
{
	inventory_->Accumulate(nullptr);
}
}
}

