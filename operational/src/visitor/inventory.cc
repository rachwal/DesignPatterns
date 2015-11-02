// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "inventory.h"

namespace operational
{
namespace visitor
{
Inventory::Inventory() :count_(0) {}

Inventory::Inventory(const Inventory& inventory) : count_(inventory.count_) {}

void Inventory::Accumulate(VisitedEquipmentInterface* equipment)
{
	count_++;
}

int Inventory::count() const
{
	return count_;
}
}}
