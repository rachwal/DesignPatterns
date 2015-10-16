// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "maze_prototype_factory.h"

namespace patterns
{
	MazePrototypeFactory::MazePrototypeFactory(Maze* m, Wall* w, Room* r, Door* d)
	{
		prototype_maze_ = m;
		prototype_wall_ = w;
		prototype_room_ = r;
		prototype_door_ = d;
	}

	Room* MazePrototypeFactory::MakeRoom(const int&) const
	{
		auto room = prototype_room_->Clone();
		return room;
	}

	Maze* MazePrototypeFactory::MakeMaze() const
	{
		return prototype_maze_->Clone();
	}

	Wall* MazePrototypeFactory::MakeWall() const
	{
		return prototype_wall_->Clone();
	}

	Door* MazePrototypeFactory::MakeDoor(const Room& first_room, const Room& second_room) const
	{
		auto door = prototype_door_->Clone();
		door->Initialize(first_room, second_room);
		return door;
	}
}
