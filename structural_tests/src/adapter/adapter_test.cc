// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Structural/src/adapter/text_shape_object_adapter.h"
#include "../../../Structural/src/adapter/text_shape_class_adapter.h"

namespace structuraltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace structural::adapter;

TEST_CLASS(AdapterTest)
{
	public:
	AdapterTest() { }

	~AdapterTest() { }

	TEST_METHOD(ClientShouldBeEmptyWhenAdapteeHasNoContent)
	{
		//GIVEN
		auto text_view = new TextView("");

		//WHEN
		auto client = new TextShapeObjectAdapter(text_view);

		//THEN
		auto is_empty = client->IsEmpty();

		Assert::IsTrue(is_empty);
	}

	TEST_METHOD(ClientShouldNotBeEmptyWhenAdapteeHasSomeContent)
	{
		//GIVEN
		auto text_view = new TextView("test");

		//WHEN
		auto client = new TextShapeObjectAdapter(text_view);

		//THEN
		auto is_empty = client->IsEmpty();

		Assert::IsFalse(is_empty);
	}

	TEST_METHOD(ClientShouldHaveBoundingBoxBasedOnAdaptee)
	{
		//GIVEN
		auto text_view = new TextView("test");
		auto client = new TextShapeObjectAdapter(text_view);

		//WHEN
		auto bottom_left = new structural::commons::Point<float>();
		auto top_right = new structural::commons::Point<float>();
		client->BoundingBox(*bottom_left, *top_right);

		//THEN
		Assert::AreEqual(0.0f, bottom_left->x());
		Assert::AreEqual(0.0f, bottom_left->y());
		Assert::AreEqual(10.0f, top_right->x());
		Assert::AreEqual(1.0f, top_right->y());
	}

	TEST_METHOD(ClientShouldHaveAnEmptyContentAfterCreationLikeAdaptee)
	{
		//WHEN
		auto client = new TextShapeClassAdapter();

		//THEN
		auto is_empty = client->IsEmpty();
		auto content = client->content();

		Assert::IsTrue(is_empty);
		Assert::AreEqual("", content.c_str());
	}

	TEST_METHOD(ClientShouldCreateClassAdapterWithContentLikeAdaptee)
	{
		//GIVEN
		auto expected_content = "test";

		//WHEN
		auto client = new TextShapeClassAdapter(expected_content);

		//THEN
		auto is_empty = client->IsEmpty();
		auto content = client->content();

		Assert::IsFalse(is_empty);
		Assert::AreEqual(expected_content, content.c_str());
	}

	TEST_METHOD(ClientShouldSetBoundingBoxLikeAdaptee)
	{
		//GIVEN
		auto client = new TextShapeClassAdapter();

		//WHEN
		client->SetOrigin(3.0f, 4.0f);
		client->SetExtent(2.0f, 3.0f);

		//THEN
		auto bottom_left = new structural::commons::Point<float>();
		auto top_right = new structural::commons::Point<float>();
		client->BoundingBox(*bottom_left, *top_right);

		Assert::AreEqual(3.0f, bottom_left->x());
		Assert::AreEqual(4.0f, bottom_left->y());
		Assert::AreEqual(5.0f, top_right->x());
		Assert::AreEqual(7.0f, top_right->y());
	}
};
}
