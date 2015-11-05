// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_ITERATOR_LIST_ITERATOR_H_
#define OPERATIONAL_ITERATOR_LIST_ITERATOR_H_

#include "iterator_interface.h"
#include "list_interface.h"

namespace operational
{
namespace iterator
{
template<class Item>
class ListIterator : public IteratorInterface<Item>
{
	public:
	explicit ListIterator(const ListInterface<Item>* list);
	virtual ~ListIterator() override;

	virtual void First() override;
	virtual void Next() override;
	virtual bool IsDone() const override;
	virtual Item CurrentItem() const override;

	private:
	const ListInterface<Item>* list_;
	long current_;
};

template<class Item>
ListIterator<Item>::ListIterator(const ListInterface<Item>* list) : list_(list), current_(0) { }

template<class Item>
ListIterator<Item>::~ListIterator() { }

template<class Item>
void ListIterator<Item>::First()
{
	current_ = 0;
}

template<class Item>
void ListIterator<Item>::Next()
{
	current_++;
}

template<class Item>
bool ListIterator<Item>::IsDone() const
{
	return current_ >= list_->Count();
}

template<class Item>
Item ListIterator<Item>::CurrentItem() const
{
	if (IsDone())
	{
		return nullptr;
	}
	return list_->Get(current_);
}
}
}

#endif

