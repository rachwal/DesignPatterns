// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../operational/src/strategy/array_compositor.h"
#include "../../../operational/src/strategy/strategy_context.h"
#include "../../../operational/src/strategy/my_strategy.h"
#include "../../../operational/src/strategy/composition.h"
#include "../../../operational/src/strategy/simple_compositor.h"
#include "../../../operational/src/strategy/tex_compositor.h"

namespace operationaltests
{
using namespace operational::strategy;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(StrategyTest)
{
	public:
	StrategyTest() { }

	~StrategyTest() { }

	TEST_METHOD(ShouldRunSimpleCompositorStrategy)
	{
		//GIVEN
		auto expected_break_count = 0;
		auto quick = new Composition(new SimpleCompositor);

		//WHEN
		quick->Repair();

		//THEN
		auto break_count = quick->break_count();
		Assert::AreEqual(expected_break_count, break_count);

		delete quick;
	}

	TEST_METHOD(ShouldRunTexCompositorStrategy)
	{
		//GIVEN
		auto expected_break_count = 1;
		auto slick = new Composition(new TexCompositor);

		//WHEN
		slick->Repair();

		//THEN
		auto break_count = slick->break_count();
		Assert::AreEqual(expected_break_count, break_count);

		delete slick;
	}

	TEST_METHOD(ShouldRunArrayCompositorStrategy)
	{
		//GIVEN
		auto expected_break_count = 6;
		auto iconic = new Composition(new ArrayCompositor(100));

		//WHEN
		iconic->Repair();

		//THEN
		auto break_count = iconic->break_count();
		Assert::AreEqual(expected_break_count, break_count);

		delete iconic;
	}

	TEST_METHOD(ShouldRunTemplateStrategy)
	{
		//GIVEN
		std::string expected_result = "<MyStrategy>";

		StrategyContext<MyStrategy> context;

		//WHEN
		context.Operation();

		//THEN
		auto result = context.result();

		Assert::AreEqual(0, expected_result.compare(result));
	}
};
}

