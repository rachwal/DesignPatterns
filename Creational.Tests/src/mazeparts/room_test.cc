// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Creational/src/mazeparts/room.h"
#include "../../../Creational/src/mazeparts/wall.h"
#include "../../../Creational/src/mazeparts/door.h"

namespace patternstests
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(RoomTest)
	{
	public:
		RoomTest()
		{
		}

		~RoomTest()
		{
		}

		TEST_METHOD(ShouldCreateNonEnteredRoomWithNumber)
		{
			//GIVEN
			auto expected_room_number = 3;

			//WHEN
			auto room = patterns::Room(expected_room_number);

			//THEN
			auto room_number = room.room_number();
			auto entered = room.entered();

			Assert::AreEqual(expected_room_number, room_number);
			Assert::AreEqual(false, entered);
		}

		TEST_METHOD(ShouldEnterRoom)
		{
			//GIVEN
			auto room = patterns::Room(0);

			//WHEN
			room.Enter();

			//THEN
			auto entered = room.entered();

			Assert::AreEqual(true, entered);
		}

		TEST_METHOD(ShouldCreateRoomWithFromNonEnteredRoom)
		{
			//GIVEN
			auto expected_room_number = 3;
			auto existing_room = patterns::Room(expected_room_number);

			//WHEN
			auto room = patterns::Room(existing_room);

			//THEN
			auto room_number = room.room_number();
			auto entered = room.entered();

			Assert::AreEqual(expected_room_number, room_number);
			Assert::AreEqual(false, entered);
		}

		TEST_METHOD(ShouldCreateRoomWithFromEnteredRoom)
		{
			//GIVEN
			auto expected_room_number = 3;
			auto existing_room = patterns::Room(expected_room_number);

			//WHEN
			auto room = patterns::Room(existing_room);
			room.Enter();

			//THEN
			auto room_number = room.room_number();
			auto entered = room.entered();

			Assert::AreEqual(expected_room_number, room_number);
			Assert::AreEqual(true, entered);
		}

		TEST_METHOD(ShouldSetSide)
		{
			//GIVEN
			auto room = patterns::Room(1);
			auto wall = new patterns::Wall();
			auto door = new patterns::Door(patterns::Room(3), patterns::Room(4));

			//WHEN
			room.SetSide(patterns::North, wall);
			room.SetSide(patterns::South, door);

			//THEN
			auto north_side = room.GetSide(patterns::North);
			auto north_side_wall = dynamic_cast<patterns::Wall*>(north_side);

			auto south_side = room.GetSide(patterns::South);
			auto south_side_door = dynamic_cast<patterns::Door*>(south_side);

			auto east_side = room.GetSide(patterns::East);
			auto west_side = room.GetSide(patterns::West);

			Assert::IsNotNull(north_side_wall);
			Assert::IsNotNull(south_side_door);
			Assert::IsNull(east_side);
			Assert::IsNull(west_side);
		}

		TEST_METHOD(ShouldCloneNonEnteredRoom)
		{
			//GIVEN
			auto expected_room_number = 3;
			auto existing_room = patterns::Room(expected_room_number);
			existing_room.SetSide(patterns::West, new patterns::Wall);

			//WHEN
			auto room = existing_room.Clone();

			//THEN
			auto room_number = room->room_number();
			auto entered = room->entered();
			auto west_side = room->GetSide(patterns::West);

			Assert::AreEqual(expected_room_number, room_number);
			Assert::AreEqual(false, entered);
			Assert::IsNotNull(west_side);
		}

		TEST_METHOD(ShouldCloneEnteredRoom)
		{
			//GIVEN
			auto expected_room_number = 3;
			auto existing_room = patterns::Room(expected_room_number);

			//WHEN
			auto room = existing_room.Clone();
			room->Enter();

			//THEN
			auto room_number = room->room_number();
			auto entered = room->entered();

			Assert::AreEqual(expected_room_number, room_number);
			Assert::AreEqual(true, entered);
		}
	};
}
