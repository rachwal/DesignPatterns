// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef CREATIONALTESTS_UTILS_VALIDATOR_H_
#define CREATIONALTESTS_UTILS_VALIDATOR_H_
#include "../../../Creational/src/mazeparts/maze.h"

namespace patternstests
{
	class Validator
	{
	public:
		static bool BasicMazeConfiguration(patterns::Maze* maze);
		static bool FactoryMethodsMazeConfiguration(patterns::Maze* maze);
		static bool BombedMazeFactoryMazeConfiguration(patterns::Maze* maze);
		static bool EnchantedMazeFactoryMazeConfiguration(patterns::Maze* maze);
		static bool MazeFactoryMazeConfiguration(patterns::Maze* maze);
		static bool StandardMazeBuilderConfiguration(patterns::Maze* maze);
	};
}

#endif
