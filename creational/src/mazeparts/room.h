// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEPARTS_ROOM_H_
#define CREATIONAL_MAZEPARTS_ROOM_H_

#include "map_site_interface.h"
#include "direction.h"

namespace creational
{
namespace commons
{
class Room : public MapSiteInterface
{
	public:
	explicit Room(const int& room_number);
	Room(const Room& room);

	virtual Room *Clone() const;
	virtual void Enter() override;
	virtual bool entered() const;
	MapSiteInterface *GetSide(const Direction&) const;
	int room_number() const;
	void SetSide(const Direction&, MapSiteInterface*);

	protected:
	int room_number_;

	private:
	MapSiteInterface* sides_[4];
	bool enetered_;
};
}
}

#endif

