// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "btree.h"

namespace structural
{
namespace flyweight
{
BTree::BTree(long size) : size_(size)
{
	leafs_ = new operational::iterator::List<Font*>();
	nodes_ = new int[size_];

	for (auto i = 0; i < size_; i++)
	{
		nodes_[i] = -1;
	}
}

BTree::BTree() : BTree(1000) { }

void BTree::Set(Font* font, const int& index, const int& span) const
{
	auto font_index = -1;

	for (auto i = 0; i < leafs_->Count(); i++)
	{
		if (&leafs_->Get(i) == &font)
		{
			font_index = i;
		}
	}

	if (font_index == -1)
	{
		leafs_->Append(font);
		font_index = leafs_->Count() - 1;
	}

	for (auto j = index; j < index + span; j++)
	{
		nodes_[j] = font_index;
	}
}

Font *BTree::Get(int index) const
{
	if (index > size_)
	{
		return nullptr;
	}

	auto font_index = nodes_[index];
	if (font_index == -1)
	{
		return nullptr;
	}

	return leafs_->Get(font_index);
}
}
}

