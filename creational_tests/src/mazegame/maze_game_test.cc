// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "../utils/validator.h"

#include <CppUnitTest.h>

#include "../../../Creational/src/mazegame/maze_game.h"
#include "../../../Creational/src/abstractfactory/bombed_maze_factory.h"
#include "../../../Creational/src/abstractfactory/enchanted_maze_factory.h"
#include "../../../Creational/src/builder/standard_maze_builder.h"
#include "../../../Creational/src/builder/counting_maze_builder.h"
#include "../../../Creational/src/prototype/maze_prototype_factory.h"
#include "../../../Creational/src/mazeparts/enchanted_room.h"
#include "../../../Creational/src/mazeparts/bombed_wall.h"

namespace creationaltests
{
using namespace creational;
using namespace validation;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(MazeGameTest)
{
	public:
	MazeGameTest() { }

	~MazeGameTest() { }

	TEST_METHOD(ShouldValidateMazeWithBasicConfiguration)
	{
		//GIVEN
		auto maze = new Maze();
		auto r1 = new Room(1);
		auto r2 = new Room(2);
		auto door = new Door(*r1, *r2);

		//WHEN
		r1->SetSide(North, new Wall);
		r1->SetSide(East, door);
		r1->SetSide(South, new Wall);
		r1->SetSide(West, new Wall);

		r2->SetSide(North, new Wall);
		r2->SetSide(East, new Wall);
		r2->SetSide(South, new Wall);
		r2->SetSide(West, door);

		maze->AddRoom(r1);
		maze->AddRoom(r2);

		//THEN
		Assert::IsTrue(Validator::BasicMazeConfiguration(maze));
	}

	TEST_METHOD(ShouldInvalidateMazeWithoutBasicConfiguration)
	{
		//WHEN
		auto maze = new Maze();

		//THEN
		Assert::IsFalse(Validator::BasicMazeConfiguration(maze));
	}

	TEST_METHOD(ShouldCreateMazeWithBasicConfiguration)
	{
		//GIVEN
		MazeGame maze_game;
		Maze* maze;

		//WHEN
		maze = maze_game.CreateMaze();

		//THEN
		Assert::IsTrue(Validator::BasicMazeConfiguration(maze));
	}

	TEST_METHOD(ShouldCreateMazeUsingFactoryMethods)
	{
		//GIVEN
		MazeGame maze_game;
		Maze* maze;

		//WHEN
		maze = maze_game.CreateSimpleMaze();

		//THEN
		Assert::IsFalse(Validator::BasicMazeConfiguration(maze));
		Assert::IsTrue(Validator::FactoryMethodsMazeConfiguration(maze));
	}

	TEST_METHOD(ShouldCreateMazeUsingBombedMazeFactory)
	{
		//GIVEN
		MazeGame maze_game;
		Maze* maze;
		abstractfactory::BombedMazeFactory bombed_maze_factory;

		//WHEN
		maze = maze_game.CreateMaze(bombed_maze_factory);

		//THEN
		Assert::IsTrue(Validator::BombedMazeFactoryMazeConfiguration(maze));
		Assert::IsFalse(Validator::EnchantedMazeFactoryMazeConfiguration(maze));
		Assert::IsTrue(Validator::MazeFactoryMazeConfiguration(maze));
	}

	TEST_METHOD(ShouldCreateMazeUsingEnchantedMazeFactory)
	{
		//GIVEN
		MazeGame maze_game;
		Maze* maze;
		abstractfactory::EnchantedMazeFactory enchanted_maze_factory;

		//WHEN
		maze = maze_game.CreateMaze(enchanted_maze_factory);

		//THEN
		Assert::IsFalse(Validator::BombedMazeFactoryMazeConfiguration(maze));
		Assert::IsTrue(Validator::EnchantedMazeFactoryMazeConfiguration(maze));
		Assert::IsTrue(Validator::MazeFactoryMazeConfiguration(maze));
	}

	TEST_METHOD(ShouldCreateMazeUsingSingletonMazeFactory)
	{
		//GIVEN
		MazeGame maze_game;
		Maze* maze;

		//WHEN
		maze = maze_game.CreateMaze(*abstractfactory::MazeFactory::Instance());

		//THEN
		Assert::IsFalse(Validator::BombedMazeFactoryMazeConfiguration(maze));
		Assert::IsFalse(Validator::EnchantedMazeFactoryMazeConfiguration(maze));
		Assert::IsTrue(Validator::MazeFactoryMazeConfiguration(maze));
	}

	TEST_METHOD(ShouldCreateMazeUsingStandardMazeBuilder)
	{
		//GIVEN
		MazeGame maze_game;
		Maze* maze;
		builder::StandardMazeBuilder standard_maze_builder;

		//WHEN
		maze = maze_game.CreateMaze(standard_maze_builder);

		//THEN
		Assert::IsTrue(Validator::StandardMazeBuilderConfiguration(maze));
	}

	TEST_METHOD(ShouldCreateMazeUsingCountingMazeBuilder)
	{
		//GIVEN
		MazeGame maze_game;
		Maze* maze;
		builder::CountingMazeBuilder counting_maze_builder;

		//WHEN
		maze = maze_game.CreateMaze(counting_maze_builder);

		//THEN
		int rooms, doors;
		counting_maze_builder.GetCounts(&rooms, &doors);
		Assert::AreEqual(2, rooms);
		Assert::AreEqual(1, doors);
		Assert::IsTrue(Validator::StandardMazeBuilderConfiguration(maze));
	}

	TEST_METHOD(ShouldCreateMazeUsingMazePrototypeFactory)
	{
		//GIVEN
		auto prototype_door = new Door(Room(10), Room(11));

		MazeGame maze_game;
		Maze* maze;
		prototype::MazePrototypeFactory maze_prototype_factory(new Maze, new BombedWall(true), new EnchantedRoom(66, Spell("abracadabra")), prototype_door);

		//WHEN
		maze = maze_game.CreateMaze(maze_prototype_factory);

		//THEN
		auto prototype_room = maze->GetRoom(66);
		auto enchanted_room = dynamic_cast<EnchantedRoom*>(prototype_room);

		Assert::IsNotNull(prototype_room);
		Assert::IsNotNull(enchanted_room);
	}
};
}

