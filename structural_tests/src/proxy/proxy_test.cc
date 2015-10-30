// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Foundation/src/point.h"
#include "../../../Structural/src/proxy/image_proxy.h"
#include "../../../Structural/src/proxy/text_document.h"
#include "../../../Structural/src/proxy/virtual_image_proxy.h"

namespace structuraltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace structural::proxy;

TEST_CLASS(ProxyTest)
{
	public:
	ProxyTest() { }

	~ProxyTest() { }

	TEST_METHOD(VirtualProxyShouldCreateImageWithDefaultExtent)
	{
		//GIVEN
		auto expected_default_extent = foundation::Point<float>(100, 20);
		auto image = VirtualImageProxy("sample.bmp");

		//WHEN
		auto extent = image->GetExtent();

		//THEN
		Assert::IsTrue(expected_default_extent == extent);
	}

	TEST_METHOD(VirtualProxyShouldSetNewExtentWhenDrawing)
	{
		//GIVEN
		auto new_extent = foundation::Point<float>(150, 120);
		auto image = VirtualImageProxy("sample.bmp");

		//WHEN
		image->Draw(new_extent);

		//THEN
		auto extent = image->GetExtent();
		Assert::IsTrue(new_extent == extent);
	}

	TEST_METHOD(ShouldCreateEmptyDocumentWithZeroExtent)
	{
		//GIVEN
		auto zero_extent = foundation::Point<float>(0, 0);
		auto text = new TextDocument;

		//WHEN
		auto extent = text->GetExtent();

		//THEN
		Assert::IsTrue(zero_extent == extent);
	}

	TEST_METHOD(ShouldChangeDocumentExtentToGraphicExtent)
	{
		//GIVEN
		auto expected_default_extent = foundation::Point<float>(100, 20);
		auto text = new TextDocument;

		//WHEN
		text->Insert(new ImageProxy("sample.bmp"));
		auto extent = text->GetExtent();

		//THEN
		Assert::IsTrue(expected_default_extent == extent);
	}
};
}
