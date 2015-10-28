// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEPARTS_WALL_H_
#define CREATIONAL_MAZEPARTS_WALL_H_

#include "map_site_interface.h"

namespace creational
{
	class Wall : public MapSiteInterface
	{
	public:
		Wall();
		Wall(const Wall&);
		virtual ~Wall() override;

		virtual Wall* Clone() const;
		virtual void Enter() override;
		virtual bool entered() const;

	protected:
		bool entered_;
	};
}

#endif
