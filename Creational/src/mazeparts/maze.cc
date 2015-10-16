// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "maze.h"

namespace patterns
{
	Maze::Maze()
	{
	}

	Maze::Maze(const Maze& maze)
	{
		rooms_ = std::map<int, Room*>(maze.rooms_);
	}

	Maze::~Maze()
	{
		auto itr = rooms_.begin();
		while (itr != rooms_.end())
		{
			itr = rooms_.erase(itr);
		}
	}

	Room* Maze::GetRoom(const int& room_number) const
	{
		return rooms_.at(room_number);
	}

	void Maze::AddRoom(Room* room)
	{
		auto room_number = room->room_number();
		rooms_.insert_or_assign(room_number, room);
	}

	Maze* Maze::Clone() const
	{
		return new Maze(*this);
	}
}
