// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "maze_factory.h"

#include <mutex>

namespace creational
{
	MazeFactory::MazeFactory()
	{
		instance_ = nullptr;
	}

	MazeFactory::~MazeFactory()
	{
		delete instance_;
	}

	Maze* MazeFactory::MakeMaze() const
	{
		return new Maze;
	}

	Wall* MazeFactory::MakeWall() const
	{
		return new Wall;
	}

	Room* MazeFactory::MakeRoom(const int& room_number) const
	{
		return new Room(room_number);
	}

	Door* MazeFactory::MakeDoor(const Room& first_room, const Room& second_room) const
	{
		return new Door(first_room, second_room);
	}

	MazeFactoryInterface* MazeFactory::instance_;

	MazeFactoryInterface* MazeFactory::Instance()
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
}
