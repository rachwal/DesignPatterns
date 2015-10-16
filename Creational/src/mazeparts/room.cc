// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "room.h"

namespace patterns
{
	Room::Room(const int& room_number) :room_number_(room_number)
	{
		enetered_ = false;

		for (auto i = 0; i < 4; i++)
		{
			sides_[i] = nullptr;
		}
	}

	Room::Room(const Room& room) :room_number_(room.room_number_), enetered_(room.enetered_)
	{
		for (auto i = 0; i < 4; i++)
		{
			sides_[i] = room.sides_[i];
		}
	}

	Room* Room::Clone() const
	{
		return new Room(*this);
	}

	MapSiteInterface* Room::GetSide(const Direction& direction) const
	{
		return sides_[direction];
	}

	void Room::SetSide(const Direction& direction, MapSiteInterface* side)
	{
		sides_[direction] = side;
	}

	int Room::room_number() const
	{
		return room_number_;
	}

	bool Room::entered() const
	{
		return enetered_;
	}

	void Room::Enter()
	{
		enetered_ = true;
	}
}
