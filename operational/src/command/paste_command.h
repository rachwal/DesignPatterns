// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_COMMAND_PASTE_COMMAND_H_
#define OPERATIONAL_COMMAND_PASTE_COMMAND_H_

#include "command_interface.h"
#include "command_document.h"

namespace operational
{
namespace command
{
class PasteCommand : public CommandInterface
{
	public:
	explicit PasteCommand(CommandDocument* document);

	virtual void Execute() override;

	private:
	CommandDocument* document_;
};
}
}

#endif

