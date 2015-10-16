// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_PROTOTYPE_MAZE_PROTOTYPE_FACTORY_H_
#define CREATIONAL_PROTOTYPE_MAZE_PROTOTYPE_FACTORY_H_

#include "../abstractfactory/maze_factory.h"

namespace patterns
{
	class MazePrototypeFactory : public MazeFactoryInterface
	{
	public:
		MazePrototypeFactory(Maze*, Wall*, Room*, Door*);

		virtual Maze* MakeMaze() const override;
		virtual Room* MakeRoom(const int& room_number) const override;
		virtual Wall* MakeWall() const override;
		virtual Door* MakeDoor(const Room& first_room, const Room& second_room) const override;

	private:
		Maze* prototype_maze_;
		Room* prototype_room_;
		Wall* prototype_wall_;
		Door* prototype_door_;
	};
}

#endif
