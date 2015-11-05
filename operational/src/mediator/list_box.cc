// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "list_box.h"

namespace operational
{
namespace madiator
{
ListBox::ListBox(DialogDirectorInterface* director) : director_(director), items_(nullptr) {}

const std::string &ListBox::GetSelection()
{
	return items_->First();
}

void ListBox::SetList(iterator::List<std::string>* items)
{
	items_ = items;
}

void ListBox::HandleMouse(MouseEvent& event)
{
	Changed();
}

void ListBox::Changed()
{
	director_->WidgetChanged(this);
}
}
}

