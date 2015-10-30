// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "maze_factory.h"

#include <mutex>

namespace creational
{
namespace abstractfactory
{
MazeFactory::MazeFactory()
{
	instance_ = nullptr;
}

MazeFactory::~MazeFactory()
{
	delete instance_;
}

commons::Maze *MazeFactory::MakeMaze() const
{
	return new commons::Maze;
}

commons::Wall *MazeFactory::MakeWall() const
{
	return new commons::Wall;
}

commons::Room *MazeFactory::MakeRoom(const int& room_number) const
{
	return new commons::Room(room_number);
}

commons::Door *MazeFactory::MakeDoor(const commons::Room& first_room, const commons::Room& second_room) const
{
	return new commons::Door(first_room, second_room);
}

MazeFactoryInterface* MazeFactory::instance_;

MazeFactoryInterface *MazeFactory::Instance()
{
	if (!instance_)
	{
		std::mutex m;
		m.lock();
		if (!instance_)
		{
			auto factory = new MazeFactory;
			instance_ = factory;
		}
		m.unlock();
	}
	return instance_;
}
}}
