// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_MEDIATOR_LIST_BOX_H_
#define OPERATIONAL_MEDIATOR_LIST_BOX_H_

#include "mediator_widget_interface.h"
#include "dialog_director_interface.h"

#include <string>

#include "../iterator/list.h"


namespace operational
{
namespace madiator
{
class ListBox : public MediatorWidgetInterface
{
	public:
	explicit ListBox(DialogDirectorInterface* director);

	virtual const std::string &GetSelection();
	virtual void SetList(iterator::List<std::string>* items);
	virtual void HandleMouse(MouseEvent& event) override;
	virtual void Changed() override;

	private:
	DialogDirectorInterface* director_;
	iterator::List<std::string>* items_;
};
}}

#endif
