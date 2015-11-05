// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_COMMAND_COMMAND_INTERFACE_H_
#define OPERATIONAL_COMMAND_COMMAND_INTERFACE_H_

namespace operational
{
namespace command
{
class CommandInterface
{
	public:
	virtual ~CommandInterface() {}

	virtual void Execute() = 0;
};
}
}

#endif

