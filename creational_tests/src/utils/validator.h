// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef CREATIONALTESTS_UTILS_VALIDATOR_H_
#define CREATIONALTESTS_UTILS_VALIDATOR_H_

#include "../../../Creational/src/mazeparts/maze.h"

namespace creationaltests
{
	namespace validation
	{
		class Validator
		{
		public:
			static bool BasicMazeConfiguration(creational::Maze* maze);
			static bool FactoryMethodsMazeConfiguration(creational::Maze* maze);
			static bool BombedMazeFactoryMazeConfiguration(creational::Maze* maze);
			static bool EnchantedMazeFactoryMazeConfiguration(creational::Maze* maze);
			static bool MazeFactoryMazeConfiguration(creational::Maze* maze);
			static bool StandardMazeBuilderConfiguration(creational::Maze* maze);

		private:
			template <class east_side, class west_side, class north_side, class south_side>
			static bool ValidateRoom(creational::Maze* maze, int room_number);

			template <class room_type>
			static bool ValidateRoomType(creational::Maze* maze, int room_number);

			template <class side_type>
			static bool ValidateSide(creational::Room* room, creational::Direction direction);
		};
	}
}
#endif
