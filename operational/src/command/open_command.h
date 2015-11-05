// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_COMMAND_OPEN_COMMAND_H_
#define OPERATIONAL_COMMAND_OPEN_COMMAND_H_

#include "command_interface.h"
#include "command_application.h"

namespace operational
{
namespace command
{
class OpenCommand : public CommandInterface
{
	public:
	explicit OpenCommand(CommandApplication* application);

	virtual void Execute() override;

	protected:
	virtual std::string AskUser() const;

	private:
	CommandApplication* application_;
	std::string response_;
};
}
}

#endif

