// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_PROTOTYPE_MAZE_PROTOTYPE_FACTORY_H_
#define CREATIONAL_PROTOTYPE_MAZE_PROTOTYPE_FACTORY_H_

#include "../abstractfactory/maze_factory.h"

namespace creational
{
namespace prototype
{
class MazePrototypeFactory : public abstractfactory::MazeFactoryInterface
{
	public:
	MazePrototypeFactory(commons::Maze*, commons::Wall*, commons::Room*, commons::Door*);

	virtual commons::Maze *MakeMaze() const override;
	virtual commons::Room *MakeRoom(const int& room_number) const override;
	virtual commons::Wall *MakeWall() const override;
	virtual commons::Door *MakeDoor(const commons::Room& first_room, const commons::Room& second_room) const override;

	private:
	commons::Maze* prototype_maze_;
	commons::Room* prototype_room_;
	commons::Wall* prototype_wall_;
	commons::Door* prototype_door_;
};
}}

#endif
