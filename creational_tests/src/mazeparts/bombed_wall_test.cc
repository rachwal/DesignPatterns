// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Creational/src/mazeparts/bombed_wall.h"

namespace creationaltests
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(BombedWallTest)
	{
	public:
		BombedWallTest()
		{
		}

		~BombedWallTest()
		{
		}

		TEST_METHOD(ShouldCreateBombedWall)
		{
			//GIVEN
			auto bombed = true;

			//WHEN
			auto bombed_wall = creational::BombedWall(bombed);

			//THEN
			auto is_bombed = bombed_wall.bombed();

			Assert::IsTrue(is_bombed);
		}

		TEST_METHOD(ShouldCreateNonBombedWall)
		{
			//GIVEN
			auto bombed = false;

			//WHEN
			auto bombed_wall = creational::BombedWall(bombed);

			//THEN
			auto is_bombed = bombed_wall.bombed();

			Assert::IsFalse(is_bombed);
		}

		TEST_METHOD(ShouldCreateBombedWallFromAnotherBombedWall)
		{
			//GIVEN
			auto existing_bombed_wall = creational::BombedWall(true);

			//WHEN
			auto bombed_wall = creational::BombedWall(existing_bombed_wall);

			//THEN
			auto is_bombed = bombed_wall.bombed();

			Assert::IsTrue(is_bombed);
		}

		TEST_METHOD(ShouldCreateBombedWallFromAnotherNonBombedWall)
		{
			//GIVEN
			auto existing_bombed_wall = creational::BombedWall(false);

			//WHEN
			auto bombed_wall = creational::BombedWall(existing_bombed_wall);

			//THEN
			auto is_bombed = bombed_wall.bombed();

			Assert::IsFalse(is_bombed);
		}

		TEST_METHOD(ShouldCloneEnteredBombedWall)
		{
			//GIVEN
			auto existing_bombed_wall = creational::BombedWall(true);
			existing_bombed_wall.Enter();

			//WHEN
			auto bombed_wall = existing_bombed_wall.Clone();
			auto is_entered = bombed_wall->entered();

			//THEN
			auto is_bombed = bombed_wall->bombed();

			Assert::IsTrue(is_bombed);
			Assert::IsTrue(is_entered);
		}

		TEST_METHOD(ShouldCloneNonBombedWall)
		{
			//GIVEN
			auto existing_bombed_wall = creational::BombedWall(false);

			//WHEN
			auto bombed_wall = existing_bombed_wall.Clone();

			//THEN
			auto is_bombed = bombed_wall->bombed();
			auto is_entered = bombed_wall->entered();

			Assert::IsFalse(is_bombed);
			Assert::IsFalse(is_entered);
		}
	};
}
