// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "macro_command.h"

#include "../iterator/list_iterator.h"

namespace operational
{
namespace command
{
void MacroCommand::Execute()
{
	iterator::ListIterator<CommandInterface*> iterator(commands_);

	for (iterator.First(); !iterator.IsDone(); iterator.Next())
	{
		auto command = iterator.CurrentItem();
		command->Execute();
	}
}

MacroCommand::~MacroCommand()
{
	delete commands_;
}

MacroCommand::MacroCommand()
{
	commands_ = new iterator::List<CommandInterface*>();
}

void MacroCommand::Add(CommandInterface* command)
{
	commands_->Append(command);
}

void MacroCommand::Remove(CommandInterface* command)
{
	commands_->Remove(command);
}
}
}

