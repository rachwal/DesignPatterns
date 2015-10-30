// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "dialog.h"

#include <sstream>

namespace operational
{
namespace chain
{
Dialog::Dialog() :Dialog("dialog", -1, nullptr) {}

Dialog::Dialog(std::string name) : Dialog(name, -1, nullptr) {}

Dialog::Dialog(std::string name, int topic) : Dialog(name, topic, nullptr) {}

Dialog::Dialog(std::string name, int topic, HelpHandlerInterface* parent) : Widget(name, topic, parent)
{
	topic_ = topic;
}

bool Dialog::HasHelp()
{
	return topic_ != -1;
}

void Dialog::HandleHelp()
{
	if (HasHelp())
	{
		std::ostringstream stream;
		stream << "<Dialog|" << name() << "|" << topic_ << "|Dialog>";
		help_message_ = stream.str();
	}
	else
	{
		Widget::HandleHelp();
	}
}

std::string Dialog::help_message() const
{
	return help_message_;
}
}}
