// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_ITERATOR_LIST_H_
#define OPERATIONAL_ITERATOR_LIST_H_

#include "list_iterator.h"
#include "list_interface.h"

namespace operational
{
namespace iterator
{
template<class Item>
class List : public ListInterface<Item>
{
	public:
	List();
	explicit List(long size);
	List(List& list);
	virtual ~List();

	List &operator=(const List& list);

	virtual ListIterator<Item> *CreateIterator() const;

	long Count() const override;

	Item &Get(long index) const override;
	Item &First() const override;
	Item &Last() const override;

	bool Includes(const Item& anItem) const override;

	void Append(const Item& anItem) override;
	void Prepend(const Item& anItem) override;

	void Remove(const Item& anItem) override;
	void RemoveAt(long index) override;
	void RemoveLast() override;
	void RemoveFirst() override;
	void RemoveAll() override;

	Item &Top() const override;

	void Push(const Item& anItem) override;

	Item &Pop() override;

	private:
	long size_;
	int count_;
	Item* items_;
};

template<class Item>
List<Item>::List() : List(100) { }

template<class Item>
List<Item>::List(long size) : size_(size), count_(0)
{
	items_ = new Item[size_];
}

template<class Item>
List<Item>::List(List& list) : size_(list.size_), count_(list.count_), items_(list.items_) { }

template<class Item>
List<Item>::~List()
{
	delete items_;
}

template<class Item>
List<Item> &List<Item>::operator=(const List& list)
{
	size_ = list.size_;
	count_ = list.count_;
	items_ = list.items_;
	return this;
}

template<class Item>
ListIterator<Item> *List<Item>::CreateIterator() const
{
	return new ListIterator<Item>(this);
}

template<class Item>
long List<Item>::Count() const
{
	return count_;
}

template<class Item>
Item &List<Item>::Get(long index) const
{
	if (count_ <= size_)
		return items_[index];
	throw "RangeError";
}

template<class Item>
Item &List<Item>::First() const
{
	return Get(0);
}

template<class Item>
Item &List<Item>::Last() const
{
	return Get(Count() - 1);
}

template<class Item>
bool List<Item>::Includes(const Item& item) const
{
	for (long i = 0; i < Count(); i++)
	{
		if (items_[i] == item)
		{
			return true;
		}
	}
	return false;
}

template<class Item>
void List<Item>::Append(const Item& item)
{
	if (count_ <= size_)
	{
		items_[count_] = item;
		count_++;
	}
}

template<class Item>
void List<Item>::Prepend(const Item& item)
{
	if (count_ <= size_)
	{
		for (long i = count_ - 1; i >= 0; i--)
			items_[i + 1] = items_[i];
		items_[0] = item;
		count_++;
	}
}

template<class Item>
void List<Item>::Remove(const Item& item)
{
	for (long i = 0; i < Count(); i++)
	{
		if (items_[i] == item)
		{
			RemoveAt(i);
		}
	}
}

template<class Item>
void List<Item>::RemoveAt(long index)
{
	if (index < 0 || index >= Count())
		throw "RangeException";

	for (auto i = index; i < Count() - 1; i++)
		items_[i] = items_[i + 1];
	count_--;
}

template<class Item>
void List<Item>::RemoveLast()
{
	RemoveAt(Count() - 1);
}

template<class Item>
void List<Item>::RemoveFirst()
{
	RemoveAt(0);
}

template<class Item>
void List<Item>::RemoveAll()
{
	count_ = 0;
}

template<class Item>
Item &List<Item>::Top() const
{
	return Last();
}

template<class Item>
void List<Item>::Push(const Item& item)
{
	Append(item);
}

template<class Item>
Item &List<Item>::Pop()
{
	Item& top = Last();
	RemoveLast();
	return top;
}
}
}

#endif

