// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "mediator_button.h"

#include <string>

namespace operational
{
namespace madiator
{
MediatorButton::MediatorButton(DialogDirectorInterface* director) : MediatorWidget(director), text_("") { }

void MediatorButton::text(const std::string& text)
{
	text_ = text;
}

const std::string &MediatorButton::text(const std::string& text) const
{
	return text_;
}

void MediatorButton::HandleMouse(MouseEvent& event)
{
	Changed();
}
}}
