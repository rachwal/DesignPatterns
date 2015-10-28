// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Operational/src/observer/clock_timer.h"
#include "../../../Operational/src/iterator/employee.h"

namespace operationaltests
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;
	using namespace operational;

	TEST_CLASS(IteratorTest)
	{
	public:
		IteratorTest()
		{
		}

		~IteratorTest()
		{
		}

		TEST_METHOD(ShouldCreateEmptyList)
		{
			//GIVEN
			auto employees = new List<Employee*>();

			//WHEN
			auto employees_count = employees->Count();

			//THEN
			Assert::AreEqual(0l, employees_count);
		}

		TEST_METHOD(ShouldAppendTwoElementsToList)
		{
			//GIVEN
			auto employees = new List<Employee*>();

			//WHEN
			employees->Append(new Employee("Test 1"));
			employees->Append(new Employee("Test 2"));

			//THEN
			auto employees_count = employees->Count();
			Assert::AreEqual(2l, employees_count);
		}

		//void PrintEmployees(IteratorInterface<Employee*>& i) const
		//{
		//	for (i.First(); !i.IsDone(); i.Next()) {
		//		i.CurrentItem()->Print();
		//	}
		//};
	};
}
