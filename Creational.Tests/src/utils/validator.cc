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
		try
		{
			auto first_room = maze->GetRoom(1);
			auto first_room_east_side = first_room->GetSide(patterns::East);
			auto first_room_west_side = first_room->GetSide(patterns::West);

			auto room = dynamic_cast<patterns::Room*>(first_room);
			if (!room)
			{
				return false;
			}

			auto door = dynamic_cast<patterns::Door*>(first_room_east_side);
			if (!door)
			{
				return false;
			}

			auto wall = dynamic_cast<patterns::Wall*>(first_room_west_side);
			if (!wall)
			{
				return false;
			}

			auto second_room = maze->GetRoom(2);
		}
		catch (...)
		{
			return false;
		}
		return true;
	}

	bool Validator::FactoryMethodsMazeConfiguration(patterns::Maze* maze)
	{
		try
		{
			auto first_room = maze->GetRoom(12);
			auto first_room_east_side = first_room->GetSide(patterns::East);
			auto first_room_north_side = first_room->GetSide(patterns::North);

			auto room = dynamic_cast<patterns::Room*>(first_room);
			if (!room)
			{
				return false;
			}

			auto door = dynamic_cast<patterns::Door*>(first_room_east_side);
			if (!door)
			{
				return false;
			}

			auto wall = dynamic_cast<patterns::Wall*>(first_room_north_side);
			if (!wall)
			{
				return false;
			}

			auto second_room = maze->GetRoom(23);
		}
		catch (...)
		{
			return false;
		}
		return true;
	}

	bool Validator::BombedMazeFactoryMazeConfiguration(patterns::Maze* maze)
	{
		try
		{
			auto first_room = maze->GetRoom(100);
			auto first_room_east_side = first_room->GetSide(patterns::East);
			auto first_room_south_side = first_room->GetSide(patterns::North);

			auto room = dynamic_cast<patterns::RoomWithABomb*>(first_room);
			if (!room)
			{
				return false;
			}

			auto door = dynamic_cast<patterns::Door*>(first_room_east_side);
			if (!door)
			{
				return false;
			}

			auto wall = dynamic_cast<patterns::BombedWall*>(first_room_south_side);
			if (!wall)
			{
				return false;
			}

			auto second_room = maze->GetRoom(200);
		}
		catch (...)
		{
			return false;
		}
		return true;
	}

	bool Validator::EnchantedMazeFactoryMazeConfiguration(patterns::Maze* maze)
	{
		try
		{
			auto first_room = maze->GetRoom(100);
			auto first_room_east_side = first_room->GetSide(patterns::East);
			auto first_room_south_side = first_room->GetSide(patterns::North);

			auto room = dynamic_cast<patterns::EnchantedRoom*>(first_room);
			if (!room)
			{
				return false;
			}

			auto door = dynamic_cast<patterns::DoorNeedingSpell*>(first_room_east_side);
			if (!door)
			{
				return false;
			}

			auto wall = dynamic_cast<patterns::Wall*>(first_room_south_side);
			if (!wall)
			{
				return false;
			}

			auto second_room = maze->GetRoom(200);
		}
		catch (...)
		{
			return false;
		}
		return true;
	}

	bool Validator::MazeFactoryMazeConfiguration(patterns::Maze* maze)
	{
		try
		{
			auto first_room = maze->GetRoom(100);
			auto first_room_east_side = first_room->GetSide(patterns::East);
			auto first_room_south_side = first_room->GetSide(patterns::North);

			auto room = dynamic_cast<patterns::Room*>(first_room);
			if (!room)
			{
				return false;
			}

			auto door = dynamic_cast<patterns::Door*>(first_room_east_side);
			if (!door)
			{
				return false;
			}

			auto wall = dynamic_cast<patterns::Wall*>(first_room_south_side);
			if (!wall)
			{
				return false;
			}

			auto second_room = maze->GetRoom(200);
		}
		catch (...)
		{
			return false;
		}
		return true;
	}

	bool Validator::StandardMazeBuilderConfiguration(patterns::Maze* maze)
	{
		try
		{
			auto first_room = maze->GetRoom(1000);

			auto room = dynamic_cast<patterns::Room*>(first_room);
			if (!room)
			{
				return false;
			}

			auto second_room = maze->GetRoom(2000);
		}
		catch (...)
		{
			return false;
		}
		return true;
	}
};
