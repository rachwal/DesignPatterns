// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_ABSTRACTFACTORY_MAZE_FACTORY_H_
#define CREATIONAL_ABSTRACTFACTORY_MAZE_FACTORY_H_

#include "maze_factory_interface.h"

namespace creational
{
namespace abstractfactory
{
class MazeFactory : public MazeFactoryInterface
{
	public:
	~MazeFactory() override;

	virtual commons::Maze *MakeMaze() const override;
	virtual commons::Wall *MakeWall() const override;
	virtual commons::Room *MakeRoom(const int& room_number) const override;
	virtual commons::Door *MakeDoor(const commons::Room& first_room, const commons::Room& second_room) const override;

	static MazeFactoryInterface *Instance();

	protected:
	MazeFactory();

	private:
	static MazeFactoryInterface* instance_;
};
}}

#endif
