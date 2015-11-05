// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../operational/src/mediator/font_dialog_director.h"

namespace operationaltests
{
using namespace operational::madiator;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(MediatorTest)
{
	public:
	MediatorTest() { }

	~MediatorTest() { }

	TEST_METHOD(ShouldPassSetFontNameOnEntryFieldWhenGetMouseEventFromListBox)
	{
		//GIVEN
		auto expected_font_name = "arial";

		auto director = new FontDialogDirector();

		auto ok_button = new MediatorButton(director);
		auto cancel_button = new MediatorButton(director);

		auto font_list = new ListBox(director);
		auto items = new operational::iterator::List<std::string>();
		items->Append(expected_font_name);
		font_list->SetList(items);

		auto font_name = new EntryField(director);

		director->Initialize(ok_button, cancel_button, font_list, font_name);

		//WHEN
		auto event = MouseEvent();
		font_list->HandleMouse(event);

		//THEN
		auto font = font_name->text();

		Assert::AreEqual(expected_font_name, font.c_str());
	}

	TEST_METHOD(ShouldEraseEntryFiedTextWhenCancelButtonGetMouseEvent)
	{
		//GIVEN
		auto expected_font_name = "";

		auto director = new FontDialogDirector();

		auto ok_button = new MediatorButton(director);
		auto cancel_button = new MediatorButton(director);

		auto font_list = new ListBox(director);
		auto items = new operational::iterator::List<std::string>();
		items->Append(expected_font_name);
		font_list->SetList(items);

		auto font_name = new EntryField(director);

		director->Initialize(ok_button, cancel_button, font_list, font_name);

		auto event = MouseEvent();
		font_list->HandleMouse(event);

		//WHEN
		cancel_button->HandleMouse(event);

		//THEN
		auto font = font_name->text();

		Assert::AreEqual(expected_font_name, font.c_str());
	}
};
}

