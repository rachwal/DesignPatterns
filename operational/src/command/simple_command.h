// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_COMMAND_SIMPLE_COMMAND_H_
#define OPERATIONAL_COMMAND_SIMPLE_COMMAND_H_

#include "command_interface.h"

namespace operational
{
namespace command
{
template<class Receiver>
class SimpleCommand : public CommandInterface
{
	public:
	typedef void (Receiver::* Action)();

	SimpleCommand(Receiver* r, Action a);

	virtual void Execute() override;

	private:
	Action action_;
	Receiver* receiver_;
};

template<class Receiver>
SimpleCommand<Receiver>::SimpleCommand(Receiver* receiver, Action action): action_(action), receiver_(receiver) { }

template<class Receiver>
void SimpleCommand<Receiver>::Execute()
{
	(receiver_ ->* action_)();
}
}
}

#endif

