// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Operational/src/observer/clock_timer.h"

namespace operationaltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace operational::observer;

TEST_CLASS(ClockTimerTest)
{
	public:
	ClockTimerTest() { }

	~ClockTimerTest() { }

	TEST_METHOD(ShouldCreateTimerWithZeroTime)
	{
		//GIVEN
		auto timer = new ClockTimer;

		//WHEN
		auto hour = timer->GetHours();
		auto minute = timer->GetMinutes();
		auto second = timer->GetSeconds();

		//THEN
		Assert::AreEqual(0, hour);
		Assert::AreEqual(0, minute);
		Assert::AreEqual(0, second);
	}

	TEST_METHOD(ShouldIncreaseSecondsValueBy15AfterOneTick)
	{
		//GIVEN
		auto timer = new ClockTimer();

		//WHEN
		timer->Tick();

		//THEN
		auto hour = timer->GetHours();
		auto minute = timer->GetMinutes();
		auto second = timer->GetSeconds();

		Assert::AreEqual(0, hour);
		Assert::AreEqual(0, minute);
		Assert::AreEqual(15, second);
	}

	TEST_METHOD(ShouldSetCorrectTimeAfter1001Ticks)
	{
		//GIVEN
		auto timer = new ClockTimer();

		//WHEN
		for (auto i = 0; i < 1001; i++)
		{
			timer->Tick();
		}

		//THEN
		auto hour = timer->GetHours();
		auto minute = timer->GetMinutes();
		auto second = timer->GetSeconds();

		Assert::AreEqual(4, hour);
		Assert::AreEqual(10, minute);
		Assert::AreEqual(15, second);
	}
};
}
