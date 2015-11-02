// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_COMPOSITE_FLOPPY_DISK_H_
#define STRUCTURAL_COMPOSITE_FLOPPY_DISK_H_

#include "equipment_interface.h"

#include <string>

namespace structural
{
namespace composite
{
class FloppyDisk : public EquipmentInterface
{
	public:
	FloppyDisk();
	explicit FloppyDisk(const std::string&);

	std::string name() const override;
	Currency price() const override;
	void price(const Currency&) override;
	Watt power() const override;
	void power(const Watt&) override;
	Currency NetPrice() override;
	Currency DiscountPrice() override;

	private:
	std::string name_;
	Watt power_;
	Currency price_;
};
}}

#endif
