// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "standard_maze_builder.h"

#include "../mazeparts/wall.h"
#include "../mazeparts/door.h"

namespace creational
{
namespace builder
{
StandardMazeBuilder::StandardMazeBuilder() :current_maze_(nullptr) { }

StandardMazeBuilder::~StandardMazeBuilder()
{
	delete current_maze_;
}

void StandardMazeBuilder::BuildMaze()
{
	current_maze_ = new commons::Maze;
}

void StandardMazeBuilder::BuildRoom(const int& room_number)
{
	auto room = new commons::Room(room_number);
	current_maze_->AddRoom(room);

	room->SetSide(commons::North, new commons::Wall);
	room->SetSide(commons::South, new commons::Wall);
	room->SetSide(commons::East, new commons::Wall);
	room->SetSide(commons::West, new commons::Wall);
}

void StandardMazeBuilder::BuildDoor(const int& first_room_number, const int& second_room_number)
{
	auto r1 = current_maze_->GetRoom(first_room_number);
	auto r2 = current_maze_->GetRoom(second_room_number);
	auto d = new commons::Door(*r1, *r2);

	r1->SetSide(CommonWall(*r1, *r2), d);
	r2->SetSide(CommonWall(*r2, *r1), d);
}

commons::Maze *StandardMazeBuilder::GetMaze()
{
	return current_maze_;
}

commons::Direction StandardMazeBuilder::CommonWall(const commons::Room& first_room, const commons::Room& second_room) const
{
	auto r1_number = first_room.room_number();
	auto r2_number = second_room.room_number();
	if (r1_number < r2_number)
	{
		return commons::East;
	}
	return commons::West;
}
}}
