// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../operational/src/visitor/inventory_visitor.h"
#include "../../../operational/src/visitor/chassis.h"
#include "../../../operational/src/visitor/bus.h"
#include "../../../operational/src/visitor/floppy_disk.h"
#include "../../../operational/src/visitor/card.h"
#include "../../../operational/src/visitor/pricing_visitor.h"

namespace operationaltests
{
using namespace operational::visitor;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(VisitorTest)
{
	public:
	VisitorTest() { }

	~VisitorTest() { }

	TEST_METHOD(ShouldVisitSingleElement)
	{
		//GIVEN
		InventoryVisitor visitor;

		auto bus = new Bus("test bus");

		//WHEN
		bus->Accept(visitor);

		//THEN
		auto inventory = visitor.GetInventory();

		Assert::AreEqual(1, inventory->count());

		delete bus;
	}

	TEST_METHOD(ShouldVisitCompositeElement)
	{
		//GIVEN
		InventoryVisitor visitor;
		auto card = new Card("");
		auto floppy = new FloppyDisk("");
		auto bus = new Bus("test bus");

		auto chassis = new Chassis("parent");
		chassis->AddPart(card);
		chassis->AddPart(floppy);
		chassis->AddPart(bus);

		//WHEN
		chassis->Accept(visitor);

		//THEN
		auto inventory = visitor.GetInventory();

		Assert::AreEqual(4, inventory->count());

		delete chassis;
	}

	TEST_METHOD(ShouldVisitCalculateTotalPriceOfCompositeElement)
	{
		//GIVEN
		auto expected_price = 26.0;

		PricingVisitor visitor;

		auto card = new Card("");
		card->price(1);

		auto floppy = new FloppyDisk("");
		floppy->price(2);

		auto bus = new Bus("");
		bus->price(3);

		auto child_chassis = new Chassis("child");
		child_chassis->price(4);
		child_chassis->AddPart(card);
		child_chassis->AddPart(floppy);
		child_chassis->AddPart(bus);

		auto chassis = new Chassis("parent");
		chassis->price(1);
		chassis->AddPart(child_chassis);

		//WHEN
		chassis->Accept(visitor);

		//THEN
		auto price = visitor.GetTotalPrice();

		Assert::AreEqual(expected_price, price);

		delete chassis;
	}
};
}

