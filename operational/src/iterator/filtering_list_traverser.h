// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_ITERATOR_FILTERING_LIST_TRAVERSER_H_
#define OPERATIONAL_ITERATOR_FILTERING_LIST_TRAVERSER_H_

#include "list.h"
#include "list_iterator.h"
#include "list_traverser.h"

namespace operational
{
namespace iterator
{
template<class Item>
class FilteringListTraverser : public ListTraverser<Item>
{
	public:
	explicit FilteringListTraverser(List<Item>* aList);
	virtual ~FilteringListTraverser() override;

	bool Traverse() override;

	protected:
	virtual bool ProcessItem(const Item&) override;
	virtual bool TestItem(const Item&);

	private:
	ListIterator<Item> iterator_;
};

template<class Item>
FilteringListTraverser<Item>::FilteringListTraverser(List<Item>* list) { }

template<class Item>
FilteringListTraverser<Item>::~FilteringListTraverser() { }

template<class Item>
bool FilteringListTraverser<Item>::Traverse()
{
	auto result = false;

	for (iterator_.First(); !iterator_.IsDone(); iterator_.Next())
	{
		if (TestItem(iterator_.CurrentItem()))
		{
			result = ProcessItem(iterator_.CurrentItem());
			if (result == false)
			{
				break;
			}
		}
	}
	return result;
}

template<class Item>
bool FilteringListTraverser<Item>::ProcessItem(const Item&)
{
	return false;
}

template<class Item>
bool FilteringListTraverser<Item>::TestItem(const Item&)
{
	return false;
}
}}

#endif
