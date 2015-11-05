// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "door_needing_spell.h"

namespace creational
{
namespace commons
{
DoorNeedingSpell::DoorNeedingSpell(const Room& first_room, const Room& second_room) : Door(first_room, second_room) { }

DoorNeedingSpell::DoorNeedingSpell(const DoorNeedingSpell& door_needing_spell) : Door(door_needing_spell) { }

bool DoorNeedingSpell::TrySpell(const Spell& spell)
{
	if (spell.message() == "")
	{
		return false;
	}
	return true;
}
}
}

