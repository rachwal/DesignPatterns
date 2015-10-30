// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "entry_field.h"

namespace operational
{
namespace madiator
{
EntryField::EntryField(DialogDirectorInterface* director) : MediatorWidget(director), text_("") { }

void EntryField::text(const std::string& text)
{
	text_ = text;
}

const std::string &EntryField::text() const
{
	return text_;
}

void EntryField::HandleMouse(MouseEvent& event)
{
	Changed();
}
}}
