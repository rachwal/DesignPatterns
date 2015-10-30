// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Creational/src/mazeparts/room.h"
#include "../../../Creational/src/mazeparts/wall.h"
#include "../../../Creational/src/mazeparts/door.h"

namespace creationaltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace creational::commons;

TEST_CLASS(RoomTest)
{
	public:
	RoomTest() { }

	~RoomTest() { }

	TEST_METHOD(ShouldCreateNonEnteredRoomWithNumber)
	{
		//GIVEN
		auto expected_room_number = 3;

		//WHEN
		auto room = Room(expected_room_number);

		//THEN
		auto room_number = room.room_number();
		auto entered = room.entered();

		Assert::AreEqual(expected_room_number, room_number);
		Assert::AreEqual(false, entered);
	}

	TEST_METHOD(ShouldEnterRoom)
	{
		//GIVEN
		auto room = Room(0);

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
		auto existing_room = Room(expected_room_number);

		//WHEN
		auto room = Room(existing_room);

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
		auto existing_room = Room(expected_room_number);

		//WHEN
		auto room = Room(existing_room);
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
		auto room = Room(1);
		auto wall = new Wall();
		auto door = new Door(Room(3), Room(4));

		//WHEN
		room.SetSide(North, wall);
		room.SetSide(South, door);

		//THEN
		auto north_side = room.GetSide(North);
		auto north_side_wall = dynamic_cast<Wall*>(north_side);

		auto south_side = room.GetSide(South);
		auto south_side_door = dynamic_cast<Door*>(south_side);

		auto east_side = room.GetSide(East);
		auto west_side = room.GetSide(West);

		Assert::IsNotNull(north_side_wall);
		Assert::IsNotNull(south_side_door);
		Assert::IsNull(east_side);
		Assert::IsNull(west_side);
	}

	TEST_METHOD(ShouldCloneNonEnteredRoom)
	{
		//GIVEN
		auto expected_room_number = 3;
		auto existing_room = Room(expected_room_number);
		existing_room.SetSide(West, new Wall);

		//WHEN
		auto room = existing_room.Clone();

		//THEN
		auto room_number = room->room_number();
		auto entered = room->entered();
		auto west_side = room->GetSide(West);

		Assert::AreEqual(expected_room_number, room_number);
		Assert::AreEqual(false, entered);
		Assert::IsNotNull(west_side);
	}

	TEST_METHOD(ShouldCloneEnteredRoom)
	{
		//GIVEN
		auto expected_room_number = 3;
		auto existing_room = Room(expected_room_number);

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
