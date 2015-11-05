// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "command_document.h"

#include <sstream>

namespace operational
{
namespace command
{
CommandDocument::CommandDocument(const std::string& name) : name_(name) {}

void CommandDocument::Open()
{
	std::ostringstream stream;
	stream << "<Open|" << name_ << "|Open>";
	name_ = stream.str();
}

void CommandDocument::Paste()
{
	std::ostringstream stream;
	stream << "<Paste|" << name_ << "|Paste>";
	name_ = stream.str();
}

std::string CommandDocument::name() const
{
	return name_;
}
}
}

