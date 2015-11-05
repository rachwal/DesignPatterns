// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_COMPOSITE_COMPOSITE_EQUIPMENT_H_
#define STRUCTURAL_COMPOSITE_COMPOSITE_EQUIPMENT_H_

#include "equipment_interface.h"

#include <string>

#include "../../../operational/src/iterator/list.h"

namespace structural
{
namespace composite
{
class CompositeEquipment : public EquipmentInterface
{
	public:
	virtual std::string name() const override;

	virtual Currency price() const override;
	virtual void price(const Currency&) override;

	virtual Watt power() const override;
	virtual void power(const Watt&) override;

	Currency NetPrice() override;
	Currency DiscountPrice() override;

	virtual void Add(EquipmentInterface*);
	virtual void Remove(EquipmentInterface*);

	virtual operational::iterator::IteratorInterface<EquipmentInterface*> *CreateIterator();

	protected:
	CompositeEquipment();
	explicit CompositeEquipment(const std::string& name);
	~CompositeEquipment();

	private:
	std::string name_;
	Currency price_;
	Watt power_;

	operational::iterator::List<EquipmentInterface*>* equipment_;
};
}
}

#endif

