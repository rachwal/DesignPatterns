// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "floppy_disk.h"

namespace structural
{
namespace composite
{
FloppyDisk::FloppyDisk(const std::string& name) :name_(name), power_(0), price_(0) { }

FloppyDisk::FloppyDisk() : FloppyDisk("") { }

std::string FloppyDisk::name() const
{
	return name_;
}

Currency FloppyDisk::price() const
{
	return price_;
}

void FloppyDisk::price(const Currency& price)
{
	price_ = price;
}

Watt FloppyDisk::power() const
{
	return power_;
}

void FloppyDisk::power(const Watt& power)
{
	power_ = power;
}

Currency FloppyDisk::NetPrice()
{
	return price_;
}

Currency FloppyDisk::DiscountPrice()
{
	auto discount_price = price_.value() * 0.9;
	return Currency(discount_price);
}
}}
