// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "card.h"

namespace operational
{
namespace visitor
{
Card::Card(const std::string& name) :name_(name), price_(0) {}

std::string Card::name() const
{
	return name_;
}

double Card::price() const
{
	return price_;
}

void Card::price(const double& price)
{
	price_ = price;
}

double Card::GetSilverPrice()
{
	return 1.0 * price();
}

double Card::GetGoldPrice()
{
	return 2.0 * price();
}

void Card::Accept(EquipmentVisitorInterface& visitor)
{
	visitor.VisitCard(this);
}
}}
