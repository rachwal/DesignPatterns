// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_CHAIN_BUTTON_H_
#define OPERATIONAL_CHAIN_BUTTON_H_

#include "widget.h"

namespace operational
{
namespace chain
{
class Button : public Widget
{
	public:
	Button();
	explicit Button(std::string name);
	Button(std::string name, int topic);
	Button(std::string name, int topic, HelpHandlerInterface* parent);

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

