// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../creational/src/mazeparts/room_with_a_bomb.h"

namespace creationaltests
{
using namespace creational::commons;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(RoomWithABombTest)
{
	public:
	RoomWithABombTest() { }

	~RoomWithABombTest() { }

	TEST_METHOD(ShouldCreateRoomWithABomb)
	{
		//GIVEN
		auto expected_room_number = 2;
		auto bombed = true;

		//WHEN
		auto room_with_a_bomb = RoomWithABomb(expected_room_number, bombed);

		//THEN
		auto room_number = room_with_a_bomb.room_number();
		auto has_bomb = room_with_a_bomb.has_bomb();

		Assert::AreEqual(expected_room_number, room_number);
		Assert::IsTrue(has_bomb);
	}

	TEST_METHOD(ShouldCreateRoomWithoutBomb)
	{
		//GIVEN
		auto expected_room_number = 4;
		auto bombed = false;

		//WHEN
		auto room_with_a_bomb = RoomWithABomb(expected_room_number, bombed);

		//THEN
		auto room_number = room_with_a_bomb.room_number();
		auto has_bomb = room_with_a_bomb.has_bomb();

		Assert::AreEqual(expected_room_number, room_number);
		Assert::IsFalse(has_bomb);
	}

	TEST_METHOD(ShouldCreateRoomWithoutBombFromAnotherRoomWithoutBomb)
	{
		//GIVEN
		auto expected_room_number = 4;
		auto bombed = false;
		auto existing_room_with_a_bomb = RoomWithABomb(expected_room_number, bombed);

		//WHEN
		auto room_with_a_bomb = RoomWithABomb(existing_room_with_a_bomb);

		//THEN
		auto room_number = room_with_a_bomb.room_number();
		auto has_bomb = room_with_a_bomb.has_bomb();

		Assert::AreEqual(expected_room_number, room_number);
		Assert::IsFalse(has_bomb);
	}

	TEST_METHOD(ShouldCreateRoomWithABombFromAnotherRoomWithABomb)
	{
		//GIVEN
		auto expected_room_number = 4;
		auto bombed = true;
		auto existing_room_with_a_bomb = RoomWithABomb(expected_room_number, bombed);

		//WHEN
		auto room_with_a_bomb = RoomWithABomb(existing_room_with_a_bomb);

		//THEN
		auto room_number = room_with_a_bomb.room_number();
		auto has_bomb = room_with_a_bomb.has_bomb();

		Assert::AreEqual(expected_room_number, room_number);
		Assert::IsTrue(has_bomb);
	}

	TEST_METHOD(ShouldCloneRoomWithABomb)
	{
		//GIVEN
		auto expected_room_number = 4;
		auto bombed = true;
		auto existing_room_with_a_bomb = RoomWithABomb(expected_room_number, bombed);

		//WHEN
		auto room_with_a_bomb = existing_room_with_a_bomb.Clone();

		//THEN
		auto room_number = room_with_a_bomb->room_number();
		auto has_bomb = room_with_a_bomb->has_bomb();

		Assert::AreEqual(expected_room_number, room_number);
		Assert::IsTrue(has_bomb);
	}

	TEST_METHOD(ShouldCloneRoomWithoutBomb)
	{
		//GIVEN
		auto expected_room_number = 4;
		auto bombed = false;
		auto existing_room_with_a_bomb = RoomWithABomb(expected_room_number, bombed);

		//WHEN
		auto room_with_a_bomb = existing_room_with_a_bomb.Clone();

		//THEN
		auto room_number = room_with_a_bomb->room_number();
		auto has_bomb = room_with_a_bomb->has_bomb();

		Assert::AreEqual(expected_room_number, room_number);
		Assert::IsFalse(has_bomb);
	}

	TEST_METHOD(ShouldInitializeRoomWithoutBomb)
	{
		//GIVEN
		auto expected_room_number = 4;
		auto bombed = true;

		//WHEN
		auto room_with_a_bomb = RoomWithABomb(expected_room_number, bombed);

		//THEN
		room_with_a_bomb.Initialize(false);
		auto has_bomb = room_with_a_bomb.has_bomb();

		Assert::IsFalse(has_bomb);
	}
};
}

