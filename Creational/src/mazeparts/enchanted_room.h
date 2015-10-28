// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEPARTS_ENCHANTED_ROOM_H_
#define CREATIONAL_MAZEPARTS_ENCHANTED_ROOM_H_

#include "room.h"
#include "spell.h"

namespace creational
{
	class EnchantedRoom : public Room
	{
	public:
		explicit EnchantedRoom(const int& room_number, const Spell& spell);
		EnchantedRoom(const EnchantedRoom&);

		EnchantedRoom* Clone() const override;
		bool HasSpell() const;
		void Initialize(const Spell& spell);
		Spell PickUpSpell() const;

	private:
		Spell* spell_;
	};
}

#endif
