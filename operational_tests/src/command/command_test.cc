// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../operational/src/command/my_class.h"
#include "../../../operational/src/command/simple_command.h"
#include "../../../operational/src/command/command_application.h"
#include "../../../operational/src/command/open_command.h"
#include "../../../operational/src/command/macro_command.h"
#include "../../../operational/src/command/paste_command.h"

namespace operationaltests
{
using namespace operational::command;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(CommnadTest)
{
	public:
	CommnadTest() { }

	~CommnadTest() { }

	TEST_METHOD(ShouldFireActionBySimpleCommand)
	{
		//GIVEN
		auto receiver = new MyClass;
		auto command = new SimpleCommand<MyClass>(receiver, &MyClass::Action);

		//WHEN
		command->Execute();

		//THEN
		auto fired = receiver->fired();

		Assert::IsTrue(fired);

		delete command;
	}

	TEST_METHOD(ShouldOpenNewDocumentWithStubName)
	{
		//GIVEN
		std::string expected_document_title = "<Open|command document|Open>";

		auto application = new CommandApplication;
		auto open_command = new OpenCommand(application);

		//WHEN
		open_command->Execute();

		//THEN
		auto document_title = application->GetCurrentDocumentTitle();

		Assert::AreEqual(0, expected_document_title.compare(document_title));

		delete open_command;
	}

	TEST_METHOD(ShouldExecuteMacroCommand)
	{
		//GIVEN
		std::string expected_application_document_title = "<Open|command document|Open>";
		std::string expected_document_title = "<Paste|test document|Paste>";

		auto application = new CommandApplication;
		auto document = new CommandDocument("test document");

		auto macro_command = new MacroCommand();

		auto open_command = new OpenCommand(application);
		auto paste_command = new PasteCommand(document);

		//WHEN
		macro_command->Add(open_command);
		macro_command->Add(paste_command);
		macro_command->Execute();

		//THEN
		auto application_document_title = application->GetCurrentDocumentTitle();
		auto document_title = document->name();

		Assert::AreEqual(0, expected_application_document_title.compare(application_document_title));
		Assert::AreEqual(0, expected_document_title.compare(document_title));

		delete macro_command;
	}
};
}

