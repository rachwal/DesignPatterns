// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_VISITOR_EQUIPMENT_VISITOR_INTERFACE_H_
#define OPERATIONAL_VISITOR_EQUIPMENT_VISITOR_INTERFACE_H_

#include "floppy_disk_interface.h"
#include "card_interface.h"
#include "chassis_interface.h"
#include "bus_interface.h"

namespace operational
{
namespace visitor
{
class EquipmentVisitorInterface
{
	public:
	virtual ~EquipmentVisitorInterface() {};

	virtual void VisitFloppyDisk(FloppyDiskInterface*) = 0;
	virtual void VisitCard(CardInterface*) = 0;
	virtual void VisitChassis(ChassisInterface*) = 0;
	virtual void VisitBus(BusInterface*) = 0;
};
}}

#endif
