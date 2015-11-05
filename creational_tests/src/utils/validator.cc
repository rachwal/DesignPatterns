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

namespace creationaltests
{
namespace validation
{
bool Validator::BasicMazeConfiguration(Maze* maze)
{
	if (!ValidateRoom<Door, Wall, Wall, Wall>(maze, 1))
	{
		return false;
	}

	if (!ValidateRoom<Wall, Door, Wall, Wall>(maze, 2))
	{
		return false;
	}

	return true;
}

bool Validator::FactoryMethodsMazeConfiguration(Maze* maze)
{
	if (!ValidateRoom<Door, Wall, Wall, Wall>(maze, 12))
	{
		return false;
	}

	if (!ValidateRoom<Wall, Door, Wall, Wall>(maze, 23))
	{
		return false;
	}

	return true;
}

bool Validator::BombedMazeFactoryMazeConfiguration(Maze* maze)
{
	if (!ValidateRoomType<RoomWithABomb>(maze, 100))
	{
		return false;
	}

	if (!ValidateRoom<Door, Wall, Wall, BombedWall>(maze, 100))
	{
		return false;
	}

	if (!ValidateRoom<Wall, Door, Wall, Wall>(maze, 200))
	{
		return false;
	}

	return true;
}

bool Validator::EnchantedMazeFactoryMazeConfiguration(Maze* maze)
{
	if (!ValidateRoomType<EnchantedRoom>(maze, 100))
	{
		return false;
	}

	if (!ValidateRoom<DoorNeedingSpell, Wall, Wall, Wall>(maze, 100))
	{
		return false;
	}

	if (!ValidateRoom<Wall, Door, Wall, Wall>(maze, 200))
	{
		return false;
	}

	return true;
}

bool Validator::MazeFactoryMazeConfiguration(Maze* maze)
{
	if (!ValidateRoomType<Room>(maze, 100))
	{
		return false;
	}

	if (!ValidateRoom<Door, Wall, Wall, Wall>(maze, 100))
	{
		return false;
	}

	if (!ValidateRoom<Wall, Door, Wall, Wall>(maze, 200))
	{
		return false;
	}

	return true;
}

bool Validator::StandardMazeBuilderConfiguration(Maze* maze)
{
	if (!ValidateRoomType<Room>(maze, 1000))
	{
		return false;
	}

	if (!ValidateRoom<Door, Wall, Wall, Wall>(maze, 1000))
	{
		return false;
	}

	if (!ValidateRoom<Wall, Door, Wall, Wall>(maze, 2000))
	{
		return false;
	}

	return true;
}

template<class east_side, class west_side, class north_side, class south_side>
bool Validator::ValidateRoom(Maze* maze, int room_number)
{
	auto room = maze->GetRoom(room_number);
	if (!room)
	{
		return false;
	}

	if (!ValidateSide<east_side>(room, East))
	{
		return false;
	}

	if (!ValidateSide<west_side>(room, West))
	{
		return false;
	}
	if (!ValidateSide<north_side>(room, North))
	{
		return false;
	}

	if (!ValidateSide<south_side>(room, South))
	{
		return false;
	}

	return true;
}

template<class room_type>
bool Validator::ValidateRoomType(Maze* maze, int room_number)
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
bool Validator::ValidateSide(Room* room, Direction direction)
{
	auto side = room->GetSide(direction);
	auto element = dynamic_cast<side_type*>(side);
	if (!element)
	{
		return false;
	}
	return true;
}
}
};

