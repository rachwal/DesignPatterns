// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "cabinet.h"

namespace structural
{
	Cabinet::Cabinet(const std::string& name) :CompositeEquipment(name)
	{
	}

	Cabinet::Cabinet() : Cabinet("")
	{
	}
}
