// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "card.h"

namespace structural
{
namespace composite
{
Card::Card(const std::string& name) : name_(name), power_(0), price_(0) { }

Card::Card() : Card("") { }

std::string Card::name() const
{
	return name_;
}

Currency Card::price() const
{
	return price_;
}

void Card::price(const Currency& price)
{
	price_ = price;
}

Watt Card::power() const
{
	return power_;
}

void Card::power(const Watt& power)
{
	power_ = power;
}

Currency Card::NetPrice()
{
	return price_;
}

Currency Card::DiscountPrice()
{
	auto discount_price = price_.value() * 0.9;
	return Currency(discount_price);
}
}
}

