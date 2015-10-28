// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Operational/src/observer/digital_clock.h"
#include "../../../Operational/src/observer/analog_clock.h"

namespace operationaltests
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(ObserverTest)
	{
	public:
		ObserverTest()
		{
		}

		~ObserverTest()
		{
		}

		TEST_METHOD(ShouldIncreaseNotifyObserversAboutClockTimerChange)
		{
			//GIVEN
			auto timer = new operational::ClockTimer;
			auto analog_clock = new operational::AnalogClock(timer);
			auto digital_clock = new operational::DigitalClock(timer);

			//WHEN
			for (auto i = 0; i < 1001; i++)
			{
				timer->Tick();
			}

			//THEN
			auto analog_time = analog_clock->formated_time();
			auto digital_time = digital_clock->formated_time();

			Assert::AreEqual("4/10", analog_time.c_str());
			Assert::AreEqual("4:10:15", digital_time.c_str());
		}
	};
}
