// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Structural/src/adapter/text_view.h"

namespace structuraltests
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(TextViewTest)
	{
	public:
		TextViewTest()
		{
		}

		~TextViewTest()
		{
		}

		TEST_METHOD(ShouldCreateEmptyTextView)
		{
			//WHEN
			auto text_view = new structural::TextView();

			//THEN
			auto is_empty = text_view->IsEmpty();

			float x, y, width, height;
			text_view->GetOrigin(x, y);
			text_view->GetExtent(width, height);

			Assert::IsTrue(is_empty);
			Assert::AreEqual(0.0f, x);
			Assert::AreEqual(0.0f, y);
			Assert::AreEqual(10.0f, width);
			Assert::AreEqual(1.0f, height);
		}

		TEST_METHOD(ShouldCreateTextViewWithNoContent)
		{
			//WHEN
			auto text_view = new structural::TextView();

			//THEN
			auto content = text_view->content();

			Assert::AreEqual("", content.c_str());
		}

		TEST_METHOD(ShouldCreateTextViewWithContent)
		{
			//GIVEN
			auto expected_content = "test";

			//WHEN
			auto text_view = new structural::TextView(expected_content);

			//THEN
			auto content = text_view->content();
			auto is_empty = text_view->IsEmpty();

			Assert::AreEqual(expected_content, content.c_str());
			Assert::IsFalse(is_empty);
		}

		TEST_METHOD(ShouldSetTextViewOrigin)
		{
			//GIVEN
			auto expected_x = 1.0f;
			auto expected_y = 2.0f;
			auto text_view = new structural::TextView();

			//WHEN
			text_view->SetOrigin(expected_x, expected_y);

			//THEN
			float x, y;
			text_view->GetOrigin(x, y);

			Assert::AreEqual(expected_x, x);
			Assert::AreEqual(expected_y, y);
		}

		TEST_METHOD(ShouldSetTextViewExtent)
		{
			//GIVEN
			auto expected_width = 10.0f;
			auto expected_height = 20.0f;
			auto text_view = new structural::TextView();

			//WHEN
			text_view->SetExtent(expected_width, expected_height);

			//THEN
			float width, height;
			text_view->GetExtent(width, height);

			Assert::AreEqual(expected_width, width);
			Assert::AreEqual(expected_height, height);
		}
	};
}
