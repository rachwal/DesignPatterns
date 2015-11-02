// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Structural/src/composite/bus.h"
#include "../../../Structural/src/composite/cabinet.h"
#include "../../../Structural/src/composite/card.h"

namespace structuraltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace structural::composite;

TEST_CLASS(CompositeTest)
{
	public:
	CompositeTest() { }

	~CompositeTest() { }

	TEST_METHOD(ShouldCreateBusWithName)
	{
		//GIVEN
		auto expected_name = "composite bus";
		auto bus = new Bus(expected_name);

		//WHEN
		auto bus_name = bus->name();

		//THEN
		Assert::AreEqual(expected_name, bus_name.c_str());
	}

	TEST_METHOD(ShouldSetBusPrice)
	{
		//GIVEN
		auto expected_price = Currency(3);
		auto bus = new Bus("test bus");
		bus->price(expected_price);

		//WHEN
		auto bus_price = bus->price();
		auto bus_net_price = bus->NetPrice();

		//THEN
		Assert::IsTrue(expected_price == bus_price);
		Assert::IsTrue(expected_price == bus_net_price);
	}

	TEST_METHOD(ShouldReturnPriceOfBusWithCabinetComposite)
	{
		//GIVEN
		auto expected_bus_price = Currency(3);
		auto bus = new Bus("test bus");
		bus->price(expected_bus_price);

		auto expected_cabinet_price = Currency(2);
		auto cabinet = new Cabinet("test cabinet");
		cabinet->price(expected_cabinet_price);

		auto expected_total_price = Currency(5);

		//WHEN
		bus->Add(cabinet);
		auto bus_price = bus->price();
		auto bus_net_price = bus->NetPrice();

		//THEN
		Assert::IsTrue(expected_bus_price == bus_price);
		Assert::IsTrue(expected_total_price == bus_net_price);
	}

	TEST_METHOD(ShouldReturnLeafPrice)
	{
		//GIVEN
		auto expected_card_price = Currency(3);
		auto card = new Card();
		card->price(expected_card_price);

		auto expected_total_price = Currency(3);

		//WHEN
		auto card_price = card->price();
		auto card_net_price = card->NetPrice();

		//THEN
		Assert::IsTrue(expected_card_price == card_price);
		Assert::IsTrue(expected_total_price == card_net_price);
	}

	TEST_METHOD(ShouldReturnCompositeWithALeafPrice)
	{
		//GIVEN
		auto expected_bus_price = Currency(3);
		auto bus = new Bus();
		bus->price(expected_bus_price);

		auto expected_card_price = Currency(3);
		auto card = new Card();
		card->price(expected_card_price);

		auto expected_total_price = Currency(6);

		//WHEN
		bus->Add(card);
		auto bus_price = bus->price();
		auto bus_net_price = bus->NetPrice();

		//THEN
		Assert::IsTrue(expected_bus_price == bus_price);
		Assert::IsTrue(expected_total_price == bus_net_price);
	}
};
}
