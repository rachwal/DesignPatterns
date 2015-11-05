// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../structural/src/commons/point.h"

namespace structuraltests
{
using namespace structural::commons;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(PointTest)
{
	public:
	PointTest() { }

	~PointTest() { }

	TEST_METHOD(ShouldCreateDefaultPoint)
	{
		//WHEN
		Point<float> point;

		//THEN
		Assert::AreEqual(0.0f, point.x());
		Assert::AreEqual(0.0f, point.y());
	}

	TEST_METHOD(ShouldAddTwoPoints)
	{
		//GIVEN
		Point<float> first_point(1, 2);
		Point<float> second_point(3, 4);

		//WHEN
		auto point = first_point + second_point;

		//THEN
		Assert::AreEqual(4.0f, point.x());
		Assert::AreEqual(6.0f, point.y());
	}

	TEST_METHOD(ShouldSubstractTwoPoints)
	{
		//GIVEN
		Point<float> first_point(1, 2);
		Point<float> second_point(3, 4);

		//WHEN
		auto point = first_point - second_point;

		//THEN
		Assert::AreEqual(-2.0f, point.x());
		Assert::AreEqual(-2.0f, point.y());
	}

	TEST_METHOD(ShouldAddPointToExistingOne)
	{
		//GIVEN
		Point<float> first_point(1, 2);
		Point<float> second_point(3, 4);

		//WHEN
		first_point += second_point;

		//THEN
		Assert::AreEqual(4.0f, first_point.x());
		Assert::AreEqual(6.0f, first_point.y());
	}

	TEST_METHOD(ShouldSubstractPointFromExistingOne)
	{
		//GIVEN
		Point<float> first_point(1, 2);
		Point<float> second_point(3, 4);

		//WHEN
		first_point -= second_point;

		//THEN
		Assert::AreEqual(-2.0f, first_point.x());
		Assert::AreEqual(-2.0f, first_point.y());
	}
};
}

