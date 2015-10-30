// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_COMPOSITE_CABINET_H_
#define STRUCTURAL_COMPOSITE_CABINET_H_

#include "composite_equipment.h"

namespace structural
{
namespace composite
{
class Cabinet : public CompositeEquipment
{
	public:
	Cabinet();
	explicit Cabinet(const std::string& name);
};
}}

#endif
