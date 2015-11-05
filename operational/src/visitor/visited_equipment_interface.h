// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_VISITOR_VISITED_EQUIPMENT_INTERFACE_H_
#define OPERATIONAL_VISITOR_VISITED_EQUIPMENT_INTERFACE_H_

#include "equipment_visitor_interface.h"

#include <string>

namespace operational
{
namespace visitor
{
class VisitedEquipmentInterface
{
	public:
	virtual ~VisitedEquipmentInterface() { }

	virtual std::string name() const = 0;

	virtual double price() const = 0;
	virtual void price(const double&) = 0;

	virtual void Accept(EquipmentVisitorInterface&) = 0;
};
}
}

#endif

