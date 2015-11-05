// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_CHAIN_DIALOG_H_
#define OPERATIONAL_CHAIN_DIALOG_H_

#include "widget.h"

namespace operational
{
namespace chain
{
class Dialog : public Widget
{
	public:
	Dialog();
	explicit Dialog(std::string name);
	Dialog(std::string name, int topic);
	Dialog(std::string name, int topic, HelpHandlerInterface* parent);

	virtual bool HasHelp() override;
	virtual void HandleHelp() override;

	virtual std::string help_message() const override;

	private:
	int topic_;
	std::string name_;
	std::string help_message_;
};
}
}

#endif

