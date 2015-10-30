// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEGAME_MAZE_GAME_H_
#define CREATIONAL_MAZEGAME_MAZE_GAME_H_

#include "../abstractfactory/maze_factory.h"
#include "../builder/maze_builder_interface.h"

namespace creational
{
class MazeGame
{
	public:
	virtual ~MazeGame();

	commons::Maze *CreateMaze() const;
	commons::Maze *CreateSimpleMaze() const;
	commons::Maze *CreateMaze(const abstractfactory::MazeFactoryInterface&) const;
	commons::Maze *CreateMaze(builder::MazeBuilderInterface&) const;

	// factory methods
	virtual commons::Maze *MakeMaze() const;
	virtual commons::Room *MakeRoom(const int& room_number) const;
	virtual commons::Wall *MakeWall() const;
	virtual commons::Door *MakeDoor(const commons::Room& first_room, const commons::Room& second_room) const;
};
}

#endif
