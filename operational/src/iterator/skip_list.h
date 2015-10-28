// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_ITERATOR_SKIP_LIST_H_
#define OPERATIONAL_ITERATOR_SKIP_LIST_H_

#include "list.h"

namespace operational
{
	template <class Item>
	class SkipList : public List<Item>
	{
	public:
		explicit SkipList(long size);
		explicit SkipList(List<Item>& list);
		~SkipList() override;

		virtual IteratorInterface<Item>* CreateIterator() const override;
	};

	template <class Item>
	SkipList<Item>::SkipList(long size) : List<Item>(size)
	{
	}

	template <class Item>
	SkipList<Item>::SkipList(List<Item>& list) : List<Item>(list)
	{
	}

	template <class Item>
	SkipList<Item>::~SkipList()
	{
	}

	template <class Item>
	IteratorInterface<Item>* SkipList<Item>::CreateIterator() const
	{
		return nullptr;
	}
}

#endif
