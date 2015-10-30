// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "mediator_widget.h"

namespace operational
{
namespace madiator
{
MediatorWidget::MediatorWidget(DialogDirectorInterface* director) :director_(director) { }

void MediatorWidget::HandleMouse(MouseEvent& event)
{
	Changed();
}

void MediatorWidget::Changed()
{
	director_->WidgetChanged(this);
}
}}
