// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "bombed_maze_factory.h"

#include "../mazeparts/bombed_wall.h"
#include "../mazeparts/room_with_a_bomb.h"

namespace creational
{
	Maze* BombedMazeFactory::MakeMaze() const
	{
		return new Maze;
	}

	Wall* BombedMazeFactory::MakeWall() const
	{
		return new BombedWall(false);
	}

	Room* BombedMazeFactory::MakeRoom(const int& room_number) const
	{
		return new RoomWithABomb(room_number, false);
	}

	Door* BombedMazeFactory::MakeDoor(const Room& first_room, const Room& second_room) const
	{
		return new Door(first_room, second_room);
	}
}
