// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_ITERATOR_ITERATOR_PTR_H_
#define OPERATIONAL_ITERATOR_ITERATOR_PTR_H_

#include "iterator_interface.h"

namespace operational
{
	template <class Item>
	class IteratorPtr
	{
	public:
		explicit IteratorPtr(IteratorInterface<Item>* i);
		~IteratorPtr();

		IteratorInterface<Item>* operator->();
		IteratorInterface<Item>& operator*();

	private:
		IteratorPtr(const IteratorPtr&);
		IteratorPtr& operator=(const IteratorPtr&);

		IteratorInterface<Item>* i_;
	};

	template <class Item>
	IteratorPtr<Item>::IteratorPtr(IteratorInterface<Item>* i) : i_(i)
	{
	}

	template <class Item>
	IteratorPtr<Item>::~IteratorPtr()
	{
		delete i_;
	}

	template <class Item>
	IteratorInterface<Item>* IteratorPtr<Item>::operator->()
	{
		return i_;
	}

	template <class Item>
	IteratorInterface<Item>& IteratorPtr<Item>::operator*()
	{
		return *i_;
	}

	template <class Item>
	IteratorPtr<Item>::IteratorPtr(const IteratorPtr&)
	{
	}

	template <class Item>
	IteratorPtr<Item>& IteratorPtr<Item>::operator=(const IteratorPtr&)
	{
		return{};
	}
}

#endif
