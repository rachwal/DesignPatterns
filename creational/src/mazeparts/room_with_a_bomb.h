// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEPARTS_ROOM_WITH_A_BOMB_H_
#define CREATIONAL_MAZEPARTS_ROOM_WITH_A_BOMB_H_

#include "room.h"

namespace creational
{
namespace commons
{
class RoomWithABomb : public Room
{
	public:
	RoomWithABomb(const RoomWithABomb&);
	explicit RoomWithABomb(const int& room_number, const bool& has_bomb);

	virtual RoomWithABomb *Clone() const override;
	bool has_bomb() const;
	void Initialize(const bool& bombed);

	private:
	bool has_bomb_;
};
}
}

#endif

