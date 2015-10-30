// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef CREATIONALTESTS_UTILS_VALIDATOR_H_
#define CREATIONALTESTS_UTILS_VALIDATOR_H_

#include "../../../Creational/src/mazeparts/maze.h"

namespace creationaltests
{
namespace validation
{
using namespace creational::commons;

class Validator
{
	public:
	static bool BasicMazeConfiguration(Maze* maze);
	static bool FactoryMethodsMazeConfiguration(Maze* maze);
	static bool BombedMazeFactoryMazeConfiguration(Maze* maze);
	static bool EnchantedMazeFactoryMazeConfiguration(Maze* maze);
	static bool MazeFactoryMazeConfiguration(Maze* maze);
	static bool StandardMazeBuilderConfiguration(Maze* maze);

	private:
	template<class east_side, class west_side, class north_side, class south_side>
	static bool ValidateRoom(Maze* maze, int room_number);

	template<class room_type>
	static bool ValidateRoomType(Maze* maze, int room_number);

	template<class side_type>
	static bool ValidateSide(Room* room, Direction direction);
};
}}
#endif
