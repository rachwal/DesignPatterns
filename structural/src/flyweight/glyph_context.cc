// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "glyph_context.h"

namespace structural
{
namespace flyweight
{
GlyphContext::GlyphContext() : index_(1)
{
	fonts_ = new BTree();
}

GlyphContext::~GlyphContext()
{
	delete fonts_;
}

void GlyphContext::First()
{
	index_ = 1;
}

void GlyphContext::Next(int step)
{
	index_ += step;
}

void GlyphContext::Next()
{
	Next(1);
}

bool GlyphContext::IsDone()
{
	if (GetFont())
	{
		return true;
	}
	return false;
}

void GlyphContext::Insert(int quantity)
{
	auto current_font = fonts_->Get(index_);
	fonts_->Set(current_font, index_, quantity);
}

void GlyphContext::Insert()
{
	Insert(1);
}

Font *GlyphContext::GetFont()
{
	return fonts_->Get(index_);
}

void GlyphContext::SetFont(Font* font)
{
	SetFont(font, 1);
}

void GlyphContext::SetFont(Font* font, int span)
{
	fonts_->Set(font, index_, span);
}
}
}

