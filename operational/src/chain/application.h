// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_CHAIN_APPLICATION_H_
#define OPERATIONAL_CHAIN_APPLICATION_H_

#include "help_handler_interface.h"

#include <string>

namespace operational
{
namespace chain
{
class Application : public HelpHandlerInterface
{
	public:
	Application();
	explicit Application(std::string name);
	Application(std::string name, int topic);
	Application(std::string name, int topic, HelpHandlerInterface* parent_);

	virtual bool HasHelp() override;
	virtual void SetHandler(HelpHandlerInterface*, int) override;

	virtual void HandleHelp() override;

	int topic() const;
	std::string name() const;
	std::string help_message() const;

	private:
	int topic_;
	std::string name_;
	std::string help_message_;
	HelpHandlerInterface* parent_;
};
}}

#endif
