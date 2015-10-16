// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "enchanted_maze_factory.h"

#include "../mazeparts/enchanted_room.h"
#include "../mazeparts/door_needing_spell.h"

namespace patterns
{
	Maze* EnchantedMazeFactory::MakeMaze() const
	{
		return new Maze;
	}

	Wall* EnchantedMazeFactory::MakeWall() const
	{
		return new Wall;
	}

	Room* EnchantedMazeFactory::MakeRoom(const int& room_number) const
	{
		auto spell = CastSpell();
		return new EnchantedRoom(room_number, *spell);
	}

	Door* EnchantedMazeFactory::MakeDoor(const Room& first_room, const Room& second_room) const
	{
		return new DoorNeedingSpell(first_room, second_room);
	}

	Spell* EnchantedMazeFactory::CastSpell() const
	{
		return new Spell("Cast Spell");
	}
}
