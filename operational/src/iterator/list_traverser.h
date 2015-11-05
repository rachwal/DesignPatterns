// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_ITERATOR_LIST_TRAVERSER_H_
#define OPERATIONAL_ITERATOR_LIST_TRAVERSER_H_

#include "list.h"
#include "list_iterator.h"

namespace operational
{
namespace iterator
{
template<class Item>
class ListTraverser
{
	public:
	explicit ListTraverser(List<Item>* list);
	virtual ~ListTraverser();

	virtual bool Traverse();

	protected:
	virtual bool ProcessItem(const Item&) = 0;

	private:
	ListIterator<Item> iterator_;
};

template<class Item>
ListTraverser<Item>::ListTraverser(List<Item>* list) : iterator_(list) { }

template<class Item>
ListTraverser<Item>::~ListTraverser() { }

template<class Item>
bool ListTraverser<Item>::Traverse()
{
	auto result = false;

	for (iterator_.First(); !iterator_.IsDone(); iterator_.Next())
	{
		result = ProcessItem(iterator_.CurrentItem());
		if (result == false)
		{
			break;
		}
	}
	return result;
}
}
}

#endif

