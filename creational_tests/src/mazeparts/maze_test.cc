// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../creational/src/mazeparts/room.h"
#include "../../../creational/src/mazeparts/maze.h"

namespace creationaltests
{
using namespace creational::commons;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(MazeTest)
{
	public:
	MazeTest() { }

	~MazeTest() { }

	TEST_METHOD(ShouldAddRoom)
	{
		//GIVEN
		auto expected_room_number = 3;
		auto existing_room = Room(expected_room_number);
		Maze maze;

		//WHEN
		maze.AddRoom(&existing_room);

		//THEN
		auto room = maze.GetRoom(expected_room_number);

		Assert::IsNotNull(room);
	}

	TEST_METHOD(ReturnNullptrWhenTryToGetNotAddedRoom)
	{
		//GIVEN
		Maze maze;

		//WHEN
		auto room = maze.GetRoom(1);

		//THEN
		Assert::IsNull(room);
	}

	TEST_METHOD(ShouldAddMultipleRooms)
	{
		//GIVEN
		auto south_room_number = 1;
		auto existing_south_room = Room(south_room_number);
		auto north_room_number = 2;
		auto existing_north_room = Room(north_room_number);
		auto west_room_number = 3;
		auto existing_west_room = Room(west_room_number);
		auto east_room_number = 4;
		auto existing_east_room = Room(east_room_number);
		Maze maze;

		//WHEN
		maze.AddRoom(&existing_south_room);
		maze.AddRoom(&existing_south_room);
		maze.AddRoom(&existing_north_room);
		maze.AddRoom(&existing_west_room);
		maze.AddRoom(&existing_east_room);

		//THEN
		auto south_room = maze.GetRoom(south_room_number);
		auto north_room = maze.GetRoom(north_room_number);
		auto west_room = maze.GetRoom(west_room_number);
		auto east_room = maze.GetRoom(east_room_number);

		Assert::IsNotNull(south_room);
		Assert::IsNotNull(north_room);
		Assert::IsNotNull(west_room);
		Assert::IsNotNull(east_room);
	}

	TEST_METHOD(ShouldCreateMazeFromExistingMaze)
	{
		//GIVEN
		auto south_room_number = 1;
		auto existing_south_room = Room(south_room_number);
		auto north_room_number = 2;
		auto existing_north_room = Room(north_room_number);
		auto west_room_number = 3;
		auto existing_west_room = Room(west_room_number);
		auto east_room_number = 4;
		auto existing_east_room = Room(east_room_number);

		Maze existing_maze;

		existing_maze.AddRoom(&existing_south_room);
		existing_maze.AddRoom(&existing_south_room);
		existing_maze.AddRoom(&existing_north_room);
		existing_maze.AddRoom(&existing_west_room);
		existing_maze.AddRoom(&existing_east_room);

		//WHEN
		auto maze = Maze(existing_maze);

		//THEN
		auto south_room = maze.GetRoom(south_room_number);
		auto north_room = maze.GetRoom(north_room_number);
		auto west_room = maze.GetRoom(west_room_number);
		auto east_room = maze.GetRoom(east_room_number);

		Assert::IsNotNull(south_room);
		Assert::IsNotNull(north_room);
		Assert::IsNotNull(west_room);
		Assert::IsNotNull(east_room);
	}

	TEST_METHOD(ShouldCloneMaze)
	{
		//GIVEN
		auto south_room_number = 1;
		auto existing_south_room = Room(south_room_number);
		auto north_room_number = 2;
		auto existing_north_room = Room(north_room_number);
		auto west_room_number = 3;
		auto existing_west_room = Room(west_room_number);
		auto east_room_number = 4;
		auto existing_east_room = Room(east_room_number);

		Maze existing_maze;

		existing_maze.AddRoom(&existing_south_room);
		existing_maze.AddRoom(&existing_south_room);
		existing_maze.AddRoom(&existing_north_room);
		existing_maze.AddRoom(&existing_west_room);
		existing_maze.AddRoom(&existing_east_room);

		//WHEN
		auto maze = existing_maze.Clone();

		//THEN
		auto south_room = maze->GetRoom(south_room_number);
		auto north_room = maze->GetRoom(north_room_number);
		auto west_room = maze->GetRoom(west_room_number);
		auto east_room = maze->GetRoom(east_room_number);

		Assert::IsNotNull(south_room);
		Assert::IsNotNull(north_room);
		Assert::IsNotNull(west_room);
		Assert::IsNotNull(east_room);
	}
};
}

