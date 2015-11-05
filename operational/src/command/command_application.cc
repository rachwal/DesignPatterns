// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "command_application.h"

namespace operational
{
namespace command
{
CommandApplication::CommandApplication() : current_document_(nullptr) { }

void CommandApplication::Add(CommandDocument* document)
{
	current_document_ = document;
}

std::string CommandApplication::GetCurrentDocumentTitle() const
{
	if (current_document_)
	{
		return current_document_->name();
	}
	return "";
}
}
}

