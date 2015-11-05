// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_VISITOR_CHASSIS_H_
#define OPERATIONAL_VISITOR_CHASSIS_H_

#include "chassis_interface.h"
#include "visited_equipment_interface.h"

#include "../iterator/list.h"

namespace operational
{
namespace visitor
{
class Chassis : public VisitedEquipmentInterface, public ChassisInterface
{
	public:
	explicit Chassis(const std::string& name);
	~Chassis() override;

	std::string name() const override;

	double price() const override;
	void price(const double&) override;

	double GetPrice() override;

	void Accept(EquipmentVisitorInterface&) override;

	void AddPart(VisitedEquipmentInterface*) const;

	private:
	std::string name_;
	double price_;
	iterator::List<VisitedEquipmentInterface*>* parts_;
};
}
}

#endif

