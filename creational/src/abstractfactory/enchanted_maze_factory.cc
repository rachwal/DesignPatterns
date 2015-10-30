// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "enchanted_maze_factory.h"

#include "../mazeparts/enchanted_room.h"
#include "../mazeparts/door_needing_spell.h"

namespace creational
{
namespace abstractfactory
{
commons::Maze *EnchantedMazeFactory::MakeMaze() const
{
	return new commons::Maze;
}

commons::Wall *EnchantedMazeFactory::MakeWall() const
{
	return new commons::Wall;
}

commons::Room *EnchantedMazeFactory::MakeRoom(const int& room_number) const
{
	auto spell = CastSpell();
	return new commons::EnchantedRoom(room_number, *spell);
}

commons::Door *EnchantedMazeFactory::MakeDoor(const commons::Room& first_room, const commons::Room& second_room) const
{
	return new commons::DoorNeedingSpell(first_room, second_room);
}

commons::Spell *EnchantedMazeFactory::CastSpell() const
{
	return new commons::Spell("Cast Spell");
}
}}
