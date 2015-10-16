// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_FACTORYMETHOD_ENCHANTED_MAZE_GAME_H_
#define CREATIONAL_FACTORYMETHOD_ENCHANTED_MAZE_GAME_H_

#include "../mazegame/maze_game.h"
#include "../mazeparts/spell.h"

namespace patterns
{
	class EnchantedMazeGame : public MazeGame
	{
	public:
		EnchantedMazeGame();

		virtual Room* MakeRoom(const int& room_number) const override;
		virtual Door* MakeDoor(const Room& first_room, const Room& second_room) const override;

	protected:
		Spell* WeaveSpell() const;
	};
}

#endif
