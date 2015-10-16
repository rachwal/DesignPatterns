// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "room_with_a_bomb.h"

namespace patterns
{
	RoomWithABomb::RoomWithABomb(const int& room_number, const bool& bombed) :Room(room_number), has_bomb_(bombed)
	{
	}

	RoomWithABomb::RoomWithABomb(const RoomWithABomb& room) : Room(room.room_number_), has_bomb_(room.has_bomb_)
	{
	}

	bool RoomWithABomb::has_bomb() const
	{
		return has_bomb_;
	}

	RoomWithABomb* RoomWithABomb::Clone() const
	{
		return new RoomWithABomb(*this);
	}

	void RoomWithABomb::Initialize(const bool& bombed)
	{
		has_bomb_ = bombed;
	}
}
