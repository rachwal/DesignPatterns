// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_COMPOSITE_EQUIPMENT_INTERFACE_H_
#define STRUCTURAL_COMPOSITE_EQUIPMENT_INTERFACE_H_

#include "watt.h"
#include "currency.h"

#include <string>

namespace structural
{
namespace composite
{
class EquipmentInterface
{
	public:
	virtual ~EquipmentInterface() { }

	virtual std::string name() const = 0;

	virtual Currency price() const = 0;
	virtual void price(const Currency&) = 0;

	virtual Watt power() const = 0;
	virtual void power(const Watt&) = 0;

	virtual Currency NetPrice() = 0;
	virtual Currency DiscountPrice() = 0;
};
}}

#endif
