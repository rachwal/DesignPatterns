// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "maze_game.h"

#include <memory>

namespace creational
{
using namespace commons;

MazeGame::~MazeGame() { }

commons::Maze *MazeGame::CreateMaze() const
{
	auto maze = new Maze();
	auto r1 = new Room(1);
	auto r2 = new Room(2);
	auto door = new Door(*r1, *r2);

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

	return maze;
}

Maze *MazeGame::CreateMaze(builder::MazeBuilderInterface& builder) const
{
	builder.BuildMaze();
	builder.BuildRoom(1000);
	builder.BuildRoom(2000);
	builder.BuildDoor(1000, 2000);

	return builder.GetMaze();
}

Maze *MazeGame::CreateMaze(const abstractfactory::MazeFactoryInterface& factory) const
{
	auto maze = factory.MakeMaze();
	auto r1 = factory.MakeRoom(100);
	auto r2 = factory.MakeRoom(200);
	auto door = factory.MakeDoor(*r1, *r2);
	auto wall = factory.MakeWall();

	maze->AddRoom(r1);
	maze->AddRoom(r2);

	r1->SetSide(North, wall);
	r1->SetSide(East, door);
	r1->SetSide(South, wall);
	r1->SetSide(West, wall);

	r2->SetSide(North, wall);
	r2->SetSide(East, wall);
	r2->SetSide(South, wall);
	r2->SetSide(West, door);

	return maze;
}

Maze *MazeGame::CreateSimpleMaze() const
{
	auto maze = MakeMaze();
	auto r1 = MakeRoom(12);
	auto r2 = MakeRoom(23);
	auto door = MakeDoor(*r1, *r2);
	auto wall = MakeWall();

	maze->AddRoom(r1);
	maze->AddRoom(r2);

	r1->SetSide(North, wall);
	r1->SetSide(East, door);
	r1->SetSide(South, wall);
	r1->SetSide(West, wall);

	r2->SetSide(North, wall);
	r2->SetSide(East, wall);
	r2->SetSide(South, wall);
	r2->SetSide(West, door);

	return maze;
}

Maze *MazeGame::MakeMaze() const
{
	return new Maze;
}

Room *MazeGame::MakeRoom(const int& room_number) const
{
	return new Room(room_number);
}

Wall *MazeGame::MakeWall() const
{
	return new Wall;
}

Door *MazeGame::MakeDoor(const Room& first_room, const Room& second_room) const
{
	return new Door(first_room, second_room);
}
}
