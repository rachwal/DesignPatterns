// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_VISITOR_INVENTORY_H_
#define OPERATIONAL_VISITOR_INVENTORY_H_

#include "visited_equipment_interface.h"

namespace operational
{
namespace visitor
{
class Inventory
{
	public:
	Inventory();
	Inventory(const Inventory&);

	void Accumulate(VisitedEquipmentInterface*);
	int count() const;

	private:
	int count_;
};
}
}

#endif

