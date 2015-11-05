// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Creational/src/mazeparts/spell.h"
#include "../../../Creational/src/mazeparts/enchanted_room.h"

namespace creationaltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace creational::commons;

TEST_CLASS(EnchantedRoomTest)
{
	public:
	EnchantedRoomTest() { }

	~EnchantedRoomTest() { }

	TEST_METHOD(ShouldCreateEnchantedRoom)
	{
		//GIVEN
		auto expected_message = "abracadabra";
		auto expected_room_number = 11;
		Spell expected_spell(expected_message);

		//WHEN
		auto enchanted_room = EnchantedRoom(expected_room_number, expected_spell);

		//THEN
		auto room_number = enchanted_room.room_number();
		auto spell = enchanted_room.PickUpSpell();
		auto has_spell = enchanted_room.HasSpell();

		Assert::AreEqual(expected_room_number, room_number);
		Assert::IsTrue(has_spell);
		Assert::AreEqual(expected_message, spell.message().c_str());
	}

	TEST_METHOD(ShouldCreateEnchantedRoomFromAnotherEnchantedRoom)
	{
		//GIVEN
		auto expected_message = "abracadabra";
		auto expected_room_number = 11;
		Spell expected_spell(expected_message);
		auto existing_enchanted_room = EnchantedRoom(expected_room_number, expected_spell);

		//WHEN
		auto enchanted_room = EnchantedRoom(existing_enchanted_room);

		//THEN
		auto room_number = enchanted_room.room_number();
		auto spell = enchanted_room.PickUpSpell();
		auto has_spell = enchanted_room.HasSpell();

		Assert::AreEqual(expected_room_number, room_number);
		Assert::IsTrue(has_spell);
		Assert::AreEqual(expected_message, spell.message().c_str());
	}

	TEST_METHOD(ShouldCloneEnchantedRoom)
	{
		//GIVEN
		auto expected_message = "abracadabra";
		auto expected_room_number = 11;
		Spell expected_spell(expected_message);
		auto existing_enchanted_room = EnchantedRoom(expected_room_number, expected_spell);

		//WHEN
		auto enchanted_room = existing_enchanted_room.Clone();

		//THEN
		auto room_number = enchanted_room->room_number();
		auto spell = enchanted_room->PickUpSpell();
		auto has_spell = enchanted_room->HasSpell();

		Assert::AreEqual(expected_room_number, room_number);
		Assert::IsTrue(has_spell);
		Assert::AreEqual(expected_message, spell.message().c_str());
	}

	TEST_METHOD(ShouldInitializeEnchantedRoom)
	{
		//GIVEN
		auto expected_room_number = 11;
		Spell spell("");
		auto enchanted_room = EnchantedRoom(expected_room_number, spell);

		//WHEN
		Spell new_spell("abracadabra");
		enchanted_room.Initialize(new_spell);

		//THEN
		auto room_number = enchanted_room.room_number();
		auto has_spell = enchanted_room.HasSpell();

		Assert::AreEqual(expected_room_number, room_number);
		Assert::IsTrue(has_spell);
	}
};
}

