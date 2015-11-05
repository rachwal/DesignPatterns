// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../creational/src/mazeparts/room.h"
#include "../../../creational/src/mazeparts/door_needing_spell.h"

namespace creationaltests
{
using namespace creational::commons;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(DoorNeedingSpellTest)
{
	public:
	DoorNeedingSpellTest() { }

	~DoorNeedingSpellTest() { }

	TEST_METHOD(ShouldReturnFalseWhenTryEmptySpell)
	{
		//GIVEN
		auto east_room = Room(1);
		auto west_room = Room(2);
		auto door_needing_spell = DoorNeedingSpell(east_room, west_room);
		Spell spell("");

		//WHEN
		auto result = door_needing_spell.TrySpell(spell);

		//THEN
		Assert::IsFalse(result);
	}

	TEST_METHOD(ShouldReturnTrueWhenTryNonEmptySpell)
	{
		//GIVEN
		auto east_room = Room(1);
		auto west_room = Room(2);
		auto door_needing_spell = DoorNeedingSpell(east_room, west_room);
		Spell spell("abracadabra");

		//WHEN
		auto result = door_needing_spell.TrySpell(spell);

		//THEN
		Assert::IsTrue(result);
	}
};
}

