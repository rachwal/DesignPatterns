// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEPARTS_DOOR_H_
#define CREATIONAL_MAZEPARTS_DOOR_H_

#include "map_site_interface.h"
#include "room.h"

namespace creational
{
	class Door : public MapSiteInterface
	{
	public:
		explicit Door(const Room& first_room, const Room& second_room);
		Door(const Door&);

		virtual Door* Clone() const;
		virtual void Enter() override;
		void Initialize(const Room& first_room, const Room& second_room);
		bool is_open() const;
		Room* OtherSideFrom(const Room& room) const;
		virtual bool entered() const;

	private:
		Room* room1_;
		Room* room2_;
		bool is_open_;
		bool entered_;
	};
}

#endif
