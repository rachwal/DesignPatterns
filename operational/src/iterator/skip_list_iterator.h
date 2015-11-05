// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_ITERATOR_SKIP_LIST_ITERATOR_H_
#define OPERATIONAL_ITERATOR_SKIP_LIST_ITERATOR_H_

#include "list.h"
#include "list_iterator.h"

namespace operational
{
namespace iterator
{
template<class Item>
class SkipListIterator : public ListIterator<Item>
{
	public:
	explicit SkipListIterator(const List<Item>* list);
	~SkipListIterator() override;

	void First() override;
	void Next() override;
	bool IsDone() const override;
	Item CurrentItem() const override;
};

template<class Item>
SkipListIterator<Item>::~SkipListIterator() { }

template<class Item>
SkipListIterator<Item>::SkipListIterator(const List<Item>* list): ListIterator<Item>(list) { }

template<class Item>
void SkipListIterator<Item>::First() { }

template<class Item>
void SkipListIterator<Item>::Next() { }

template<class Item>
bool SkipListIterator<Item>::IsDone() const
{
	return false;
}

template<class Item>
Item SkipListIterator<Item>::CurrentItem() const
{
	return {};
}
}
}

#endif

