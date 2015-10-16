// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "bombed_maze_game.h"

#include "../mazeparts/bombed_wall.h"
#include "../mazeparts/room_with_a_bomb.h"

namespace patterns
{
	BombedMazeGame::BombedMazeGame()
	{
	}

	Wall* BombedMazeGame::MakeWall() const
	{
		return new BombedWall(false);
	}

	Room* BombedMazeGame::MakeRoom(const int& room_number) const
	{
		return new RoomWithABomb(room_number, false);
	}
}
