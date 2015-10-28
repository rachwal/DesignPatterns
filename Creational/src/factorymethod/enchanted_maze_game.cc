// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "enchanted_maze_game.h"

#include "../mazeparts/enchanted_room.h"
#include "../mazeparts/door_needing_spell.h"

namespace creational
{
	EnchantedMazeGame::EnchantedMazeGame()
	{
	}

	Room* EnchantedMazeGame::MakeRoom(const int& room_number) const
	{
		auto spell = WeaveSpell();
		return new EnchantedRoom(room_number, *spell);
	}

	Door* EnchantedMazeGame::MakeDoor(const Room& first_room, const Room& second_room) const
	{
		return new DoorNeedingSpell(first_room, second_room);
	}

	Spell* EnchantedMazeGame::WeaveSpell() const
	{
		return new Spell("Weave Spell");
	};
}
