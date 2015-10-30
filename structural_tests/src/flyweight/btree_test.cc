// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Structural/src/flyweight/glyph_context.h"

namespace structuraltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace structural::flyweight;

TEST_CLASS(BTreeTest)
{
	public:
	BTreeTest() { }

	~BTreeTest() { }

	TEST_METHOD(ShouldCompareFonts)
	{
		//WHEN
		Font first_font("test");
		Font second_font("test");

		//THEN
		Assert::IsTrue(first_font == second_font);
	}

	TEST_METHOD(ShouldAddFirstPointWithIndexOfOne)
	{
		//GIVEN
		auto btree = new BTree();
		Font first_font("test");

		//WHEN
		btree->Set(&first_font, 1, 1);
		auto font = btree->Get(1);

		//THEN
		Assert::IsTrue(first_font == *font);
	}

	TEST_METHOD(ShouldGetFontByIndex)
	{
		//GIVEN
		auto btree = new BTree();
		Font first_font("test 1");
		Font second_font("test 2");

		//WHEN
		btree->Set(&first_font, 1, 1);
		btree->Set(&second_font, 2, 1);

		auto first = btree->Get(1);
		auto second = btree->Get(2);

		//THEN
		Assert::IsTrue(first_font == *first);
		Assert::IsTrue(second_font == *second);
	}

	TEST_METHOD(ShouldGetFontByIndexConsideringAlsoCapacityOfFontBlock)
	{
		//GIVEN
		auto btree = new BTree();
		Font first_font("test 1");
		Font second_font("test 2");

		//WHEN
		btree->Set(&first_font, 1, 3);
		btree->Set(&second_font, 4, 1);

		auto first = btree->Get(1);
		auto second = btree->Get(2);
		auto fourth = btree->Get(4);

		//THEN
		Assert::IsTrue(first_font == *first);
		Assert::IsTrue(first_font == *second);
		Assert::IsTrue(second_font == *fourth);
	}

	TEST_METHOD(ShouldPassTestCaseFromBook)
	{
		//GIVEN
		auto btree = new BTree();

		Font times_12("Times 12");
		Font times_24("Times 24");
		Font times_italic_12("Times-Italic 12");
		Font times_bold_12("Times-Bold 12");
		Font courier_24("Courier 24");

		//WHEN
		btree->Set(&times_12, 1, 500);
		btree->Set(&times_24, 1, 1);
		btree->Set(&times_italic_12, 102, 6);
		btree->Set(&times_bold_12, 302, 8);
		btree->Set(&courier_24, 312, 3);

		//THEN
		auto first = btree->Get(1);
		auto second = btree->Get(2);
		auto italic = btree->Get(107);
		auto bold = btree->Get(305);
		auto courier = btree->Get(314);

		Assert::IsTrue(times_24 == *first);
		Assert::IsTrue(times_12 == *second);
		Assert::IsTrue(times_italic_12 == *italic);
		Assert::IsTrue(times_bold_12 == *bold);
		Assert::IsTrue(courier_24 == *courier);
	}
};
}
