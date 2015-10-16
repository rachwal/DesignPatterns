// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Creational/src/mazeparts/room.h"
#include "../../../Creational/src/mazeparts/door.h"

namespace patternstests
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(DoorTest)
	{
	public:
		DoorTest()
		{
		}

		~DoorTest()
		{
		}

		TEST_METHOD(ShouldCreateNotEnteredDoor)
		{
			//GIVEN
			auto east_room_number = 12;
			auto east_room = patterns::Room(east_room_number);
			auto west_room_number = 31;
			auto west_room = patterns::Room(west_room_number);

			//WHEN
			auto door = patterns::Door(east_room, west_room);

			//THEN
			auto east_room_other_side = door.OtherSideFrom(east_room);
			auto west_room_other_side = door.OtherSideFrom(west_room);
			auto entered = door.entered();

			Assert::IsFalse(entered);
			Assert::AreEqual(west_room_number, east_room_other_side->room_number());
			Assert::AreEqual(east_room_number, west_room_other_side->room_number());
		}

		TEST_METHOD(ShouldEnterDoor)
		{
			//GIVEN
			auto east_room = patterns::Room(1);
			auto west_room = patterns::Room(2);
			auto door = patterns::Door(east_room, west_room);

			//WHEN
			door.Enter();

			//THEN
			auto entered = door.entered();
			Assert::IsTrue(entered);
		}

		TEST_METHOD(ShouldCreateFromAnotherDoor)
		{
			//GIVEN
			auto east_room_number = 12;
			auto east_room = patterns::Room(east_room_number);
			auto west_room_number = 31;
			auto west_room = patterns::Room(west_room_number);
			auto existing_door = patterns::Door(east_room, west_room);
			existing_door.Enter();

			//WHEN
			auto door = patterns::Door(existing_door);

			//THEN
			auto east_room_other_side = door.OtherSideFrom(east_room);
			auto west_room_other_side = door.OtherSideFrom(west_room);
			auto entered = door.entered();

			Assert::IsTrue(entered);
			Assert::AreEqual(west_room_number, east_room_other_side->room_number());
			Assert::AreEqual(east_room_number, west_room_other_side->room_number());
		}

		TEST_METHOD(ShouldCloneDoor)
		{
			//GIVEN
			auto east_room_number = 11;
			auto east_room = patterns::Room(east_room_number);
			auto west_room_number = 22;
			auto west_room = patterns::Room(west_room_number);
			auto existing_door = patterns::Door(east_room, west_room);
			existing_door.Enter();

			//WHEN
			auto door = existing_door.Clone();

			//THEN
			auto east_room_other_side = door->OtherSideFrom(east_room);
			auto west_room_other_side = door->OtherSideFrom(west_room);
			auto entered = door->entered();

			Assert::IsTrue(entered);
			Assert::AreEqual(west_room_number, east_room_other_side->room_number());
			Assert::AreEqual(east_room_number, west_room_other_side->room_number());
		}

		TEST_METHOD(ShouldInitializeDoor)
		{
			//GIVEN
			auto east_room_number = 11;
			auto east_room = patterns::Room(east_room_number);
			auto west_room_number = 22;
			auto west_room = patterns::Room(west_room_number);
			auto door = patterns::Door(patterns::Room(1), patterns::Room(2));

			//WHEN
			door.Initialize(east_room, west_room);

			//THEN
			auto east_room_other_side = door.OtherSideFrom(east_room);
			auto west_room_other_side = door.OtherSideFrom(west_room);

			Assert::AreEqual(west_room_number, east_room_other_side->room_number());
			Assert::AreEqual(east_room_number, west_room_other_side->room_number());
		}
	};
}