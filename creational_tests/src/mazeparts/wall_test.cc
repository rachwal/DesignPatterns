// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../creational/src/mazeparts/wall.h"

namespace creationaltests
{
using namespace creational::commons;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(WallTest)
{
	public:
	WallTest() { }

	~WallTest() { }

	TEST_METHOD(ShouldCreateWall)
	{
		//WHEN
		Wall wall;

		//THEN
		auto entered = wall.entered();

		Assert::IsFalse(entered);
	}

	TEST_METHOD(ShouldEnterWall)
	{
		//GIVEN
		Wall wall;

		//WHEN
		wall.Enter();

		//THEN
		auto entered = wall.entered();

		Assert::IsTrue(entered);
	}

	TEST_METHOD(ShouldCreateWallFromAnotherWall)
	{
		//GIVEN
		Wall existing_wall;

		//WHEN
		auto wall = Wall(existing_wall);

		//THEN
		auto entered = wall.entered();

		Assert::IsFalse(entered);
	}

	TEST_METHOD(ShouldCreateWallFromAnotherEnteredWall)
	{
		//GIVEN
		Wall existing_wall;
		existing_wall.Enter();

		//WHEN
		auto wall = Wall(existing_wall);

		//THEN
		auto entered = wall.entered();

		Assert::IsTrue(entered);
	}

	TEST_METHOD(ShouldCloneWallFromAnotherWall)
	{
		//GIVEN
		Wall existing_wall;

		//WHEN
		auto wall = existing_wall.Clone();

		//THEN
		auto entered = wall->entered();

		Assert::IsFalse(entered);
	}

	TEST_METHOD(ShouldCloneWallFromAnotherEnteredWall)
	{
		//GIVEN
		Wall existing_wall;
		existing_wall.Enter();

		//WHEN
		auto wall = existing_wall.Clone();

		//THEN
		auto entered = wall->entered();

		Assert::IsTrue(entered);
	}
};
}

