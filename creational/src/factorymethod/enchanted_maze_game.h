// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_FACTORYMETHOD_ENCHANTED_MAZE_GAME_H_
#define CREATIONAL_FACTORYMETHOD_ENCHANTED_MAZE_GAME_H_

#include "../mazegame/maze_game.h"
#include "../mazeparts/spell.h"

namespace creational
{
namespace factorymethod
{
class EnchantedMazeGame : public MazeGame
{
	public:
	EnchantedMazeGame();

	virtual commons::Room *MakeRoom(const int& room_number) const override;
	virtual commons::Door *MakeDoor(const commons::Room& first_room, const commons::Room& second_room) const override;

	protected:
	commons::Spell *WeaveSpell() const;
};
}}

#endif
