// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "bus.h"

namespace structural
{
	Bus::Bus(const std::string& name) : CompositeEquipment(name)
	{
	}

	Bus::Bus() : Bus("")
	{
	}
}
