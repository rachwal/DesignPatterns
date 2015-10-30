// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_COMPOSITE_COMPOSITE_EQUIPMENT_H_
#define STRUCTURAL_COMPOSITE_COMPOSITE_EQUIPMENT_H_

#include <string>

#include "../../../Operational/src/iterator/list.h"
#include "../../../foundation/src/equipment_interface.h"

namespace structural
{
namespace composite
{
class CompositeEquipment : public foundation::EquipmentInterface
{
	public:
	virtual std::string name() const override;

	virtual foundation::Currency price() const override;
	virtual void price(const foundation::Currency&) override;

	virtual foundation::Watt power() const override;
	virtual void power(const foundation::Watt&) override;

	foundation::Currency NetPrice() override;
	foundation::Currency DiscountPrice() override;

	virtual void Add(EquipmentInterface*);
	virtual void Remove(EquipmentInterface*);

	virtual operational::iterator::IteratorInterface<EquipmentInterface*> *CreateIterator();

	protected:
	CompositeEquipment();
	explicit CompositeEquipment(const std::string& name);
	~CompositeEquipment();

	private:
	std::string name_;
	foundation::Currency price_;
	foundation::Watt power_;

	operational::iterator::List<EquipmentInterface*>* equipment_;
};
}}

#endif
