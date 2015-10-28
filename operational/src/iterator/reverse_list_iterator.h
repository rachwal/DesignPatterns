// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_ITERATOR_REVERSE_LIST_ITERATOR_H_
#define OPERATIONAL_ITERATOR_REVERSE_LIST_ITERATOR_H_

#include "iterator_interface.h"
#include "list.h"

namespace operational
{
	template <class Item>
	class ReverseListIterator : public IteratorInterface<Item>
	{
	public:
		explicit ReverseListIterator(const List<Item>* list);
		virtual ~ReverseListIterator() override;

		virtual void First() override;
		virtual void Next() override;
		virtual bool IsDone() const override;
		virtual Item CurrentItem() const override;
	};

	template <class Item>
	ReverseListIterator<Item>::ReverseListIterator(const List<Item>* list)
	{
	}

	template <class Item>
	ReverseListIterator<Item>::~ReverseListIterator()
	{
	}

	template <class Item>
	void ReverseListIterator<Item>::First()
	{
	}

	template <class Item>
	void ReverseListIterator<Item>::Next()
	{
	}

	template <class Item>
	bool ReverseListIterator<Item>::IsDone() const
	{
		return false;
	}

	template <class Item>
	Item ReverseListIterator<Item>::CurrentItem() const
	{
		return{};
	}
}

#endif
