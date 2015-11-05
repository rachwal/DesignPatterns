// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_MEDIATOR_DIALOG_DIRECTOR_INTERFACE_H_
#define OPERATIONAL_MEDIATOR_DIALOG_DIRECTOR_INTERFACE_H_

#include "mediator_widget_interface.h"

namespace operational
{
namespace madiator
{
class DialogDirectorInterface
{
	public:
	virtual ~DialogDirectorInterface() {};

	virtual void ShowDialog() = 0;
	virtual void WidgetChanged(MediatorWidgetInterface*) = 0;
};
}
}

#endif

