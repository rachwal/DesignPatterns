// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEPARTS_DOOR_NEEDING_SPELL_H_
#define CREATIONAL_MAZEPARTS_DOOR_NEEDING_SPELL_H_

#include "door.h"
#include "room.h"
#include "spell.h"

namespace creational
{
namespace commons
{
class DoorNeedingSpell : public Door
{
	public:
	DoorNeedingSpell(const DoorNeedingSpell&);
	DoorNeedingSpell(const Room& first_room, const Room& second_room);

	bool TrySpell(const Spell&) const;
};
}}

#endif
