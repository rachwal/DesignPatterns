// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_CHAIN_WIDGET_H_
#define OPERATIONAL_CHAIN_WIDGET_H_

#include "help_handler_interface.h"

#include <string>

namespace operational
{
namespace chain
{
class Widget : public HelpHandlerInterface
{
	public:
	virtual bool HasHelp() override;
	virtual void SetHandler(HelpHandlerInterface*, int) override;

	virtual void HandleHelp() override;

	virtual int topic() const;
	virtual std::string name() const;
	virtual std::string help_message() const;

	protected:
	Widget();
	explicit Widget(std::string name);
	Widget(std::string name, int topic);
	Widget(std::string name, int topic, HelpHandlerInterface* parent);

	private:
	int topic_;
	std::string name_;
	std::string help_message_;
	HelpHandlerInterface* parent_;
};
}}

#endif
