// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "wall.h"

namespace creational
{
	Wall::Wall() :entered_(false)
	{
	}

	Wall::Wall(const Wall& wall)
	{
		entered_ = wall.entered_;
	}

	Wall::~Wall()
	{
	}

	Wall* Wall::Clone() const
	{
		return new Wall(*this);
	}

	void Wall::Enter()
	{
		entered_ = true;
	}

	bool Wall::entered() const
	{
		return entered_;
	}
}
