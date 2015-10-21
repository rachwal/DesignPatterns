// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "validator.h"

#include "../../../Creational/src/mazeparts/maze.h"
#include "../../../Creational/src/mazeparts/door.h"
#include "../../../Creational/src/mazeparts/wall.h"
#include "../../../Creational/src/mazeparts/door_needing_spell.h"
#include "../../../Creational/src/mazeparts/bombed_wall.h"
#include "../../../Creational/src/mazeparts/room_with_a_bomb.h"
#include "../../../Creational/src/mazeparts/enchanted_room.h"

namespace patternstests
{
	bool Validator::BasicMazeConfiguration(patterns::Maze* maze)
	{
		if (!ValidateRoom<patterns::Door, patterns::Wall, patterns::Wall, patterns::Wall>(maze, 1))
		{
			return false;
		}

		if (!ValidateRoom<patterns::Wall, patterns::Door, patterns::Wall, patterns::Wall>(maze, 2))
		{
			return false;
		}

		return true;
	}

	bool Validator::FactoryMethodsMazeConfiguration(patterns::Maze* maze)
	{
		if (!ValidateRoom<patterns::Door, patterns::Wall, patterns::Wall, patterns::Wall>(maze, 12))
		{
			return false;
		}

		if (!ValidateRoom<patterns::Wall, patterns::Door, patterns::Wall, patterns::Wall>(maze, 23))
		{
			return false;
		}

		return true;
	}

	bool Validator::BombedMazeFactoryMazeConfiguration(patterns::Maze* maze)
	{
		if (!ValidateRoomType<patterns::RoomWithABomb>(maze, 100))
		{
			return false;
		}

		if (!ValidateRoom<patterns::Door, patterns::Wall, patterns::Wall, patterns::BombedWall>(maze, 100))
		{
			return false;
		}

		if (!ValidateRoom<patterns::Wall, patterns::Door, patterns::Wall, patterns::Wall>(maze, 200))
		{
			return false;
		}

		return true;
	}

	bool Validator::EnchantedMazeFactoryMazeConfiguration(patterns::Maze* maze)
	{
		if (!ValidateRoomType<patterns::EnchantedRoom>(maze, 100))
		{
			return false;
		}

		if (!ValidateRoom<patterns::DoorNeedingSpell, patterns::Wall, patterns::Wall, patterns::Wall>(maze, 100))
		{
			return false;
		}

		if (!ValidateRoom<patterns::Wall, patterns::Door, patterns::Wall, patterns::Wall>(maze, 200))
		{
			return false;
		}

		return true;
	}

	bool Validator::MazeFactoryMazeConfiguration(patterns::Maze* maze)
	{
		if (!ValidateRoomType<patterns::Room>(maze, 100))
		{
			return false;
		}

		if (!ValidateRoom<patterns::Door, patterns::Wall, patterns::Wall, patterns::Wall>(maze, 100))
		{
			return false;
		}

		if (!ValidateRoom<patterns::Wall, patterns::Door, patterns::Wall, patterns::Wall>(maze, 200))
		{
			return false;
		}

		return true;
	}

	bool Validator::StandardMazeBuilderConfiguration(patterns::Maze* maze)
	{
		if (!ValidateRoomType<patterns::Room>(maze, 1000))
		{
			return false;
		}

		if (!ValidateRoom<patterns::Door, patterns::Wall, patterns::Wall, patterns::Wall>(maze, 1000))
		{
			return false;
		}

		if (!ValidateRoom<patterns::Wall, patterns::Door, patterns::Wall, patterns::Wall>(maze, 2000))
		{
			return false;
		}

		return true;
	}

	template<class east_side, class west_side, class north_side, class south_side>
	bool Validator::ValidateRoom(patterns::Maze* maze, int room_number)
	{
		auto room = maze->GetRoom(room_number);
		if (!room)
		{
			return false;
		}

		if (!ValidateSide<east_side>(room, patterns::East))
		{
			return false;
		}

		if (!ValidateSide<west_side>(room, patterns::West))
		{
			return false;
		}
		if (!ValidateSide<north_side>(room, patterns::North))
		{
			return false;
		}

		if (!ValidateSide<south_side>(room, patterns::South))
		{
			return false;
		}

		return true;
	}

	template<class room_type>
	bool Validator::ValidateRoomType(patterns::Maze* maze, int room_number)
	{
		auto room = maze->GetRoom(room_number);
		if (!room)
		{
			return false;
		}

		auto specific_room = dynamic_cast<room_type*>(room);
		if (!specific_room)
		{
			return false;
		}

		return true;
	}

	template<class side_type>
	bool Validator::ValidateSide(patterns::Room* room, patterns::Direction direction)
	{
		auto side = room->GetSide(direction);
		auto element = dynamic_cast<side_type*>(side);
		if (!element)
		{
			return false;
		}
		return true;
	}
};
