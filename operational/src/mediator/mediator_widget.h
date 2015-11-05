// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_MEDIATOR_MEDIATOR_WIDGET_H_
#define OPERATIONAL_MEDIATOR_MEDIATOR_WIDGET_H_

#include "mediator_widget_interface.h"
#include "dialog_director_interface.h"

namespace operational
{
namespace madiator
{
class MediatorWidget : public MediatorWidgetInterface
{
	public:
	explicit MediatorWidget(DialogDirectorInterface* director);

	virtual void Changed() override;
	virtual void HandleMouse(MouseEvent& event) override;

	private:
	DialogDirectorInterface* director_;
};
}
}

#endif

