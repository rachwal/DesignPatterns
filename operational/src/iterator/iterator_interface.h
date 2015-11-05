// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_ITERATOR_ITERATOR_INTERFACE_H_
#define OPERATIONAL_ITERATOR_ITERATOR_INTERFACE_H_

namespace operational
{
namespace iterator
{
template<class Item>
class IteratorInterface
{
	public:
	virtual ~IteratorInterface() { };

	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual Item CurrentItem() const = 0;
};
}
}

#endif

