// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "door.h"

namespace creational
{
	Door::Door(const Room& first_room, const Room& second_room)
	{
		room1_ = new Room(first_room);
		room2_ = new Room(second_room);
		is_open_ = false;
		entered_ = false;
	}

	Door::Door(const Door& door)
	{
		room1_ = door.room1_;
		room2_ = door.room2_;
		is_open_ = door.is_open_;
		entered_ = door.entered_;
	}

	void Door::Initialize(const Room& first_room, const Room& second_room)
	{
		room1_ = new Room(first_room);
		room2_ = new Room(second_room);
	}

	bool Door::is_open() const
	{
		return is_open_;
	}

	void Door::Enter()
	{
		entered_ = true;
	}

	Room* Door::OtherSideFrom(const Room& room) const
	{
		if (room1_->room_number() == room.room_number())
			return room2_;
		if (room2_->room_number() == room.room_number())
			return room1_;
		return nullptr;
	}

	bool Door::entered() const
	{
		return entered_;
	}

	Door* Door::Clone() const
	{
		return new Door(*this);
	}
}
