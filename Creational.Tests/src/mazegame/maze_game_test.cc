// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>
#include "../../../Creational/src/mazegame/maze_game.h"
#include "../utils/validator.h"
#include "../../../Creational/src/abstractfactory/bombed_maze_factory.h"
#include "../../../Creational/src/abstractfactory/enchanted_maze_factory.h"
#include "../../../Creational/src/builder/standard_maze_builder.h"
#include "../../../Creational/src/builder/counting_maze_builder.h"
#include "../../../Creational/src/prototype/maze_prototype_factory.h"
#include "../../../Creational/src/mazeparts/enchanted_room.h"
#include "../../../Creational/src/mazeparts/bombed_wall.h"

namespace patternstests
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(MazeGameTest)
	{
	public:
		MazeGameTest()
		{
		}

		~MazeGameTest()
		{
		}

		TEST_METHOD(ShouldValidateMazeWithBasicConfiguration)
		{
			//GIVEN
			auto maze = new patterns::Maze();
			auto r1 = new patterns::Room(1);
			auto r2 = new patterns::Room(2);
			auto door = new patterns::Door(*r1, *r2);

			//WHEN
			r1->SetSide(patterns::North, new patterns::Wall);
			r1->SetSide(patterns::East, door);
			r1->SetSide(patterns::South, new patterns::Wall);
			r1->SetSide(patterns::West, new patterns::Wall);

			r2->SetSide(patterns::North, new patterns::Wall);
			r2->SetSide(patterns::East, new patterns::Wall);
			r2->SetSide(patterns::South, new patterns::Wall);
			r2->SetSide(patterns::West, door);

			maze->AddRoom(r1);
			maze->AddRoom(r2);

			//THEN
			Assert::IsTrue(Validator::BasicMazeConfiguration(maze));
		}

		TEST_METHOD(ShouldInvalidateMazeWithoutBasicConfiguration)
		{
			//WHEN
			auto maze = new patterns::Maze();

			//THEN
			Assert::IsFalse(Validator::BasicMazeConfiguration(maze));
		}

		TEST_METHOD(ShouldCreateMazeWithBasicConfiguration)
		{
			//GIVEN
			patterns::MazeGame maze_game;
			patterns::Maze* maze;

			//WHEN
			maze = maze_game.CreateMaze();

			//THEN
			Assert::IsTrue(Validator::BasicMazeConfiguration(maze));
		}

		TEST_METHOD(ShouldCreateMazeUsingFactoryMethods)
		{
			//GIVEN
			patterns::MazeGame maze_game;
			patterns::Maze* maze;

			//WHEN
			maze = maze_game.CreateSimpleMaze();

			//THEN
			Assert::IsFalse(Validator::BasicMazeConfiguration(maze));
			Assert::IsTrue(Validator::FactoryMethodsMazeConfiguration(maze));
		}

		TEST_METHOD(ShouldCreateMazeUsingBombedMazeFactory)
		{
			//GIVEN
			patterns::MazeGame maze_game;
			patterns::Maze* maze;
			patterns::BombedMazeFactory bombed_maze_factory;

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
			patterns::MazeGame maze_game;
			patterns::Maze* maze;
			patterns::EnchantedMazeFactory enchanted_maze_factory;

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
			patterns::MazeGame maze_game;
			patterns::Maze* maze;

			//WHEN
			maze = maze_game.CreateMaze(*patterns::MazeFactory::Instance());

			//THEN
			Assert::IsFalse(Validator::BombedMazeFactoryMazeConfiguration(maze));
			Assert::IsFalse(Validator::EnchantedMazeFactoryMazeConfiguration(maze));
			Assert::IsTrue(Validator::MazeFactoryMazeConfiguration(maze));
		}

		TEST_METHOD(ShouldCreateMazeUsingStandardMazeBuilder)
		{
			//GIVEN
			patterns::MazeGame maze_game;
			patterns::Maze* maze;
			patterns::StandardMazeBuilder standard_maze_builder;

			//WHEN
			maze = maze_game.CreateMaze(standard_maze_builder);

			//THEN
			Assert::IsTrue(Validator::StandardMazeBuilderConfiguration(maze));
		}

		TEST_METHOD(ShouldCreateMazeUsingCountingMazeBuilder)
		{
			//GIVEN
			patterns::MazeGame maze_game;
			patterns::Maze* maze;
			patterns::CountingMazeBuilder counting_maze_builder;

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
			auto prototype_door = new patterns::Door(patterns::Room(10), patterns::Room(11));

			patterns::MazeGame maze_game;
			patterns::Maze* maze;
			patterns::MazePrototypeFactory maze_prototype_factory(new patterns::Maze, new patterns::BombedWall(true), new patterns::EnchantedRoom(66, patterns::Spell("abracadabra")), prototype_door);

			//WHEN
			maze = maze_game.CreateMaze(maze_prototype_factory);

			//THEN
			auto prototype_room = maze->GetRoom(66);
			auto enchanted_room = dynamic_cast<patterns::EnchantedRoom*>(prototype_room);

			Assert::IsNotNull(prototype_room);
			Assert::IsNotNull(enchanted_room);
		}
	};
}
