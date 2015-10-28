// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Structural/src/flyweight/glyph_context.h"
#include "../../../Structural/src/flyweight/glyph_factory.h"

namespace structuraltests
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;
	using namespace structural;

	TEST_CLASS(FlyweightTest)
	{
	public:
		FlyweightTest()
		{
		}

		~FlyweightTest()
		{
		}

		TEST_METHOD(ShoulFlyweightTest)
		{
			//GIVEN
			auto glyph_factory = new GlyphFactory();

			auto a_character = glyph_factory->CreateCharacter('a');
			auto b_character = glyph_factory->CreateCharacter('b');

			auto column = glyph_factory->CreateColumn();
			auto row = glyph_factory->CreateRow();

			auto context = new GlyphContext();

			auto times_12 = new Font("Times 12");
			auto times_24 = new Font("Times 24");

			//WHEN
			a_character->SetFont(times_12, *context);
			a_character->Next(*context);
			b_character->SetFont(times_24, *context);

			//THEN
			column->First(*context);
			auto times_regular = column->GetFont(*context);
			row->Next(*context);
			auto times_big = row->GetFont(*context);

			Assert::IsTrue(times_12 == times_regular);
			Assert::IsTrue(times_24 == times_big);
		}
	};
}
