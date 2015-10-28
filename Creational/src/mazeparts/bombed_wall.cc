// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "bombed_wall.h"

namespace creational
{
	BombedWall::BombedWall(const bool& bombed) :bombed_(bombed)
	{
	}

	BombedWall::BombedWall(const BombedWall& bombed_wall) : Wall(bombed_wall)
	{
		bombed_ = bombed_wall.bombed_;
	}

	BombedWall* BombedWall::Clone() const
	{
		return new BombedWall(*this);
	}

	void BombedWall::Intialize(const bool& bombed)
	{
		bombed_ = bombed;
	}

	bool BombedWall::bombed() const
	{
		return bombed_;
	}

	void BombedWall::Enter()
	{
		entered_ = true;
	}
}
