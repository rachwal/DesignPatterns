// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_VISITOR_INVENTORY_VISITOR_H_
#define OPERATIONAL_VISITOR_INVENTORY_VISITOR_H_

#include "inventory.h"

namespace operational
{
namespace visitor
{
class InventoryVisitor : public EquipmentVisitorInterface
{
	public:
	InventoryVisitor();

	Inventory *GetInventory() const;

	virtual void VisitFloppyDisk(FloppyDiskInterface*) override;
	virtual void VisitCard(CardInterface*) override;
	virtual void VisitChassis(ChassisInterface*) override;
	virtual void VisitBus(BusInterface*) override;

	private:
	Inventory* inventory_;
};
}
}

#endif

