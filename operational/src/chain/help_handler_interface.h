// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_CHAIN_HELP_HANDLER_INTERFACE_H_
#define OPERATIONAL_CHAIN_HELP_HANDLER_INTERFACE_H_

namespace operational
{
namespace chain
{
class HelpHandlerInterface
{
	public:
	virtual ~HelpHandlerInterface() { };

	virtual bool HasHelp() = 0;
	virtual void SetHandler(HelpHandlerInterface*, int) = 0;
	virtual void HandleHelp() = 0;
};
}}

#endif
