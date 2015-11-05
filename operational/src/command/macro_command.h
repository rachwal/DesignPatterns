// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_COMMAND_MACRO_COMMAND_H_
#define OPERATIONAL_COMMAND_MACRO_COMMAND_H_

#include "command_interface.h"

#include "../iterator/list.h"

namespace operational
{
namespace command
{
class MacroCommand : public CommandInterface
{
	public:
	MacroCommand();
	virtual ~MacroCommand();

	virtual void Add(CommandInterface*);
	virtual void Remove(CommandInterface*);

	virtual void Execute() override;

	private:
	iterator::List<CommandInterface*>* commands_;
};
}
}

#endif

