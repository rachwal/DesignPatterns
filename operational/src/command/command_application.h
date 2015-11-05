// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_COMMAND_COMMAND_APPLICATION_H_
#define OPERATIONAL_COMMAND_COMMAND_APPLICATION_H_

#include "command_document.h"

namespace operational
{
namespace command
{
class CommandApplication
{
	public:
	CommandApplication();

	void Add(CommandDocument*);
	std::string GetCurrentDocumentTitle() const;

	private:
	CommandDocument* current_document_;
};
}
}

#endif

