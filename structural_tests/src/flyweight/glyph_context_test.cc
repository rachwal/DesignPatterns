// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Structural/src/flyweight/glyph_context.h"

namespace structuraltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace structural::flyweight;

TEST_CLASS(GlyphContextTest)
{
	public:
	GlyphContextTest() { }

	~GlyphContextTest() { }

	TEST_METHOD(ShouldPassFirstTestCaseFromBook)
	{
		//GIVEN
		GlyphContext gc;
		auto times_12 = new Font("Times 12");
		auto times_24 = new Font("Times 24");
		auto times_italic_12 = new Font("Times-Italic 12");
		auto times_bold_12 = new Font("Times-Bold 12");
		auto courier_24 = new Font("Courier 24");

		gc.SetFont(times_12, 500);
		gc.SetFont(times_24, 1);
		gc.Next(101);
		gc.SetFont(times_italic_12, 6);
		gc.Next(201);
		gc.SetFont(times_bold_12, 8);
		gc.Next(10);
		gc.SetFont(courier_24, 3);

		//WHEN
		gc.First();
		auto first = gc.GetFont();
		gc.Next();
		auto second = gc.GetFont();
		gc.Next(100);
		auto italic = gc.GetFont();
		gc.Next(6);
		auto times = gc.GetFont();
		gc.Next(195);
		auto bold = gc.GetFont();
		gc.Next(10);
		auto curier = gc.GetFont();

		//THEN
		Assert::IsTrue(times_24 == first);
		Assert::IsTrue(times_12 == second);
		Assert::IsTrue(times_italic_12 == italic);
		Assert::IsTrue(times_12 == times);
		Assert::IsTrue(times_bold_12 == bold);
		Assert::IsTrue(courier_24 == curier);
	}

	TEST_METHOD(ShouldPassSecondTestCaseFromBook)
	{
		//GIVEN
		GlyphContext gc;
		auto times_12 = new Font("Times 12");
		auto times_24 = new Font("Times 24");
		auto times_italic_12 = new Font("Times-Italic 12");
		auto times_bold_12 = new Font("Times-Bold 12");
		auto courier_24 = new Font("Courier 24");

		gc.SetFont(times_12, 500);
		gc.SetFont(times_24, 1);
		gc.Next(101);
		gc.SetFont(times_italic_12, 6);
		gc.Next(201);
		gc.SetFont(times_bold_12, 8);
		gc.Next(10);
		gc.SetFont(courier_24, 3);

		//WHEN
		gc.First();
		gc.Next(101);
		gc.SetFont(times_12, 6);

		//THEN
		gc.First();
		auto first = gc.GetFont();
		gc.Next();
		auto second = gc.GetFont();
		gc.Next(100);
		auto italic = gc.GetFont();
		gc.Next(6);
		auto times = gc.GetFont();
		gc.Next(195);
		auto bold = gc.GetFont();
		gc.Next(10);
		auto curier = gc.GetFont();

		Assert::IsTrue(times_24 == first);
		Assert::IsTrue(times_12 == second);
		Assert::IsFalse(times_italic_12 == italic);
		Assert::IsTrue(times_12 == times);
		Assert::IsTrue(times_bold_12 == bold);
		Assert::IsTrue(courier_24 == curier);
	}
};
}

