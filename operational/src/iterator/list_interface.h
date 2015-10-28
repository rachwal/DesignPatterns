// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_ITERATOR_LIST_INTERFACE_H_
#define OPERATIONAL_ITERATOR_LIST_INTERFACE_H_

namespace operational
{
	template <class Item>
	class ListInterface
	{
	public:
		virtual ~ListInterface()
		{
		}

		virtual long Count() const = 0;

		virtual Item& Get(long index) const = 0;
		virtual Item& First() const = 0;
		virtual Item& Last() const = 0;

		virtual bool Includes(const Item& anItem) const = 0;

		virtual void Append(const Item& anItem) = 0;
		virtual void Prepend(const Item& anItem) = 0;

		virtual void Remove(const Item& anItem) = 0;
		virtual void RemoveAt(long index) = 0;
		virtual void RemoveLast() = 0;
		virtual void RemoveFirst() = 0;
		virtual void RemoveAll() = 0;

		virtual Item& Top() const = 0;

		virtual void Push(const Item& anItem) = 0;

		virtual Item& Pop() = 0;
	};
}

#endif
