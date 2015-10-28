// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_FACTORYMETHOD_BOMBED_MAZE_GAME_H_
#define CREATIONAL_FACTORYMETHOD_BOMBED_MAZE_GAME_H_

#include "../mazegame/maze_game.h"

namespace creational
{
	class BombedMazeGame : public MazeGame
	{
	public:
		BombedMazeGame();

		virtual Wall* MakeWall() const override;
		virtual Room* MakeRoom(const int& room_number) const override;
	};
}

#endif
