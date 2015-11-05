// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Structural/src/bridge/application_window.h"
#include "../../../Structural/src/bridge/x_window_imp.h"
#include "../../../Structural/src/bridge/p_m_window_imp.h"
#include "../../../Structural/src/bridge/icon_window.h"

namespace structuraltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace structural::bridge;

TEST_CLASS(BridgeTest)
{
	public:
	BridgeTest() { }

	~BridgeTest() { }

	TEST_METHOD(ShouldDrawTextOnApplicationWindowUsingXWindowImplementation)
	{
		//GIVEN
		auto application_title = "test application";
		auto sample_text = "sample text";
		auto expected_x_window_imp_text = "<X|sample text|X>";

		auto x_window_imp = new XWindowImp();
		auto application_window = new ApplicationWindow(application_title, x_window_imp);

		//WHEN
		application_window->DrawText(sample_text, structural::commons::Point<float>(0, 0));

		//THEN
		auto x_window_imp_text = x_window_imp->text();

		Assert::AreEqual(expected_x_window_imp_text, x_window_imp_text.c_str());

		delete application_window;
	}

	TEST_METHOD(ShouldDrawTextOnApplicationWindowUsingPMWindowImplementation)
	{
		//GIVEN
		auto application_title = "test application";
		auto sample_text = "sample text";
		auto expected_pm_window_imp_text = "<PM|sample text|PM>";

		auto pm_window_imp = new PMWindowImp();
		auto application_window = new ApplicationWindow(application_title, pm_window_imp);

		//WHEN
		application_window->DrawText(sample_text, structural::commons::Point<float>(0, 0));

		//THEN
		auto pm_window_imp_text = pm_window_imp->text();

		Assert::AreEqual(expected_pm_window_imp_text, pm_window_imp_text.c_str());

		delete application_window;
	}

	TEST_METHOD(ShouldDrawTextOnIconWindowUsingPMWindowImplementation)
	{
		//GIVEN
		auto bitmap_file_name = "sample.bmp";
		auto sample_text = "sample text";
		auto expected_pm_window_imp_text = "<PM|sample text|PM>";

		auto pm_window_imp = new PMWindowImp();
		auto icon_window = new IconWindow(bitmap_file_name, pm_window_imp);

		//WHEN
		icon_window->DrawText(sample_text, structural::commons::Point<float>(0, 0));

		//THEN
		auto pm_window_imp_text = pm_window_imp->text();

		Assert::AreEqual(expected_pm_window_imp_text, pm_window_imp_text.c_str());

		delete icon_window;
	}
};
}

