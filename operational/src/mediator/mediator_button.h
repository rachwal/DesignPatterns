// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_MEDIATOR_MEDIATOR_BUTTON_H_
#define OPERATIONAL_MEDIATOR_MEDIATOR_BUTTON_H_

#include "mediator_widget.h"

#include <string>

namespace operational
{
namespace madiator
{
class MediatorButton : public MediatorWidget
{
	public:
	explicit MediatorButton(DialogDirectorInterface* director);

	virtual void text(const std::string& text);
	virtual const std::string &text(const std::string& text) const;

	virtual void HandleMouse(MouseEvent& event) override;

	private:
	std::string text_;
};
}}

#endif
