// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_MEDIATOR_ENTRY_FIELD_H_
#define OPERATIONAL_MEDIATOR_ENTRY_FIELD_H_

#include "mediator_widget.h"

#include <string>

namespace operational
{
namespace madiator
{
class EntryField : public MediatorWidget
{
	public:
	explicit EntryField(DialogDirectorInterface* director);

	virtual void HandleMouse(MouseEvent& event) override;

	virtual void text(const std::string& text);
	virtual const std::string &text() const;

	private:
	std::string text_;
};
}}
#endif
