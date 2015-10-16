// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEPARTS_BOMBED_WALL_H_
#define CREATIONAL_MAZEPARTS_BOMBED_WALL_H_

#include "wall.h"

namespace patterns
{
	class BombedWall : public Wall
	{
	public:
		explicit BombedWall(const bool& bombed);
		BombedWall(const BombedWall&);

		virtual BombedWall* Clone() const override;
		virtual void Enter() override;
		void Intialize(const bool& bombed);
		bool bombed() const;

	private:
		bool bombed_;
	};
}

#endif
