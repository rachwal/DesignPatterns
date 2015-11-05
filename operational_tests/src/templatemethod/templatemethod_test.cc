// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../operational/src/templatemethod/sample_application.h"

namespace operationaltests
{
using namespace operational::templatemethod;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TemplatemethodTest)
{
	public:
	TemplatemethodTest() { }

	~TemplatemethodTest() { }

	TEST_METHOD(ShouldNotCreateDocumentWhenHaveEmptyFileName)
	{
		//GIVEN
		auto application = new SampleApplication();

		//WHEN
		application->OpenDocument("");

		//THEN
		auto document_state = application->GetCurrentDocumentState();
		Assert::IsTrue(kNonCreated == document_state);

		delete application;
	}

	TEST_METHOD(ShouldOpenDocumentInSampleApplication)
	{
		//GIVEN
		auto application = new SampleApplication();

		//WHEN
		application->OpenDocument("test.txt");

		//THEN
		auto document_state = application->GetCurrentDocumentState();
		Assert::IsTrue(kRead == document_state);

		delete application;
	}
};
}

