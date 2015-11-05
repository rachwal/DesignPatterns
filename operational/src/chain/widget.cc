// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "widget.h"

#include <sstream>

namespace operational
{
namespace chain
{
Widget::Widget() : Widget("widget", -1, nullptr) {}

Widget::Widget(std::string name) : Widget(name, -1, nullptr) {}

Widget::Widget(std::string name, int topic) : Widget(name, topic, nullptr) {}

Widget::Widget(std::string name, int topic, HelpHandlerInterface* parent)
{
	topic_ = topic;
	name_ = name;
	help_message_ = "";
	parent_ = parent;
}

bool Widget::HasHelp()
{
	return topic_ != -1;
}

void Widget::SetHandler(HelpHandlerInterface* parent, int topic)
{
	topic_ = topic;
	parent_ = parent;
}

void Widget::HandleHelp()
{
	if (HasHelp())
	{
		std::ostringstream stream;
		stream << "<Widget|" << name_ << "|" << topic_ << "|Widget>";
		help_message_ = stream.str();
	}
	else
	{
		if (parent_)
		{
			parent_->HandleHelp();
		}
	}
}

int Widget::topic() const
{
	return topic_;
}

std::string Widget::name() const
{
	return name_;
}

std::string Widget::help_message() const
{
	return help_message_;
}
}
}

