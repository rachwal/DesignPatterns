// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "application.h"

#include <sstream>

namespace operational
{
namespace chain
{
Application::Application() : Application("application", -1, nullptr) {}

Application::Application(std::string name) : Application(name, -1, nullptr) {}

Application::Application(std::string name, int topic) : Application(name, topic, nullptr) {}

Application::Application(std::string name, int topic, HelpHandlerInterface* parent)
{
	topic_ = topic;
	name_ = name;
	help_message_ = "";
	parent_ = parent;
}

bool Application::HasHelp()
{
	return topic_ != -1;
}

void Application::SetHandler(HelpHandlerInterface* parent, int topic)
{
	topic_ = topic;
	parent_ = parent;
}

void Application::HandleHelp()
{
	if (HasHelp())
	{
		std::ostringstream stream;
		stream << "<Application|" << name_ << "|" << topic_ << "|Application>";
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

int Application::topic() const
{
	return topic_;
}

std::string Application::name() const
{
	return name_;
}

std::string Application::help_message() const
{
	return help_message_;
}
}
}

