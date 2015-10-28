// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef FOUNDATION_FOUNDATION_EQUIPMENT_INTERFACE_H_
#define FOUNDATION_FOUNDATION_EQUIPMENT_INTERFACE_H_

#include "watt.h"
#include "currency.h"

#include <string>

namespace foundation
{
	class EquipmentInterface
	{
	public:
		virtual ~EquipmentInterface()
		{
		}

		virtual std::string name() const = 0;

		virtual Currency price() const = 0;
		virtual void price(const Currency&) = 0;

		virtual Watt power() const = 0;
		virtual void power(const Watt&) = 0;

		virtual Currency NetPrice() = 0;
		virtual Currency DiscountPrice() = 0;
	};
}

#endif
