// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "open_command.h"

namespace operational
{
namespace command
{
OpenCommand::OpenCommand(CommandApplication* application) : application_(application), response_("") { }

void OpenCommand::Execute()
{
	auto name = AskUser();
	if (name.compare("") != 0)
	{
		auto document = new CommandDocument(name);
		application_->Add(document);
		document->Open();
	}
}

std::string OpenCommand::AskUser() const
{
	auto name = "command document";
	return name;
}
}
}

