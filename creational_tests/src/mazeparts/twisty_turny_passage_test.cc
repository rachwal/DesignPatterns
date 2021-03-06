// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../creational/src/mazeparts/twisty_turny_passage.h"

namespace creationaltests
{
using namespace creational::commons;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TwistyTurnyPassageTest)
{
	public:
	TwistyTurnyPassageTest() { }

	~TwistyTurnyPassageTest() { }

	TEST_METHOD(ShouldCreateTwistyTurnyPassage)
	{
		//WHEN
		TwistyTurnyPassage twisty_turny_passage;

		//THEN
		auto entered = twisty_turny_passage.entered();

		Assert::IsFalse(entered);
	}

	TEST_METHOD(ShouldEnterTwistyTurnyPassage)
	{
		//GIVEN
		TwistyTurnyPassage twisty_turny_passage;

		//WHEN
		twisty_turny_passage.Enter();

		//THEN
		auto entered = twisty_turny_passage.entered();

		Assert::IsTrue(entered);
	}
};
}

