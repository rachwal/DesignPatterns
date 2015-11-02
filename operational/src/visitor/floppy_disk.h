// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_VISITOR_FLOPPY_DISK_H_
#define OPERATIONAL_VISITOR_FLOPPY_DISK_H_

#include "visited_equipment_interface.h"

namespace operational
{
namespace visitor
{
class FloppyDisk : public VisitedEquipmentInterface, public FloppyDiskInterface
{
	public:
	explicit FloppyDisk(const std::string& name);

	std::string name() const override;

	double price() const override;
	void price(const double&) override;

	double GetBoxPrice() override;

	virtual void Accept(EquipmentVisitorInterface&) override;

	private:
	std::string name_;
	double price_;
};
}}

#endif
