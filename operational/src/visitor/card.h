// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_VISITOR_CARD_H_
#define OPERATIONAL_VISITOR_CARD_H_

#include "visited_equipment_interface.h"
#include "card_interface.h"

namespace operational
{
namespace visitor
{
class Card :public VisitedEquipmentInterface, public CardInterface
{
	public:
	explicit Card(const std::string& name);

	std::string name() const override;

	double price() const override;
	void price(const double&) override;

	double GetSilverPrice() override;
	double GetGoldPrice() override;

	void Accept(EquipmentVisitorInterface&) override;

	private:
	std::string name_;
	double price_;
};
}}

#endif
