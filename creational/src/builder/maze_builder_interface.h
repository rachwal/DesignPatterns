// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_BUILDER_MAZE_BUILDER_INTERFACE_H_
#define CREATIONAL_BUILDER_MAZE_BUILDER_INTERFACE_H_

#include "../mazeparts/maze.h"

namespace creational
{
namespace builder
{
class MazeBuilderInterface
{
	public:
	virtual ~MazeBuilderInterface() { }

	virtual void BuildMaze() = 0;
	virtual void BuildRoom(const int& room_number) = 0;
	virtual void BuildDoor(const int& rist_room_number, const int& second_room_number) = 0;

	virtual commons::Maze *GetMaze() = 0;
};
}
}

#endif

