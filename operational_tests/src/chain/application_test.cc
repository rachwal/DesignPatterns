// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Operational/src/chain/application.h"

namespace operationaltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace operational;

TEST_CLASS(ApplicationTest)
{
	public:
	ApplicationTest() { }

	~ApplicationTest() { }

	TEST_METHOD(ShouldCreateDefaultApplication)
	{
		//GIVEN
		auto no_help_topic = -1;
		auto application = new chain::Application();

		//WHEN
		auto has_help = application->HasHelp();
		auto topic = application->topic();

		//THEN
		Assert::IsFalse(has_help);
		Assert::AreEqual(no_help_topic, topic);
	}

	TEST_METHOD(ShouldCreateApplicationWithHelp)
	{
		//GIVEN
		std::string default_help_message = "";
		auto expected_help_topic = 11;
		auto application = new chain::Application("app", expected_help_topic);

		//WHEN
		auto has_help = application->HasHelp();
		auto topic = application->topic();
		auto help_message = application->help_message();

		//THEN
		Assert::IsTrue(has_help);
		Assert::AreEqual(expected_help_topic, topic);
		Assert::AreEqual(0, default_help_message.compare(help_message));
	}

	TEST_METHOD(ShouldHandleHelp)
	{
		//GIVEN
		std::string expected_help_message = "<Application|app|11|Application>";
		auto expected_help_topic = 11;
		auto application = new chain::Application("app", expected_help_topic);

		//WHEN
		application->HandleHelp();

		//THEN
		auto help_message = application->help_message();
		Assert::AreEqual(0, expected_help_message.compare(help_message));
	}

	TEST_METHOD(ShouldChangeApplicationHandler)
	{
		//GIVEN
		auto no_help_topic = -1;
		auto some_help_topic = 11;
		auto application = new chain::Application("app", some_help_topic);

		//WHEN
		application->SetHandler(nullptr, no_help_topic);

		//THEN
		auto has_help = application->HasHelp();
		auto topic = application->topic();

		Assert::IsFalse(has_help);
		Assert::AreEqual(no_help_topic, topic);
	}

	TEST_METHOD(ShouldPassHandlingHelpToSuccessor)
	{
		//GIVEN
		auto no_help_topic = -1;
		auto general_help_topic = 11;

		auto parent_application = new chain::Application("parent", general_help_topic);
		auto child_application = new chain::Application("child", general_help_topic);

		//WHEN
		child_application->SetHandler(parent_application, no_help_topic);

		//THEN
		auto child_has_help = child_application->HasHelp();
		auto parent_has_help = parent_application->HasHelp();

		Assert::IsFalse(child_has_help);
		Assert::IsTrue(parent_has_help);
	}

	TEST_METHOD(ParentShouldHandleHelpWhenChildHasNoTopic)
	{
		//GIVEN
		std::string default_help_message = "";
		std::string expected_help_message = "<Application|parent|11|Application>";
		auto no_help_topic = -1;
		auto general_help_topic = 11;

		auto parent_application = new chain::Application("parent", general_help_topic);
		auto child_application = new chain::Application("child", no_help_topic, parent_application);

		//WHEN
		child_application->HandleHelp();

		//THEN
		auto child_help_message = child_application->help_message();
		auto parent_help_message = parent_application->help_message();

		Assert::AreEqual(0, default_help_message.compare(child_help_message));
		Assert::AreEqual(0, expected_help_message.compare(parent_help_message));
	}
};
}
