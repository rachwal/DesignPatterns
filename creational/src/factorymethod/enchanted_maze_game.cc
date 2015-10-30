// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "enchanted_maze_game.h"

#include "../mazeparts/enchanted_room.h"
#include "../mazeparts/door_needing_spell.h"

namespace creational
{
namespace factorymethod
{
EnchantedMazeGame::EnchantedMazeGame() { }

commons::Room *EnchantedMazeGame::MakeRoom(const int& room_number) const
{
	auto spell = WeaveSpell();
	return new commons::EnchantedRoom(room_number, *spell);
}

commons::Door *EnchantedMazeGame::MakeDoor(const commons::Room& first_room, const commons::Room& second_room) const
{
	return new commons::DoorNeedingSpell(first_room, second_room);
}

commons::Spell *EnchantedMazeGame::WeaveSpell() const
{
	return new commons::Spell("Weave Spell");
};
}}
