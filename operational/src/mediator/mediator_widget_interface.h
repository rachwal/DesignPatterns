// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_MEDIATOR_MEDIATOR_WIDGET_INTERFACE_H_
#define OPERATIONAL_MEDIATOR_MEDIATOR_WIDGET_INTERFACE_H_

#include "mouse_event.h"

namespace operational
{
namespace madiator
{
class MediatorWidgetInterface
{
	public:
	virtual ~MediatorWidgetInterface() { }

	virtual void Changed() = 0;
	virtual void HandleMouse(MouseEvent& event) = 0;
};
}
}

#endif

