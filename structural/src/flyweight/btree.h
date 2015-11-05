// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FLYWEIGHT_BTREE_H_
#define STRUCTURAL_FLYWEIGHT_BTREE_H_

#include "font.h"

#include "../../../operational/src/iterator/list.h"

namespace structural
{
namespace flyweight
{
class BTree
{
	public:
	BTree();
	explicit BTree(long size);

	void Set(Font* font, const int& index, const int& span) const;
	Font *Get(int index) const;

	private:
	long size_;
	int* nodes_;
	operational::iterator::List<Font*>* leafs_;
};
}
}

#endif

