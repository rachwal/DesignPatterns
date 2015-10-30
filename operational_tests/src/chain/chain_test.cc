// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Operational/src/chain/button.h"
#include "../../../Operational/src/chain/application.h"
#include "../../../Operational/src/chain/dialog.h"

namespace operationaltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace operational;

TEST_CLASS(ChainTest)
{
	public:
	ChainTest() { }

	~ChainTest() { }

	TEST_METHOD(FirstElementShouldHandleHelp)
	{
		//GIVEN
		std::string default_help_message = "";
		std::string expected_help_message = "<Button|button|11|Button>";

		auto general_help_topic = 11;

		auto application = new chain::Application("app", general_help_topic);
		auto dialog = new chain::Dialog("dialog", general_help_topic, application);
		auto button = new chain::Button("button", general_help_topic, dialog);

		//WHEN
		button->HandleHelp();

		//THEN
		auto application_help_message = application->help_message();
		auto dialog_help_message = dialog->help_message();
		auto button_help_message = button->help_message();

		Assert::AreEqual(0, default_help_message.compare(application_help_message));
		Assert::AreEqual(0, default_help_message.compare(dialog_help_message));
		Assert::AreEqual(0, expected_help_message.compare(button_help_message));
	}

	TEST_METHOD(LastElementShouldHandleHelp)
	{
		//GIVEN
		std::string default_help_message = "";
		std::string expected_help_message = "<Application|app|11|Application>";
		auto no_help_topic = -1;
		auto general_help_topic = 11;

		auto application = new chain::Application("app", general_help_topic);
		auto dialog = new chain::Dialog("dialog", no_help_topic, application);
		auto button = new chain::Button("button", no_help_topic, dialog);

		//WHEN
		button->HandleHelp();

		//THEN
		auto application_help_message = application->help_message();
		auto dialog_help_message = dialog->help_message();
		auto button_help_message = button->help_message();

		//THEN
		Assert::AreEqual(0, expected_help_message.compare(application_help_message));
		Assert::AreEqual(0, default_help_message.compare(dialog_help_message));
		Assert::AreEqual(0, default_help_message.compare(button_help_message));
	}
};
}
