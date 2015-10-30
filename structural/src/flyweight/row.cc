// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "row.h"

namespace structural
{
namespace flyweight
{
void Row::SetFont(Font* font, GlyphContext& context)
{
	context.SetFont(font);
}

Font *Row::GetFont(GlyphContext& context)
{
	return context.GetFont();
}

Row::~Row() { }

void Row::First(GlyphContext& context)
{
	context.First();
}

void Row::Next(GlyphContext& context)
{
	context.Next();
}

bool Row::IsDone(GlyphContext& context)
{
	return context.IsDone();
}

GlyphInterface *Row::Current(GlyphContext&)
{
	return nullptr;
}

void Row::Insert(GlyphInterface*, GlyphContext&) { }

void Row::Remove(GlyphContext&) { }

void Row::Draw(Window*, GlyphContext&) { }
}}
