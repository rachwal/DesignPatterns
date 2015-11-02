// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_VISITOR_CHASSIS_INTERFACE_H_
#define OPERATIONAL_VISITOR_CHASSIS_INTERFACE_H_

namespace operational
{
namespace visitor
{
class ChassisInterface
{
	public:
	virtual ~ChassisInterface() {}

	virtual double GetPrice() = 0;
};
}}

#endif
