// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "bombed_maze_factory.h"

#include "../mazeparts/bombed_wall.h"
#include "../mazeparts/room_with_a_bomb.h"

namespace creational
{
namespace abstractfactory
{
commons::Maze *BombedMazeFactory::MakeMaze() const
{
	return new commons::Maze;
}

commons::Wall *BombedMazeFactory::MakeWall() const
{
	return new commons::BombedWall(false);
}

commons::Room *BombedMazeFactory::MakeRoom(const int& room_number) const
{
	return new commons::RoomWithABomb(room_number, false);
}

commons::Door *BombedMazeFactory::MakeDoor(const commons::Room& first_room, const commons::Room& second_room) const
{
	return new commons::Door(first_room, second_room);
}
}
}

