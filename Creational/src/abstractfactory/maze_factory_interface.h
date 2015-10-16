// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_ABSTRACTFACTORY_MAZE_FACTORY_INTERFACE_H_
#define CREATIONAL_ABSTRACTFACTORY_MAZE_FACTORY_INTERFACE_H_

#include "../mazeparts/maze.h"
#include "../mazeparts/wall.h"
#include "../mazeparts/door.h"

namespace patterns
{
	class MazeFactoryInterface
	{
	public:
		virtual ~MazeFactoryInterface()
		{
		}

		virtual Maze* MakeMaze() const = 0;
		virtual Wall* MakeWall() const = 0;
		virtual Room* MakeRoom(const int& room_number) const = 0;
		virtual Door* MakeDoor(const Room& first_room, const Room& second_room) const = 0;
	};
}

#endif
