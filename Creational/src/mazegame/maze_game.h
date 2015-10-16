// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEGAME_MAZE_GAME_H_
#define CREATIONAL_MAZEGAME_MAZE_GAME_H_

#include "../abstractfactory/maze_factory.h"
#include "../builder/maze_builder_interface.h"

namespace patterns
{
	class MazeGame
	{
	public:
		virtual ~MazeGame()
		{
		}

		Maze* CreateMaze() const;
		Maze* CreateSimpleMaze() const;
		Maze* CreateMaze(const MazeFactoryInterface&) const;
		Maze* CreateMaze(MazeBuilderInterface&) const;

		// factory methods
		virtual Maze* MakeMaze() const;
		virtual Room* MakeRoom(const int& room_number) const;
		virtual Wall* MakeWall() const;
		virtual Door* MakeDoor(const Room& first_room, const Room& second_room) const;
	};
}

#endif
