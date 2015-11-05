// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "button.h"

#include <sstream>

namespace operational
{
namespace chain
{
Button::Button() : Button("button", -1, nullptr) {}

Button::Button(std::string name) : Button(name, -1, nullptr) {}

Button::Button(std::string name, int topic) : Button(name, topic, nullptr) {}

Button::Button(std::string name, int topic, HelpHandlerInterface* parent) : Widget(name, topic, parent)
{
	topic_ = topic;
}

bool Button::HasHelp()
{
	return topic_ != -1;
}

void Button::HandleHelp()
{
	if (HasHelp())
	{
		std::ostringstream stream;
		stream << "<Button|" << name() << "|" << topic_ << "|Button>";
		help_message_ = stream.str();
	}
	else
	{
		Widget::HandleHelp();
	}
}

std::string Button::help_message() const
{
	return help_message_;
}
}
}

