// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "chassis.h"

namespace structural
{
namespace composite
{
Chassis::Chassis(const std::string& name) : CompositeEquipment(name) { }

Chassis::Chassis() : Chassis("") { }
}
}

