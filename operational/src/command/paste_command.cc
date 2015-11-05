// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "paste_command.h"

namespace operational
{
namespace command
{
PasteCommand::PasteCommand(CommandDocument* document)
{
	document_ = document;
}

void PasteCommand::Execute()
{
	document_->Paste();
}
}
}

