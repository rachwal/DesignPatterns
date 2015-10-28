// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_COMPOSITE_CARD_H_
#define STRUCTURAL_COMPOSITE_CARD_H_

#include "../../../foundation/src/equipment_interface.h"

#include <string>

namespace structural
{
	class Card : public foundation::EquipmentInterface
	{
	public:
		explicit Card(const std::string& name);
		Card();

		std::string name() const override;
		foundation::Currency price() const override;
		void price(const foundation::Currency&) override;
		foundation::Watt power() const override;
		void power(const foundation::Watt&) override;
		foundation::Currency NetPrice() override;
		foundation::Currency DiscountPrice() override;

	private:
		std::string name_;
		foundation::Watt power_;
		foundation::Currency price_;
	};
}

#endif
