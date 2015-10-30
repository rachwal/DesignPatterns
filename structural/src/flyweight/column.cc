// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "column.h"

namespace structural
{
namespace flyweight
{
void Column::SetFont(Font* font, GlyphContext& context)
{
	context.SetFont(font);
}

Font *Column::GetFont(GlyphContext& context)
{
	return context.GetFont();
}

Column::~Column() { }

void Column::First(GlyphContext& context)
{
	context.First();
}

void Column::Next(GlyphContext& context)
{
	context.Next();
}

bool Column::IsDone(GlyphContext& context)
{
	return context.IsDone();
}

GlyphInterface *Column::Current(GlyphContext&)
{
	return nullptr;
}

void Column::Insert(GlyphInterface*, GlyphContext&) { }

void Column::Remove(GlyphContext&) { }

void Column::Draw(Window*, GlyphContext&) { }
}}
