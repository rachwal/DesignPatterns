// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "enchanted_room.h"

namespace creational
{
	EnchantedRoom::EnchantedRoom(const int& room_number, const Spell& spell) :Room(room_number)
	{
		spell_ = new Spell(spell);
	}

	EnchantedRoom::EnchantedRoom(const EnchantedRoom& room) : Room(room.room_number_), spell_(room.spell_)
	{
	}

	EnchantedRoom* EnchantedRoom::Clone() const
	{
		return new EnchantedRoom(*this);
	}

	bool EnchantedRoom::HasSpell() const
	{
		if (spell_)
		{
			return true;
		}
		return false;
	}

	void EnchantedRoom::Initialize(const Spell& spell)
	{
		spell_ = new Spell(spell);
	}

	Spell EnchantedRoom::PickUpSpell() const
	{
		return *spell_;
	}
}
