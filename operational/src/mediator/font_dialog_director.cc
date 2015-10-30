// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "font_dialog_director.h"

namespace operational
{
namespace madiator
{
FontDialogDirector::FontDialogDirector()
{
	ok_button_ = nullptr;
	cancel_button_ = nullptr;
	font_list_ = nullptr;
	font_name_ = nullptr;
}

void FontDialogDirector::Initialize(MediatorButton* ok_button, MediatorButton* cancel_button, ListBox* font_list, EntryField* font_name)
{
	ok_button_ = ok_button;
	cancel_button_ = cancel_button;
	font_list_ = font_list;
	font_name_ = font_name;
}

void FontDialogDirector::ShowDialog() {}

void FontDialogDirector::WidgetChanged(MediatorWidgetInterface* widget)
{
	if (widget == font_list_)
	{
		font_name_->text(font_list_->GetSelection());
	}
	else if (widget == ok_button_)
	{
		ok_button_->text("saved");
		cancel_button_->text("");
	}
	else if (widget == cancel_button_)
	{
		ok_button_->text("");
		font_name_->text("");
		cancel_button_->text("cancelled");
	}
}
}}
