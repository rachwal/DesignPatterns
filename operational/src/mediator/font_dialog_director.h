// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_MEDIATOR_FONT_DIALOG_DIRECTOR_H_
#define OPERATIONAL_MEDIATOR_FONT_DIALOG_DIRECTOR_H_

#include "dialog_director_interface.h"
#include "list_box.h"
#include "entry_field.h"
#include "mediator_button.h"

namespace operational
{
namespace madiator
{
class FontDialogDirector : public DialogDirectorInterface
{
	public:
	FontDialogDirector();

	virtual void Initialize(MediatorButton* ok_button, MediatorButton* cancel_button, ListBox* font_list, EntryField* font_name);
	virtual void ShowDialog() override;
	virtual void WidgetChanged(MediatorWidgetInterface* widget) override;

	private:
	MediatorButton* ok_button_;
	MediatorButton* cancel_button_;
	ListBox* font_list_;
	EntryField* font_name_;
};
}
}

#endif

