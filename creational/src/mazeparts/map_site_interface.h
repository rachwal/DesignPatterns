// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEPARTS_MAP_SITE_INTERFACE_H_
#define CREATIONAL_MAZEPARTS_MAP_SITE_INTERFACE_H_

namespace creational
{
namespace commons
{
class MapSiteInterface
{
	public:
	virtual ~MapSiteInterface() { }

	virtual void Enter() = 0;
};
}
}

#endif

