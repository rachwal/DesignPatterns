// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FLYWEIGHT_GLYPH_CONTEXT_H_
#define STRUCTURAL_FLYWEIGHT_GLYPH_CONTEXT_H_

#include "btree.h"

namespace structural
{
namespace flyweight
{
class GlyphContext
{
	public:
	GlyphContext();
	virtual ~GlyphContext();

	virtual void First();

	virtual void Next(int step);
	virtual void Next();

	virtual bool IsDone();

	virtual void Insert(int quantity);
	virtual void Insert();

	virtual Font *GetFont();

	virtual void SetFont(Font*);
	virtual void SetFont(Font*, int span);

	private:
	int index_;
	BTree* fonts_;
};
}
}

#endif

